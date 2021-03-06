
/* SCCS-info %W% %E% */

/*--------------------------------------------------------------------*/
/*                                                                    */
/*              VCG : Visualization of Compiler Graphs                */
/*              --------------------------------------                */
/*                                                                    */
/*   file:         tree.c                                             */
/*   version:      1.00.00                                            */
/*   creation:     14.4.1993                                          */
/*   author:       I. Lemke  (...-Version 0.99.99)                    */
/*                 G. Sander (Version 1.00.00-...)                    */  
/*                 Universitaet des Saarlandes, 66041 Saarbruecken    */
/*                 ESPRIT Project #5399 Compare                       */
/*   description:  Layout phase 2/3: Tree Layout                      */
/*   status:       in work                                            */
/*                                                                    */
/*--------------------------------------------------------------------*/


#ifndef lint
static char *id_string="$Id: tree.c,v 1.2 2009/12/17 17:07:30 frb Exp $";
#endif

/*
 *   Copyright (C) 1993--1995 by Georg Sander, Iris Lemke, and
 *                               the Compare Consortium 
 *
 *  This program and documentation is free software; you can redistribute 
 *  it under the terms of the  GNU General Public License as published by
 *  the  Free Software Foundation;  either version 2  of the License,  or
 *  (at your option) any later version.
 *
 *  This  program  is  distributed  in  the hope that it will be useful,
 *  but  WITHOUT ANY WARRANTY;  without  even  the  implied  warranty of
 *  MERCHANTABILITY  or  FITNESS  FOR  A  PARTICULAR  PURPOSE.  See  the
 *  GNU General Public License for more details.
 *
 *  You  should  have  received a copy of the GNU General Public License
 *  along  with  this  program;  if  not,  write  to  the  Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *  The software is available per anonymous ftp at ftp.cs.uni-sb.de.
 *  Contact  sander@cs.uni-sb.de  for additional information.
 */


/* 
 * $Log: tree.c,v $
 * Revision 1.2  2009/12/17 17:07:30  frb
 * Update to patched debian version
 *
 * Revision 1.6  1995/02/08  11:11:14  sander
 * Distribution version 1.3.
 *
 * Revision 1.5  1994/12/23  18:12:45  sander
 * Manhatten layout added.
 * Option interface cleared.
 * infobox behaviour improved.
 * First version of fisheye (carthesian).
 * Options Noedge and nonode.
 * Titles in the node title box are now sorted.
 *
 * Revision 1.4  1994/08/09  15:06:36  sander
 * Cosmetic change.
 *
 * Revision 1.3  1994/08/08  16:01:47  sander
 * Attributes xraster, xlraster, yraster added.
 *
 * Revision 1.2  1994/08/05  14:27:31  sander
 * Negative values of G_width, etc. corrected.
 *
 * Revision 1.1  1994/08/05  12:13:25  sander
 * Initial revision
 *
 */

