#ifndef __CSTIME_H__
#define __CSTIME_H__

/* when compiling for the cs interface, use __f64 and define internal names */
typedef union { double d; int i[2]; } __f64;
extern double __cstime();
extern double __tatime();
extern double __tatime_d();
extern double __tatime_i();
extern double __tCK();
extern __f64 _dcstime(); 
extern __f64 _dtatime(); 
extern __f64 _dtatime_d(); 
extern __f64 _dtatime_i(); 

/* time in secs*scale - with cache effects */
#ifdef __STDC__
extern unsigned long _icstime(unsigned long scale);
/* time in secs*scale - with cache effects */
#else
extern unsigned long _icstime();
#endif


/* time in secs*scale - with cache effects */
#ifdef __STDC__
extern unsigned long _itatime(unsigned long scale);
extern unsigned long _itatime_d(unsigned long scale);
extern unsigned long _itatime_i(unsigned long scale);
#else
extern unsigned long _itatime();
extern unsigned long _itatime_d();
extern unsigned long _itatime_i();
#endif

#define cstime() _dcstime()
#define tatime() _dtatime()

extern void sim_ta_disable(); /* disable simulation */
extern void sim_ta_enable();  /* re-enable simulation */

#endif

