/* Copyright (C) 1991, 1992, 1996, 1997 Free Software Foundation, Inc.
 * This file is part of the GNU C Library.
 * 
 * The GNU C Library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 * 
 * The GNU C Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 * 
 * You should have received a copy of the GNU Library General Public
 * License along with the GNU C Library; see the file COPYING.LIB.  If not,
 * write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.  
 */

/**
*** static char sccs_id[] = "$Id: uio.h,v 1.1.1.1 2001/11/21 20:34:39 frb Exp $ ";
**/

#ifndef _SYS_UIO_H
#define _SYS_UIO_H

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

    struct iovec {
	/* Starting address.  */
	_PTR iov_base;
	/* Length in bytes.  */
	size_t iov_len;
    };

/* 
 * Read data from file descriptor FD, and put the result in the
 * buffers described by VECTOR, which is a vector of COUNT `struct iovec's.
 * The buffers are filled in the order specified.
 * Operates just like `read' (see <unistd.h>) except that data are
 * put in VECTOR instead of a contiguous buffer.  
 */
    extern ssize_t _EXFUN(__readv, (int __fd, _CONST struct iovec * __vector,
				    int __count));
/* 
 * Write data pointed by the buffers described by VECTOR, which
 * is a vector of COUNT `struct iovec's, to file descriptor FD.
 * The data is written in the order specified.
 * Operates just like `write' (see <unistd.h>) except that the data
 * are taken from VECTOR instead of a contiguous buffer.  
 */
    extern ssize_t _EXFUN(__writev, (int __fd, _CONST struct iovec * __vector,
				     int __count));
#ifdef __cplusplus
}
#endif

#endif /* _SYS_UIO_H */