/************************************************************************
 * The situation here is the following:
 * -----------------------------------
 * We are still in the layout phase of the graph. The graph is in 
 * adjacency list representation available, further it is partitioned
 * into layers that represent a proper hierarchy.
 * We want to calculate now the relative position of the nodes inside
 * the layers. We have:
 *
 *    1)  The array layer contains all visible nodes in the TSUCC lists.
 *        They are distributed at the layer[i] lists and connected by the 
 *        TSUCC list to allow to traverse the nodes of one layer[i].
 *        TANZ(layer[i])= 0.
 *        The hierarchy in layer is proper.
 *    2)  Further, all visible nodes are in nodelist, labellist and dummylist.
 *    3)  All pot. visible edges are in the lists edgelist or tmpedgelist.
 *        Visible edges can be detected by the EINVISIBLE flag (==0) in these
 *        lists. Note: invisible edges may also be in edgelist or tmpedgelist.
 *        An edge is visible iff 
 *		   a) it is used in the adjacency lists.
 *	  	or b) it is a direct neigbour edge in NCONNECT(v) for 
 *		      some node v.
 *    4)  maxdepth+1 is the maximal layer !!! NOT maxdepth !!!
 *    5)  NTIEFE(node) is filled for all nodes. 
 *        NCONNECT(node) is filled for nodes that have direct neighbours
 *        in the layout. 
 *    7)  Reverted edges are marked with EART(e)='R'.
 *        Self loops don't anymore exist.
 *
 * The task here is to calculate the (x,y) coordinates of a tree
 * by a specialized layout algorithm.
 * Crossing reduction is not necessary, because the layout algoritm 
 * implies no crossings.
 * After that, the layout must be prepared to enter step4_main, i.e.
 * the TPRED lists must be created, the nodes must be sorted according
 * to their position within the levels, etc.
 *
 * At the end, the situation is this:
 *    1)  The array layer contains all visible nodes. 
 *        They are distributed at the layer[i] lists and connected by two
 *        lists TPRED and TSUCC to allow to traverse the nodes of one 
 *        layer[i] backwards and forwards. 
 *    2)  Note that the nodes reacheable via forward connections are now
 *	  in the TSUCC and TPRED lists, too.
 *	  TANZ(layer[i]) is the number of nodes in layer[i].
 *    3)  The hierarchy in layer is proper.
 *    4)  nodelist, labellist and dummylist are not changed.
 *    5)  All pot. visible edges are in the lists edgelist or tmpedgelist,
 *	  same as before.
 *    6)  maxindeg and maxoutdeg are upper estimations of NINDEG and
 *	  NOUTDEG of nodes.
 *    7)  maxdepth+1 is the maximal layer !!! NOT maxdepth !!!
 *    8)  NTIEFE(node) is filled for all nodes. NINDEG and NOUTDEG are
 *        filled. Forward connections are not counted.
 *        NCONNECT(node) is filled as before.
 *    9)  Reverted edges are marked with EART(e)='R'.
 *        Self loops don't anymore exist.
 *    10) NPOS(v) gives the horizontal position of a node inside the
 *	  layer. Adjacency edges are sorted according to these NPOS
 *	  values. The ordering inside a layer is such that the number
 *	  of cossings is 0.
 *    11) NSUCCL(v) and NSUCCR(v) are the leftest and rightest successor
 *        edge of v, and NPREDL(v) and NPREDR(v) the leftest and rightest
 *        predecessor edge.
 *    12) All nodes have filled NX, NY, NWIDTH and NHEIGHT such that
 *        they do not overlap. NX and NY are absolutely. NWIDTH and
 *        NHEIGHT are stretched or shrinked according to the local
 *        factors at the nodes.
 *
 *
 * This file provides the following functions:
 * ------------------------------------------
 * tree_main		Main routine to produce the tree layout.
 *
 *
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"
#include "alloc.h"
#include "main.h"
#include "options.h"
#include "folding.h"
#include "steps.h"
#include "timing.h"


#ifndef ANSI_C
#ifndef const
#define const
#endif
#endif



/* Prototypes
 * ----------
 */

static int 	is_tree		_PP((void));
static int 	is_shared	_PP((GNODE v));
static void 	calc_degree	_PP((void));
static void 	create_tpred_lists 	_PP((void));
static void 	sort_tsucc_and_tpred 	_PP((void));
static  int 	compare_xpos 	   	_PP((const GNODE *a, const GNODE *b));
static void 	sort_all_adjacencies	_PP((void));

static void	tree_layout		_PP((void));
static int 	find_position		_PP((GNODE v,int l));

static void 	correct_position	_PP((GNODE conn,GNODE v));
static int 	min_x_in_tree		_PP((GNODE v,GNODE conn));
static int 	max_x_in_tree		_PP((GNODE v,int depth));
static void 	correct_xpos		_PP((GNODE v,int diff));


/* Global variables
 * ----------------
 */

static int mymaxoutdeg;		/* Maximal outdegree of nodes */

/* array where we can temporary sort the nodes of one level.
 */

static GNODE  	*sort_array = NULL;

/* Level where we start to spread the tree.
 */

int spread_level = 1;

/* Factor how much we allow to degenerate to the left
 */

double tree_factor = 0.5;
static int tree_factor1;
static int tree_factor2;

/*--------------------------------------------------------------------*/
/*  Tree Layout                                                       */
/*--------------------------------------------------------------------*/

/*   Main entry point of tree layout
 *   -------------------------------
 *   returns TREE_LAYOUT on success, otherwise 0.
 */

