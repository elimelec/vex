/*
** Copyright (C) 1996-2003 Hewlett-Packard Company.
*/

/*
** You can redistribute this file it and/or modify it under the terms 
** of the GNU Library General Public License as published by the Free 
** Software Foundation; either version 2 of the License, or (at your 
** option) any later version.
**
** You should have received a copy of the GNU Library General Public
** License along with the GNU C Library; see the file COPYING.LIB.  If not,
** write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
** Boston, MA 02111-1307, USA.
*/

/* $Id: cs_vex.h,v 1.5 2005/02/24 16:24:01 frb Exp $ */

#ifndef __CS_VEX_INCLUDED_
#define __CS_VEX_INCLUDED_

#define MAX_BUNDLE_SIZE 128

extern unsigned long long sim_bundle_index[MAX_BUNDLE_SIZE];
extern unsigned long long sim_bnt_counter;
extern unsigned long long sim_btc_counter;
extern unsigned long long sim_btu_counter;
extern unsigned long long sim_nop_counter;
extern unsigned long long sim_cycle_counter;
extern unsigned long long sim_stall_counter;
extern unsigned long long sim_dcache_stall_counter;
extern unsigned long long sim_icache_stall_counter;
extern unsigned long long sim_branch_stall;

extern unsigned int sim_calloc(unsigned int size, unsigned int align);
extern unsigned char sim_mem_access8(unsigned int a);
extern unsigned short sim_mem_access16(unsigned int a);
extern unsigned int sim_mem_access32(unsigned int a);
extern void sim_bad_label(int indicator);
extern unsigned int sim_create_stack(unsigned int size, unsigned int stackptr);
extern void sim_check_stack(unsigned int stackvalue, unsigned int framesize);
extern void *sim_sys_setjmp_save(void *env);
extern void *sim_sys_longjmp_restore(void *env);

typedef union { double d; int i[2]; } __f64;

extern __f64 _dcstime();
extern __f64 _dtatime();
extern __f64 _dtatime_d();
extern __f64 _dtatime_i();

extern double __cstime();
extern double __tatime();
extern double __tatime_d();
extern double __tatime_i();
extern double __tCK();

extern unsigned long _icstime(unsigned long scale);
extern unsigned long _itatime(unsigned long scale);
extern unsigned long _itatime_d(unsigned long scale);
extern unsigned long _itatime_i(unsigned long scale);

#define cstime() _dcstime()
#define tatime() _dtatime()

extern void sim_ta_disable();	/* disable simulation */
extern void sim_ta_enable();	/* re-enable simulation */

#if defined(__linux__)
# define _open 		__open
# define _read 		__read
# define _write 	__write
# define _close 	__close
# define _fprintf 	_linux_fprintf
# define _sprintf 	_linux_sprintf
# define _vfprintf 	_linux_vfprintf
# define _vsprintf 	_linux_vsprintf
# define _scanf 	_linux_scanf
# define _fscanf 	_linux_fscanf
# define _sscanf 	_linux_sscanf
# define _vfscanf 	_linux_vfscanf
# define _vsscanf 	_linux_vsscanf
# define _fclose 	_linux_fclose
# define _fflush 	_linux_fflush
# define _fopen 	_linux_fopen
# define _clock 	_linux_clock
# define _strncpy 	_linux_strncpy
# define _strncmp 	_linux_strncmp
# define _memcpy 	_linux_memcpy
# define _memset 	_linux_memset
# define _getenv 	_linux_getenv
# define _strcasecmp  	_linux_strcasecmp
# define _isspace       _linux_isspace
# define _sbrk          _linux_sbrk
# define _writev        _linux_writev
# define _sigaction     _linux_sigaction
#endif

#endif
