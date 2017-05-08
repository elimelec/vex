/*
** static char sccs_id[] = "$Id: w_cabs.c,v 1.1.1.1 2001/11/21 20:34:46 frb Exp $ ";
*/

/*
 * cabs() wrapper for hypot().
 * 
 * Written by J.T. Conklin, <jtc@wimsey.com>
 * Placed into the Public Domain, 1994.
 */

#include "fdlibm.h"

struct complex {
	double x;
	double y;
};

double
cabs(z)
	struct complex z;
{
	return hypot(z.x, z.y);
}