#ifdef ANSI_C
int tree_main(void)
#else
int tree_main()
#endif
{
	start_time();
	debugmessage("tree_main","");
	assert((layer));

	if (tree_factor<0) tree_factor = -tree_factor;
	if (tree_factor>1.0) {
		tree_factor2 = (int)(10.0/tree_factor);
		tree_factor1 = 10;
	}
	else {
		tree_factor1 = (int)(tree_factor*10.0);
		tree_factor2 = 10;
	}
	if ((tree_factor1==0)||(tree_factor2==0)) {
		tree_factor = 0.5;
		tree_factor1 = 1;
		tree_factor2 = 2;
	}

	gs_wait_message('T');

	/* Check whether it is a forest of trees */

	if (!is_tree()) {
		stop_time("tree_main");
		return(0);
	}

	gs_wait_message('T');

	calc_degree();

	/* Create the TPRED lists 
	 * This also initializes max_nodes_per_layer.
	 */

	create_tpred_lists();

	/* Calculate width and height of the nodes
	 */

	calc_all_node_sizes();

	/* Allocate the sort_array and the tpred_connections.
	 */

	alloc_levelshift();  /* This allocates tpred_connections. */
	sort_array = (GNODE *)tpred_connection1;

	/* Layout the tree */

	tree_layout();

	/*  Order the nodes within the levels according to their
	 *  X-coordinate. This initializes also NPOS. 
	 */

	sort_tsucc_and_tpred();

	/*  Order the adjacency lists of the nodes and initialize
	 *  NPREDL, NPREDR, NSUCCL, NSUCCR.
	 */

	gs_wait_message('T');
	sort_all_adjacencies();
	calc_all_ports(1);

	nr_crossings = 0;

	stop_time("tree_main");
	return(TREE_LAYOUT);
}




/*--------------------------------------------------------------------*/
/*  Check whether it is a forest of tree's                            */
/*--------------------------------------------------------------------*/

/* Tree check main function
 * ------------------------
 * return 1 if it is a downward tree.
 * As side effect, NINDEG and NOUTDEG are calculated, but only valid,
 * if it is a tree. Dito for maxindeg and maxoutdeg.
 */

#define forward_connection1(c)  ((CEDGE(c))&& (EEND(CEDGE(c))!=v))
#define forward_connection2(c)  ((CEDGE2(c))&&(EEND(CEDGE2(c))!=v))
#define backward_connection1(c) ((CEDGE(c))&& (EEND(CEDGE(c))==v))
#define backward_connection2(c) ((CEDGE2(c))&&(EEND(CEDGE2(c))==v))

#ifdef ANSI_C
static int is_tree(void)
#else
static int is_tree()
#endif
{
	int i;
	int result;
	int fresh;

	GNODE v;
	GNLIST li;
	CONNECT c;

	debugmessage("is_tree","");

	v = nodelist;
	while (v) { NMARK(v) = 1; v = NNEXT(v); }
	v = labellist;
	while (v) { NMARK(v) = 1; v = NNEXT(v); }
	v = dummylist;
	while (v) { NMARK(v) = 1; v = NNEXT(v); }

	/* Check whether a node is shared */

	for (i=0; i<= maxdepth+1; i++) {
		li = TSUCC(layer[i]);
		while (li) {
			v = GNNODE(li);
			fresh = NMARK(v);
			c = NCONNECT(v);
			if (c) {
				if (backward_connection1(c)) fresh = 0;
				if (backward_connection2(c)) fresh = 0;
			}
			result = 0;
			if (fresh) result = is_shared(v);
			if (result) return(0);
			li = GNNEXT(li);
		}
	}

	return(1);
}


/* Traverse a tree by dfs and check whether a node is shared
 * ---------------------------------------------------------
 * returns 1 if a node is shared.
 * As side effect, NINDEG and NOUTDEG are calculated.
 */


#ifdef ANSI_C
static int is_shared(GNODE v)
#else
static int is_shared(v)
GNODE v;
#endif
{
	int i;
	ADJEDGE a;
	CONNECT c;

	debugmessage("is_shared","");

	if (!NMARK(v)) return(1);

	NMARK(v) = 0;

	i = 0;
	a = NPRED(v);
	while (a) { i++; a = ANEXT(a); }
	if (i>1) return(1);

	i = 0;
	a = NSUCC(v);
	while (a) {
		i++;
		if (is_shared(TARGET(a))) return(1);
		a = ANEXT(a);
	}

	c = NCONNECT(v);
	if (c) {
		if (forward_connection1(c)) {
			if (is_shared(EEND(CEDGE(c)))) return(1);
		}
		if (forward_connection2(c)) {
			if (is_shared(EEND(CEDGE2(c)))) return(1);
		}
	}
	return(0);
}


/*--------------------------------------------------------------------*/
/*  Calculate the degree of the nodes                                 */
/*--------------------------------------------------------------------*/

