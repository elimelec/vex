/*
 * Inline and specialization control 
 */
#ifndef BASIC_OP_INLINE_H_INCLUDED
# define BASIC_OP_INLINE_H_INCLUDED

# ifdef BASIC_OP_INLINE
#   if defined(_mfinline_)
#    define _INLINE inline
#    define BASIC_OP_SPECIALIZED
#   elif defined(__GNUC__)
#    define _INLINE inline static
#    define BASIC_OP_SPECIALIZED
#   else
#    define _INLINE /**/
#   endif
# else
#  define _INLINE /**/
# endif

# ifndef BASIC_OP_SPECIALIZED
#  define GEN_OVERFLOW
#  define GEN_CARRY
# endif

#endif
