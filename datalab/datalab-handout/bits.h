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
long copyLSB(long);
long test_copyLSB(long);
long distinctNegation(long);
long test_distinctNegation(long);
long getByte(long, long);
long test_getByte(long, long);
long anyEvenBit(long);
long test_anyEvenBit(long);
//3
long conditional(long, long, long);
long test_conditional(long, long, long);
long subtractionOK(long, long);
long test_subtractionOK(long, long);
long isLessOrEqual(long, long);
long test_isLessOrEqual(long, long);
long bitMask(long, long);
long test_bitMask(long, long);
//4
long trueThreeFourths(long);
long test_trueThreeFourths(long);
long bitCount(long);
long test_bitCount(long);
//float
unsigned floatNegate(unsigned);
unsigned test_floatNegate(unsigned);
int floatIsLess(unsigned, unsigned);
int test_floatIsLess(unsigned, unsigned);
unsigned floatScale4(unsigned);
unsigned test_floatScale4(unsigned);