#ifdef ANSI_C
static void calc_degree(void)
#else
static void calc_degree()
#endif
{
	int i, j;
	GNODE v;
	GNLIST li;
	ADJEDGE a;

	debugmessage("calc_degree","");

	/* Check whether a node is shared */

	mymaxoutdeg = 0;
	for (i=0; i<= maxdepth+1; i++) {
		li = TSUCC(layer[i]);
		while (li) {
			v = GNNODE(li);
			j = 0;
			a = NPRED(v);
			while (a) { j++; a = ANEXT(a); }
			NINDEG(v) = j;
			assert((j<=1));
			j = 0;
			a = NSUCC(v);
			while (a) { j++; a = ANEXT(a); }
			NOUTDEG(v) = j;
			if (j>mymaxoutdeg) mymaxoutdeg = j;
			li = GNNEXT(li);
		}
	}
	maxindeg = 1;
	maxoutdeg = mymaxoutdeg;
}


/*--------------------------------------------------------------------*/
/*  Create the TPRED lists of the layers                              */
/*--------------------------------------------------------------------*/

#ifdef ANSI_C
static void create_tpred_lists(void)
#else
static void create_tpred_lists()
#endif
{
	int i, k;
	GNLIST h1, h2;

	debugmessage("create_tpred_lists","");

	max_nodes_per_layer = 0;
	for (i=0; i<=maxdepth+1; i++) {
		h1 = TSUCC(layer[i]);
		TPRED(layer[i]) = NULL;
		k = 0;
		while (h1) {
			k++;
			h2 = tmpnodelist_alloc();
			GNNEXT(h2) = TPRED(layer[i]);
			TPRED(layer[i]) = h2;
			GNNODE(h2) = GNNODE(h1);
			h1 = GNNEXT(h1);
		}
		TANZ(layer[i]) = k;
		if (k>max_nodes_per_layer) max_nodes_per_layer = k;
	}
}


/*--------------------------------------------------------------------*/
/*  Sort the layers according to the X-Postion                        */
/*--------------------------------------------------------------------*/

/* This initializes also NPOS. 
 */

#ifdef ANSI_C
static void sort_tsucc_and_tpred(void)
#else
static void sort_tsucc_and_tpred()
#endif
{
	int i, k, max;
	GNLIST h1;

	debugmessage("sort_tsucc_and_tpred","");

	for (i=0; i<=maxdepth+1; i++) {
		h1 = TSUCC(layer[i]);
		k = 0;
		while (h1) {
			sort_array[k++] = GNNODE(h1);
			h1 = GNNEXT(h1);
		}
		max = k;

#ifdef ANSI_C
		if (k) qsort(sort_array, k, sizeof(GNODE),
			(int (*) (const void *, const void *))compare_xpos); 
#else
		if (k) qsort(sort_array, k, sizeof(GNODE),compare_xpos); 
#endif

		h1 = TSUCC(layer[i]);
		k = 0;
		while (h1) {
			NPOS(sort_array[k]) = k;
			GNNODE(h1) = sort_array[k++];
			h1 = GNNEXT(h1);
		}
		assert((k==max));
		k--;
		h1 = TPRED(layer[i]);
		while (h1) {
			GNNODE(h1) = sort_array[k--];
			h1 = GNNEXT(h1);
		}
		assert((k== -1));
	}
}



/*  Compare function for sorting according NX 
 *  -----------------------------------------
 *  returns 1 if NX(*a) > NX(*b), 0 if equal, -1 otherwise.
 */
 
#ifdef ANSI_C
static int 	compare_xpos(const GNODE *a,const GNODE *b)
#else
static int 	compare_xpos(a,b)
GNODE	*a;
GNODE   *b;
#endif
{ 
	if (NX(*a) > NX(*b)) return(1);
	if (NX(*a) < NX(*b)) return(-1);
	return(0);
}


/*--------------------------------------------------------------------*/
/*  Sort adjacency lists                                              */
/*--------------------------------------------------------------------*/

/* Sort the adjacency lists and init NPREDL, NPREDR, NSUCCL, NSUCCR
 * ----------------------------------------------------------------
 */

