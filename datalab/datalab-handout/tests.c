/* Testing Code */

#include <limits.h>
#include <math.h>

/* Routines used by floation point test code */

/* Convert from bit level representation to floating point number */
float u2f(unsigned u) {
  union {
    unsigned u;
    float f;
  } a;
  a.u = u;
  return a.f;
}

/* Convert from floating point number to bit-level representation */
unsigned f2u(float f) {
  union {
    unsigned u;
    float f;
  } a;
  a.f = f;
  return a.u;
}

/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */
//2
long test_copyLSB(long x)
{
  return (x & 0x1L) ? -1 : 0;
}
long test_distinctNegation(long x) {
    return (long) (x != -x);
}
long test_getByte(long x, long n)
{
    unsigned char byte = 0;
    switch(n) {
    case 0:
      byte = x;
      break;
    case 1:
      byte = x >> 8;
      break;
    case 2:
      byte = x >> 16;
      break;
    case 3:
      byte = x >> 24;
      break;
    case 4:
      byte = x >> 32;
      break;
    case 5:
      byte = x >> 40;
      break;
    case 6:
      byte = x >> 48;
      break;
    case 7:
      byte = x >> 56;
      break;
    }
    return (long) (unsigned) byte;
}
long test_anyEvenBit(long x) {
  int i;
  for (i = 0; i < 64; i+=2)
      if (x & (1L<<i))
   return 1L;
  return 0L;
}
//3
long test_conditional(long x, long y, long z)
{
  return x?y:z;
}
long test_subtractionOK(long x, long y)
{
  __int128 ldiff = (__int128) x - y;
  return (long) (ldiff == (long) ldiff);
}
long test_isLessOrEqual(long x, long y)
{
    return (long) (x <= y);
}
long test_bitMask(long highbit, long lowbit)
{
  long result = 0L;
  int i;
  for (i = lowbit; i <= highbit; i++)
    result |= 1L << i;
  return result;
}
//4
long test_trueThreeFourths(long x)
{
  return (long) (((__int128) x * 3L)/4L);
}
long test_bitCount(long x) {
  long result = 0;
  long i;
  for (i = 0; i < 64; i++)
    result += (x >> i) & 0x1;
  return result;
}
//float
unsigned test_floatNegate(unsigned uf) {
    float f = u2f(uf);
    float nf = -f;
    if (isnan(f))
 return uf;
    else
 return f2u(nf);
}
int test_floatIsLess(unsigned uf, unsigned ug) {
    float f = u2f(uf);
    float g = u2f(ug);
    return f < g;
}
unsigned test_floatScale4(unsigned uf) {
  float f = u2f(uf);
  float tf = 4*f;
  if (isnan(f))
    return uf;
  else
    return f2u(tf);
}
