/* 
** static char sccs_id[] = "$Id: thread.c,v 1.1.1.1 2001/11/21 20:34:39 frb Exp $ ";
*/
/* Dummy version of thread locks */

#ifdef THREAD_SAFE

void pthread_lock_global_np() { }
void pthread_unlock_global_np() { }

#endif