#ifdef ANSI_C
static void sort_all_adjacencies(void)
#else
static void sort_all_adjacencies()
#endif
{
	int i;
	GNLIST h1;
	ADJEDGE a;

	debugmessage("sort_all_adjacencies","");

	for (i=0; i<=maxdepth+1; i++) {
		if (i>0) {
			h1 = TSUCC(layer[i-1]);
			while (h1) {
				NTMPADJ(GNNODE(h1)) = NSUCC(GNNODE(h1));
				h1 = GNNEXT(h1);
			}
		}
		if (i<maxdepth+1) {
			h1 = TSUCC(layer[i+1]);
			while (h1) {
				NTMPADJ(GNNODE(h1)) = NPRED(GNNODE(h1));
				h1 = GNNEXT(h1);
			}
		}
		h1 = TSUCC(layer[i]);
		while (h1) {
			a = NPRED(GNNODE(h1));
			while (a) {
				assert((NTMPADJ(SOURCE(a))));
				AKANTE(NTMPADJ(SOURCE(a))) = AKANTE(a);
				NTMPADJ(SOURCE(a)) = ANEXT(NTMPADJ(SOURCE(a)));
				a = ANEXT(a);
			}
			a = NSUCC(GNNODE(h1));
			while (a) {
				assert((NTMPADJ(TARGET(a))));
				AKANTE(NTMPADJ(TARGET(a))) = AKANTE(a);
				NTMPADJ(TARGET(a)) = ANEXT(NTMPADJ(TARGET(a)));
				a = ANEXT(a);
			}
			h1 = GNNEXT(h1);
		}
	}

	for (i=0; i<=maxdepth+1; i++) {
		h1 = TSUCC(layer[i]);
		while (h1) {
			NPREDL(GNNODE(h1)) = NPREDR(GNNODE(h1)) = 0;
			a = NPRED(GNNODE(h1));
			if (a) {
				NPREDL(GNNODE(h1)) = AKANTE(a);
				while (ANEXT(a)) a = ANEXT(a);
				NPREDR(GNNODE(h1)) = AKANTE(a);
			}
			NSUCCL(GNNODE(h1)) = NSUCCR(GNNODE(h1)) = 0;
			a = NSUCC(GNNODE(h1));
			if (a) {
				NSUCCL(GNNODE(h1)) = AKANTE(a);
				while (ANEXT(a)) a = ANEXT(a);
				NSUCCR(GNNODE(h1)) = AKANTE(a);
			}
			h1 = GNNEXT(h1);
		}
	}
}


/*--------------------------------------------------------------------*/
/*  The real tree layout algorithm                                    */
/*--------------------------------------------------------------------*/

static int horder_warn; /* 1 if the horder-warning was already printed */

#define xralign(a)  ((((a)+G_xraster-1)/G_xraster)*G_xraster)
#define xlalign(a)  ((((a)            )/G_xraster)*G_xraster)
#define dxralign(a) ((((a)+G_dxraster-1)/G_dxraster)*G_dxraster)
#define yralign(a)  ((((a)+G_yraster-1)/G_yraster)*G_yraster)


#ifdef ANSI_C
static void	tree_layout(void)
#else
static void	tree_layout()
#endif
{
	int actypos;
	int maxboxheight;
	int i, fresh;
	GNLIST li;
	GNODE v;
	CONNECT c;

	debugmessage("tree_layout","");

	horder_warn = 0;

	/* First, check the layout factors */

	if (G_yspace<5)  G_yspace=5;
	if (G_xspace<5)  G_xspace=5;
	if (G_dspace==0) {
		if (G_spline) G_dspace = 4*G_xspace/5;
		else          G_dspace = G_xspace/2;
	}
   
	if (G_flat_factor<1)   G_flat_factor = 1;
	if (G_flat_factor>100) G_flat_factor = 100;
	
	/* Now calculate the y positions */

	actypos = yralign(G_ybase);

	for (i=0; i<=maxdepth+1; i++) {
		TACTX(layer[i]) = G_xbase;
		maxboxheight = 0;
		li      = TSUCC(layer[i]);
		while (li) {
			NY(GNNODE(li))   = actypos;
			if (maxboxheight<NHEIGHT(GNNODE(li)))
				maxboxheight = NHEIGHT(GNNODE(li));
			li = GNNEXT(li);
		}	
		if (G_yalign==AL_CENTER) {
			li      = TSUCC(layer[i]);
			while (li) {
				NY(GNNODE(li))   += (maxboxheight-
						      NHEIGHT(GNNODE(li)))/2;
				li = GNNEXT(li);
			}
		}
		else if (G_yalign==AL_BOTTOM) {
			li      = TSUCC(layer[i]);
			while (li) {
				NY(GNNODE(li))   += (maxboxheight-
						      NHEIGHT(GNNODE(li)));
				li = GNNEXT(li);
			}
		}
		actypos += (maxboxheight + G_yspace);
		actypos = yralign(actypos);
	}

	v = nodelist;
	while (v) { NMARK(v) = 1; v = NNEXT(v); }
	v = labellist;
	while (v) { NMARK(v) = 1; v = NNEXT(v); }
	v = dummylist;
	while (v) { NMARK(v) = 1; v = NNEXT(v); }

	/* Now the real tree layout */

	mymaxoutdeg = 0;
	for (i=0; i<= maxdepth+1; i++) {
		li = TSUCC(layer[i]);
		while (li) {
			v = GNNODE(li);
			fresh = NMARK(v);
			c = NCONNECT(v);
			if (c) {
				if (backward_connection1(c)) fresh = 0;
				if (backward_connection2(c)) fresh = 0;
			}
			if (fresh) {
				gs_wait_message('T');
				(void)find_position(v,G_xbase+NWIDTH(v)/2);
			}
			li = GNNEXT(li);
		}
	}
}


