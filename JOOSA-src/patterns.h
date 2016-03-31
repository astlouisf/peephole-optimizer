/*
 * JOOS is Copyright (C) 1997 Laurie Hendren & Michael I. Schwartzbach
 *
 * Reproduction of all or part of this software is permitted for
 * educational or research use on condition that this copyright notice is
 * included in any copy. This software comes with no warranty of any
 * kind. In no event will the authors be liable for any damages resulting from
 * use of this software.
 *
 * email: hendren@cs.mcgill.ca, mis@brics.dk
 */

/* iload x        iload x        iload x
 * ldc 0          ldc 1          ldc 2
 * imul           imul           imul
 * ------>        ------>        ------>
 * ldc 0          iload x        iload x
 *                               dup
 *                               iadd
 */

int simplify_multiplication_right(CODE **c)
{ int x,k;
  if (is_iload(*c,&x) && 
      is_ldc_int(next(*c),&k) && 
      is_imul(next(next(*c)))) {
     if (k==0) return replace(c,3,makeCODEldc_int(0,NULL));
     else if (k==1) return replace(c,3,makeCODEiload(x,NULL));
     else if (k==2) return replace(c,3,makeCODEiload(x,
                                       makeCODEdup(
                                       makeCODEiadd(NULL))));
     return 0;
  }
  return 0;
}

/* dup
 * astore x
 * pop
 * -------->
 * astore x
 */
int simplify_astore(CODE **c)
{ int x;
  if (is_dup(*c) &&
      is_astore(next(*c),&x) &&
      is_pop(next(next(*c)))) {
     return replace(c,3,makeCODEastore(x,NULL));
  }
  return 0;
}

/* iload x
 * ldc k   (0<=k<=127)
 * iadd
 * istore x
 * --------->
 * iinc x k
 */ 
int positive_increment(CODE **c)
{ int x,y,k;
  if (is_iload(*c,&x) &&
      is_ldc_int(next(*c),&k) &&
      is_iadd(next(next(*c))) &&
      is_istore(next(next(next(*c))),&y) &&
      x==y && 0<=k && k<=127) {
     return replace(c,4,makeCODEiinc(x,k,NULL));
  }
  return 0;
}

/* goto L1
 * ...
 * L1:
 * goto L2
 * ...
 * L2:
 * --------->
 * goto L2
 * ...
 * L1:    (reference count reduced by 1)
 * goto L2
 * ...
 * L2:    (reference count increased by 1)  
 */
int simplify_goto_goto(CODE **c)
{ int l1,l2;
  if (is_goto(*c,&l1) && is_goto(next(destination(l1)),&l2) && l1>l2) {
     droplabel(l1);
     copylabel(l2);
     return replace(c,1,makeCODEgoto(l2,NULL));
  }
  return 0;
}

// New //




/* should we do this? (if so, repeat for other arithmetic operations)
 * n + m = (n+m)
 * ldc n
 * ldc m
 * iadd
 * ------>
 * ldc (n+m)
 */


/* istore k       iload k        ldc_int d	(0<=k<=3) (0<=d<=5)
 * ------>        ------>        ------>
 * istore_k       iload_k        iconst_d
 */

/* x + 0 = x
 * iload x
 * ldc 0
 * iadd
 * ------>
 * iload x
 */

/* nop
 * --------->
 */ 

/* 
 * dup
 * pop
 * --------->
 */

/* 
 * pop
 * dup
 * --------->
 */

/* 
 * swap
 * swap
 * --------->
 */

// branching //
/* 
 * iload_0
 * ifeq L
 * --------->
 * goto L
 */

/* 
 * iload k (or iload_k, where k != 0)
 * ifne L
 * --------->
 * goto L
 */

/* isub
 * ifeq L
 * --------->
 * if_icmpeq L
 */ 

/* isub
 * ifne L
 * --------->
 * if_icmpne L
 */ 

/* aconst_null
 * ifnull L
 * --------->
 * goto L
 */ 

/* 
 * L:    (with no incoming edges)
 * --------->
 * 
 */



// loop folding?
// put in loop invariants? (vms slide 60)
// simply arithmetic expressions that have constants?
// factor arithmetic expressions?
// simplify control flow to better optimize?
// write a program to test out the permutations of our rules to get the best order of optimizations?
// swap order arithmetic expressions because it might allow for optimizations? This would remove the need for the following symmetric patterns but doesn't follow a lexicographic order. If we put the swap at the beginning though, it might find an optimizing rule and that that iteration will decrease the lexicographic order.

/* 
 * 
 * --------->
 * 
 */ 





/* symmetric version of previous patterns */
/* 
 * ldc 0          ldc 1          ldc 2
 * iload x        iload x        iload x
 * imul           imul           imul
 * ------>        ------>        ------>
 * ldc 0          iload x        iload x
 *                               dup
 *                               iadd
 */

/* ldc 0
 * iload x
 * iadd
 * ------>
 * iload x
 */

/* ldc k   (0<=k<=127)
 * iload x
 * iadd
 * istore x
 * --------->
 * iinc x k
 */ 

// what's i2c?


#define OPTS 4

OPTI optimization[OPTS] = {simplify_multiplication_right,
                           simplify_astore,
                           positive_increment,
                           simplify_goto_goto};
