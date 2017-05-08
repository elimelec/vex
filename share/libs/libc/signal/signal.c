/* 
** static char sccs_id[] = "$Id: signal.c,v 1.1.1.1 2001/11/21 20:34:39 frb Exp $ ";
*/
/*
FUNCTION
<<signal>>---specify handler subroutine for a signal

INDEX
	signal
INDEX
	_signal_r
INDEX
	raise
INDEX
	_raise_r

ANSI_SYNOPSIS
	#include <signal.h>
	void ( * signal(int <[sig]>, void(*<[func]>)(int)) )(int);

	void ( * _signal_r(void *<[reent]>, 
                           int <[sig]>, void(*<[func]>)(int)) )(int);

	int raise (int <[sig]>);

	int _raise_r (void *<[reent]>, int <[sig]>);

TRAD_SYNOPSIS
	#include <signal.h>
	char ( * signal(<[sig]>, <[func]>) )()
	int <[sig]>;
	char ( * <[func]> )();

	char ( * _signal_r(<[reent]>, <[sig]>, <[func]>) )()
	char *<[reent]>;
	int <[sig]>;
	char ( * <[func]> )();

	int raise (<[sig]>)()
	int <[sig]>;

	int _raise_r (<[reent]>, <[sig]>)()
	char *<[reent]>;
	int <[sig]>;

DESCRIPTION
<<signal, raise>> provide a simple signal/raise implementation for embedded
targets.

<<signal>> allows you to request changed treatment for a particular
signal <[sig]>.  You can use one of the predefined macros <<SIG_DFL>>
(select system default handling) or <<SIG_IGN>> (ignore this signal)
as the value of <[func]>; otherwise, <[func]> is a function pointer
that identifies a subroutine in your program as the handler for this signal.

Some of the execution environment for signal handlers is
unpredictable; notably, the only library function required to work
correctly from within a signal handler is @code{signal} itself, and
only when used to redefine the handler for the current signal value.

Static storage is likewise unreliable for signal handlers, with one
exception: if you declare a static storage location as `<<volatile
sig_atomic_t>>', then you may use that location in a signal handler to
store signal values.

If your signal handler terminates using <<return>> (or implicit
return), your program's execution continues at the point
where it was when the signal was raised (whether by your program
itself, or by an external event).  Signal handlers can also
use functions such as <<exit>> and <<abort>> to avoid returning.

<<raise>> sends the signal sig to the executing program.  It returns zero if
successful, non-zero if unsuccessful.

The alternate functions <<_signal_r, _raise_r>> are the reentrant versions.
The extra argument <[reent]> is a pointer to a reentrancy structure.


@c FIXME: do we have setjmp.h and assoc fns?

RETURNS
If your request for a signal handler cannot be honored, the result is
<<SIG_ERR>>; a specific error number is also recorded in <<errno>>.

Otherwise, the result is the previous handler (a function pointer or
one of the predefined macros).

PORTABILITY
ANSI C requires <<raise>>, <<signal>>.

No supporting OS subroutines are required to link with <<signal>>, but
it will not have any useful effects, except for software generated signals,
without an operating system that can actually raise exceptions.
*/

/*
 * signal.c
 * Original Author:	G. Haley
 *
 * signal associates the function pointed to by func with the signal sig. When
 * a signal occurs, the value of func determines the action taken as follows:
 * if func is SIG_DFL, the default handling for that signal will occur; if func
 * is SIG_IGN, the signal will be ignored; otherwise, the default handling for
 * the signal is restored (SIG_DFL), and the function func is called with sig
 * as its argument. Returns the value of func for the previous call to signal
 * for the signal sig, or SIG_ERR if the request fails.
 */

/* _init_signal initialises the signal handlers for each signal. This function
   is called by crt0 at program startup.  */

#ifdef SIGNAL_PROVIDED

int _dummy_simulated_signal;

#else

#include <errno.h>
#include <signal.h>
#include <stddef.h>
#include <stdlib.h>
#include <reent.h>
#include <_syslist.h>

#if 0
int
_DEFUN (_init_signal_r, (ptr),
	struct _reent *ptr)
{
  int i;

  if (ptr->_sig_act == NULL)
    {
      ptr->_sig_act = (struct sigaction  *)_malloc_r (ptr, sizeof (struct sigaction) * NSIG);
      if (ptr->_sig_act == NULL)
	return -1;

      for (i = 0; i < NSIG; i++)
	{
	  ptr->_sig_act[i].sa_handler = SIG_DFL;
	  sigemptyset(&ptr->_sig_act[i].sa_mask);
	  ptr->_sig_act[i].sa_flags   =  0;
	}
    }

  return 0;
}
#endif

_sig_func_ptr
_DEFUN (_signal_r, (ptr, sig, func),
	struct _reent *ptr _AND
	int sig _AND
	_sig_func_ptr func)
{
  _sig_func_ptr old_func, *temp;

  if (sig < 0 || sig >= NSIG)
    {
      ptr->_errno = EINVAL;
      return SIG_ERR;
    }

#if 0

  if (ptr->_sig_act == NULL && _init_signal_r (ptr) != 0)
    return SIG_ERR;

#endif
  
  old_func = ptr->_sig_act[sig - 1].sa_handler;
  ptr->_sig_act[sig - 1].sa_handler = func;
  ptr->_sig_act[sig - 1].sa_flags   = SA_NOMASK | SA_ONESHOT;

  return old_func;
}

int 
_raise_r (ptr, sig)
     struct _reent *ptr;
     int sig;
{
  _sig_func_ptr func;
  int result = 0;

  if (sig < 0 || sig >= NSIG)
    {
      ptr->_errno = EINVAL;
      return -1;
    }

#if 0
  if (ptr->_sig_act == NULL && _init_signal_r (ptr) != 0)
    return -1;
#endif

  func = ptr->_sig_act[sig-1].sa_handler;

  if (func == SIG_DFL) {
    result = _kill_r (ptr, _getpid_r (ptr), sig);
  }
  else if (func == SIG_IGN) {
    ; /* do nothing */
  }
  else if (func == SIG_ERR) {
    ptr->_errno = EINVAL;
    result = 1;
  }
  else {
    ptr->_sig_act[sig-1].sa_handler = SIG_DFL;
    ptr->_sig_act[sig-1].sa_flags   = 0;
    func (sig);
  }

  return result;
}

#ifndef _REENT_ONLY

int 
raise (sig)
     int sig;
{
  return _raise_r (_REENT, sig);
}

_sig_func_ptr
_DEFUN (signal, (sig, func),
	int sig _AND
	_sig_func_ptr func)
{
  return _signal_r (_REENT, sig, func);
}

#if 0
int 
_init_signal ()
{
  return _init_signal_r (_REENT);
}
#endif

#endif

#endif /* !SIGNAL_PROVIDED */