/* Find position of a node
 * -----------------------
 * leftest_pos is the leftest position allowed as center of the node.
 * It returns the center of the positioned node.
 */

#ifdef ANSI_C
static int find_position(GNODE v, int leftest_pos)
#else
static int find_position(v,leftest_pos)
GNODE v;
int leftest_pos;
#endif
{
	int xpos, minpos, maxpos, l, num, i;
	ADJEDGE a;
	int minhorder, maxhorder;
	GNODE w, actl, actr, actn;
	GNODE conn1, conn2, leftconn;
	CONNECT c;

	debugmessage("find_position","");

	if (leftest_pos<0) leftest_pos = 0;
	if (!v) return(leftest_pos);
	xpos = leftest_pos;

	NMARK(v) = 0;
	if ((NHORDER(v)!= -1)&&(!horder_warn)) {
		horder_warn = 1;
		if (!silent) {
			FPRINTF(stderr,"Note: On tree layout ");
			FPRINTF(stderr,"the attribute `horizontal_order' ");
			FPRINTF(stderr,"sorts only the child nodes\n");
			FPRINTF(stderr,"of a node locally, ");
			FPRINTF(stderr,"but not the whole layer.");
			FPRINTF(stderr,"\n");
		}
	}

	l = NTIEFE(v);

	conn1 = conn2 = 0;
	c = NCONNECT(v);
	if (c) {
		if (forward_connection1(c)) { conn1 = EEND(CEDGE(c)); }
		if (forward_connection2(c)) { conn2 = EEND(CEDGE2(c)); }
	}


	if (conn1 && conn2) {

		if (NHORDER(conn1)== -1) { 
			if (NHORDER(conn2)<NHORDER(v)) 
				find_position(conn2, 
				   xpos-NWIDTH(v)/2-NWIDTH(conn2)/2-G_xspace);
			else    find_position(conn1, 
				   xpos-NWIDTH(v)/2-NWIDTH(conn1)/2-G_xspace);
		}
		else if (NHORDER(conn1)==NHORDER(v)) {
			if (NHORDER(conn2)<NHORDER(v)) 
				find_position(conn2, 
				   xpos-NWIDTH(v)/2-NWIDTH(conn2)/2-G_xspace);
			else    find_position(conn1, 
				   xpos-NWIDTH(v)/2-NWIDTH(conn1)/2-G_xspace);
		}
		else if (NHORDER(conn1)<NHORDER(v)) {
			find_position(conn1, 
				   xpos-NWIDTH(v)/2-NWIDTH(conn1)/2-G_xspace);
		}
		else {  if (NHORDER(conn2)<NHORDER(conn1)) 
				find_position(conn2, 
				   xpos-NWIDTH(v)/2-NWIDTH(conn2)/2-G_xspace);
			else    find_position(conn1, 
				   xpos-NWIDTH(v)/2-NWIDTH(conn1)/2-G_xspace);
		}	

	}
	else if (conn1) {
		if (NHORDER(conn1)!= -1) {
			if (NHORDER(conn1)<NHORDER(v)) {
				find_position(conn1,
				   xpos-NWIDTH(v)/2-NWIDTH(conn1)/2-G_xspace);
			}
		}
	}
	else if (conn2) {
		if (NHORDER(conn2)!= -1) {
			if (NHORDER(conn2)<NHORDER(v)) {
				find_position(conn2, 
				   xpos-NWIDTH(v)/2-NWIDTH(conn2)/2-G_xspace);
			}
		}
	}

	xpos = leftest_pos;
	if (xpos-NWIDTH(v)/2 < TACTX(layer[l])) 
		xpos = TACTX(layer[l]) + NWIDTH(v)/2;

	switch (NOUTDEG(v)) {
	case 0:
		break;
	case 1:
		a = NSUCC(v);
		assert((a));
		minpos = find_position(TARGET(a),xpos);
		xpos = minpos;
		break;
	default:
		a = NSUCC(v);
		actl = NULL; 
		minhorder = MAXINT;
		while (a) {
			w = TARGET(a);
			if (NHORDER(w)<minhorder) {
				minhorder = NHORDER(w);
				actl = w;
			}
			a = ANEXT(a);	
		}

		a = NSUCC(v);
		actr = NULL; 
		maxhorder = MININT;
		while (a) {
			w = TARGET(a);
			if ((w!=actl) && (NHORDER(w)>maxhorder)) {
				maxhorder = NHORDER(w);
				actr = w;
			}
			a = ANEXT(a);	
		}

		assert((actl)&&(actr)&&(actl!=actr));
		
		a = NSUCC(v);
		num = 0;
		while (a) {
			num+=NWIDTH(TARGET(a));
			a = ANEXT(a);
		}
		num += ((NOUTDEG(v)-1) * G_xspace);
		num -= NWIDTH(actl)/2;
		num -= NWIDTH(actr)/2;

		minpos = find_position(actl, xpos - (num*tree_factor1)/tree_factor2); 

		a = NSUCC(v);
		actn = NULL;
		minhorder = MAXINT;
		while (a) {
			w = TARGET(a);
			if ((w!=actr) && (NMARK(w)) && (NHORDER(w)<minhorder)) {
				minhorder = NHORDER(w);
				actn = w;
			}
			a = ANEXT(a);	
		}

		i = 2;
		while (actn) {
			if (l>spread_level) 
				maxpos = find_position(actn,
					minpos + (2*(i-1)*(xpos-minpos))/
						(NOUTDEG(v)-1)); 
			else {
				if (i<=(NOUTDEG(v)+1)/2) 
					maxpos = find_position(actn,
					   minpos + (2*(i-1)*(xpos-minpos))/
						(NOUTDEG(v)-1)); 
				else
					maxpos = find_position(actn, xpos);
			}
			if (l>spread_level) {
				xpos = minpos + (NOUTDEG(v)-1)*(maxpos-minpos)/
						(2*(i-1));
				if (xpos<leftest_pos) xpos = leftest_pos;
			}
			i++;
			a = NSUCC(v);
			actn = NULL;
			minhorder = MAXINT;
			while (a) {
				w = TARGET(a);
				if (   (w!=actr) && (NMARK(w)) 
				    && (NHORDER(w)<minhorder)) {
					minhorder = NHORDER(w);
					actn = w;
				}
				a = ANEXT(a);	
			}

		}
		if (l>spread_level) 
			maxpos = find_position(actr,
				minpos + (2*(i-1)*(xpos-minpos))/
					(NOUTDEG(v)-1)); 
		else {
			if (i<=(NOUTDEG(v)+1)/2) 
				maxpos = find_position(actr,
				   minpos + (2*(i-1)*(xpos-minpos))/
					(NOUTDEG(v)-1)); 
			else
				maxpos = find_position(actr, xpos);
		}
		if (l>spread_level) {
			xpos = minpos + (NOUTDEG(v)-1)*(maxpos-minpos)/
					(2*(i-1));
			if (xpos<leftest_pos) xpos = leftest_pos;
		}
		
		xpos = (minpos+maxpos)/2;
		if (xpos-NWIDTH(v)/2 < TACTX(layer[l])) 
			xpos = TACTX(layer[l]) + NWIDTH(v)/2;
	}

	NX(v) = xpos - NWIDTH(v)/2;

	if ((NWIDTH(v)==0) && (NHEIGHT(v)==0))
		NX(v) = dxralign(NX(v)+NWIDTH(v)/2) - NWIDTH(v)/2;
	else	NX(v) = xralign(NX(v) +NWIDTH(v)/2) - NWIDTH(v)/2;
	TACTX(layer[l]) = NX(v) + NWIDTH(v) + G_xspace;

	leftconn = 0;
	if (conn1 && (!NMARK(conn1))) leftconn = conn1;
	if (conn2 && (!NMARK(conn2))) leftconn = conn2;

	if (conn1 && (NMARK(conn1))) (void)find_position(conn1,TACTX(layer[l]));
	if (conn2 && (NMARK(conn2))) (void)find_position(conn2,TACTX(layer[l]));

	if (leftconn) correct_position(leftconn,v);

	return(xpos);	
}


/* Correct the position of a left neighbor node
 * --------------------------------------------
 * If the tree at v is wide, the left neighbor node conn is far away
 * from v. To avoid this situation, we calculate how much the tree with
 * root conn can be shifted to the right. This works only, if the tree
 * at conn has a smaller depth than the tree at v, since otherwise
 * the shifting to the right would influence the TACTX-values which
 * indicate the leftest available position.
 */

#define TMINX(x) TCROSS(x)

#ifdef ANSI_C
static void correct_position(GNODE conn, GNODE v)
#else
static void correct_position(conn,v)
GNODE conn;
GNODE v;
#endif
{
	int i, depth, diff;
	debugmessage("correct_position","");

	gs_wait_message('T');
	assert((NX(v)>NX(conn)));
	for (i=0; i<=maxdepth+1; i++) 
		TMINX(layer[i]) = MAXINT; 

	depth = min_x_in_tree(v,conn);

	diff  = max_x_in_tree(conn,depth);

	if (diff-G_xspace>0) correct_xpos(conn, xlalign(diff-G_xspace));
}



/* Traverse the tree v except conn and calculate the minimal x-positions
 * ---------------------------------------------------------------------
 * The minimal x-positions at each level are stored in TMINX of the levels.
 * We return the maximal depth of the tree.
 */

#ifdef ANSI_C
static int min_x_in_tree(GNODE v, GNODE conn)
#else
static int min_x_in_tree(v,conn)
GNODE v;
GNODE conn;
#endif
{
	int maxlevel, l, h;
	ADJEDGE a;
	CONNECT c;

	debugmessage("min_x_in_tree","");

	if (v==conn) return(0);

	maxlevel = l = NTIEFE(v);
	if (NX(v) < TMINX(layer[l])) TMINX(layer[l]) = NX(v);

	a = NSUCC(v);
	while (a) {
		h = min_x_in_tree(TARGET(a),conn);
		if (h>maxlevel) maxlevel = h;	
		a = ANEXT(a);
	}

	c = NCONNECT(v);
	if (c) {
		if (forward_connection1(c)) {
			h = min_x_in_tree(EEND(CEDGE(c)),conn); 
			if (h>maxlevel) maxlevel = h;	
		}
		if (forward_connection2(c)) {
			h = min_x_in_tree(EEND(CEDGE2(c)),conn); 
			if (h>maxlevel) maxlevel = h;	
		}
	}
	return(maxlevel);
}


/* Traverse the tree v and calculate the maximal x-positions
 * ---------------------------------------------------------
 * We compare the maximal x-positions with the minimal x-positions
 * of the right neighbor tree (which are in TMINX) and return the
 * minimal difference.
 * If the tree at v is deeper than the right neigbour tree, we return 0.
 */

#ifdef ANSI_C
static int max_x_in_tree(GNODE v, int depth)
#else
static int max_x_in_tree(v,depth)
GNODE v;
int depth;
#endif
{
	int mindiff, l, h;
	ADJEDGE a;
	CONNECT c;

	debugmessage("max_x_in_tree","");

	l = NTIEFE(v);
	if (l>depth) return(0);
	mindiff = TMINX(layer[l]) - NX(v) - NWIDTH(v);
	a = NSUCC(v);
	while (a) {
		h = max_x_in_tree(TARGET(a),depth);
		if (h<mindiff) mindiff = h;	
		a = ANEXT(a);
	}

	c = NCONNECT(v);
	if (c) {
		if (forward_connection1(c)) {
			h = max_x_in_tree(EEND(CEDGE(c)),depth); 
			if (h<mindiff) mindiff = h;	
		}
		if (forward_connection2(c)) {
			h = max_x_in_tree(EEND(CEDGE2(c)),depth); 
			if (h<mindiff) mindiff = h;	
		}
	}
	return(mindiff);
}


/* Correct the x-position of the tree at v by diff
 * -----------------------------------------------
 */

#ifdef ANSI_C
static void correct_xpos(GNODE v, int diff)
#else
static void correct_xpos(v,diff)
GNODE v;
int diff;
#endif
{
	ADJEDGE a;
	CONNECT c;

	debugmessage("correc_xpos","");

	NX(v) += diff;

	a = NSUCC(v);
	while (a) {
		correct_xpos(TARGET(a),diff);
		a = ANEXT(a);
	}

	c = NCONNECT(v);
	if (c) {
		if (forward_connection1(c)) {
			correct_xpos(EEND(CEDGE(c)),diff); 
		}
		if (forward_connection2(c)) {
			correct_xpos(EEND(CEDGE2(c)),diff); 
		}
	}
}

