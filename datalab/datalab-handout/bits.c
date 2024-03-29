/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 * <Zhiqing Xiao, zhiqingx@andrew.cmu.edu>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  long Funct(long arg1, long arg2, ...) {
      /* brief description of how your implementation works */
      long var1 = Expr1;
      ...
      long varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. (Long) integer constants 0 through 255 (0xFFL), inclusive. You are
      not allowed to use big constants such as 0xffffffffL.
  3. Function arguments and local variables (no global variables).
  4. Local variables of type int and long
  5. Unary integer operations ! ~
     - Their arguments can have types int or long
     - Note that ! always returns int, even if the argument is long
  6. Binary integer operations & ^ | + << >>
     - Their arguments can have types int or long
  7. Casting from int to long and from long to int
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting other than between int and long.
  7. Use any data type other than int or long.  This implies that you
     cannot use arrays, structs, or unions.
 
  You may assume that your machine:
  1. Uses 2s complement representations for int and long.
  2. Data type int is 32 bits, long is 64.
  3. Performs right shifts arithmetically.
  4. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31 (int) or 63 (long)

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 63
   */
  long pow2plus1(long x) {
     /* exploit ability of shifts to compute powers of 2 */
     /* Note that the 'L' indicates a long constant */
     return (1L << x) + 1L;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 63
   */
  long pow2plus4(long x) {
     /* exploit ability of shifts to compute powers of 2 */
     long result = (1L << x);
     result += 4L;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
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
// 2
/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Examples:
 *     copyLSB(5L) = 0xFFFFFFFFFFFFFFFFL,
 *     copyLSB(6L) = 0x0000000000000000L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
long copyLSB(long x) {
    return ~(x & 0x01L) + 1;
}
/*
 * distinctNegation - returns 1 if x != -x.
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 5
 *   Rating: 2
 */
long distinctNegation(long x) {
    return !!(x ^ (~x + 1));
}
/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (least significant) to 7 (most significant)
 *   Examples: getByte(0x12345678L,1) = 0x56L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
long getByte(long x, long n) {
    return (x >> (n << 3)) & 0xFFL;
}
/*
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   where bits are numbered from 0 (least significant) to 63 (most significant)
 *   Examples anyEvenBit(0xAL) = 0L, anyEvenBit(0xEL) = 1L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 14
 *   Rating: 2
 */
long anyEvenBit(long x) {
    long constant = 0x55L | 0x55L << 32;
    constant |= constant << 16;
    constant |= constant << 8;
    return !!(x & constant);
}
// 3
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4L,5L) = 4L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
long conditional(long x, long y, long z) {
    long mask = ~(!x) + 1;
    return (~mask & y) | (mask & z);
}
/*
 * subtractionOK - Determine if can compute x-y without overflow
 *   Example: subtractionOK(0x8000000000000000L,0x8000000000000000L) = 1L,
 *            subtractionOK(0x8000000000000000L,0x7000000000000000L) = 0L,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
long subtractionOK(long x, long y) {
    long xmsb = (x >> 63) & 0x01L;
    long ymsb = (y >> 63) & 0x01L;
    long subt = x + (~y + 1); // x - y
    long smsb = (subt >> 63) & 0x01L;
    return !((xmsb ^ ymsb) & (xmsb ^ smsb));
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4L,5L) = 1L.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
long isLessOrEqual(long x, long y) {
    long xmsb = (x >> 63) & 0x01L;
    long ymsb = (y >> 63) & 0x01L;
    long subt = y + (~x + 1); // y - x
    long smsb = (subt >> 63) & 0x01L;
    long mask = ~(!(xmsb ^ ymsb)) + 1;
    return (~mask & xmsb) | (mask & !smsb);
}
/*
 * bitMask - Generate a mask consisting of all 1's
 *   between lowbit and highbit
 *   Examples: bitMask(5L,3L) = 0x38L
 *   Assume 0 <= lowbit < 64, and 0 <= highbit < 64
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
long bitMask(long highbit, long lowbit) {
    long bits = highbit + (~lowbit + 1); // hi - lo
    long bmsb = (bits >> 63) & 0x01L;
    long mask = ~(!bmsb) + 1;
    long lmsk = mask << lowbit;
    long hmsk = (mask << highbit) << 1;
    return (lmsk ^ hmsk) & mask;
}
// 4
/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples:
 *    trueThreeFourths(11L) = 8
 *    trueThreeFourths(-9L) = -6
 *    trueThreeFourths(4611686018427387904L) = 3458764513820540928L (no
 * overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
long trueThreeFourths(long x) {
    long nsbt = x + (~(x >> 2) + 1);
    long psbt = x + ((~x + 1) >> 2); // TODO: why it works
    long xmsb = (x >> 63) & 0x01L;
    long mask = ~(!xmsb) + 1;
    return (~mask & nsbt) | (mask & psbt);
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5L) = 2, bitCount(7L) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */
long bitCount(long x) {
    long mask1, mask2, mask3, mask4, mask5, mask6;

    mask1 = 0x11L | (0x11L << 32); // 0x0000 0011 0000 0011L
    mask1 |= mask1 << 16;          // 0x0011 0011 0011 0011L
    mask1 |= mask1 << 8;           // 0x1111 1111 1111 1111L
    mask2 = mask1 | mask1 << 1;    // 0x3333 3333 3333 3333L
    mask1 |= mask1 << 2;           // 0x5555 5555 5555 5555L

    mask3 = 0x0FL | (0x0FL << 16); // 0x0000 0000 000F 000FL
    mask3 |= mask3 << 32;          // 0x000F 000F 000F 000FL
    mask4 = mask3 | mask3 << 4;    // 0x00FF 00FF 00FF 00FFL
    mask3 |= mask3 << 8;           // 0x0F0F 0F0F 0F0F 0F0FL

    mask6 = 0xFFL | (0xFFL << 8);  // 0x0000 0000 0000 FFFFL
    mask5 = mask6 | (mask6 << 32); // 0x0000 FFFF 0000 FFFFL
    mask6 |= mask6 << 16;          // 0x0000 0000 FFFF FFFFL

    x = (x & mask1) + ((x >> 1) & mask1);
    x = (x & mask2) + ((x >> 2) & mask2);
    x = (x & mask3) + ((x >> 4) & mask3);
    x = (x & mask4) + ((x >> 8) & mask4);
    x = (x & mask5) + ((x >> 16) & mask5);
    x = (x & mask6) + ((x >> 32) & mask6);
    return x;
}
// float
/*
 * floatNegate - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatNegate(unsigned uf) {
    if ((uf >> 23 & 0xFF) == 255) { // exp == 255 && frac != 0
        if ((uf & 0x7FFFFF) != 0)
            return uf;
    }
    return uf ^ (0x1L << 31);
}
/*
 * floatIsLess - Compute f < g for floating point arguments f and g.
 *   Both the arguments are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   If either argument is NaN, return 0.
 *   +0 and -0 are considered equal.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 3
 */
int floatIsLess(unsigned uf, unsigned ug) {
    unsigned fs = (uf >> 31) & 0x01;
    unsigned fe = (uf >> 23) & 0xFF;
    unsigned ff = uf & 0x7FFFFF;
    unsigned gs = (ug >> 31) & 0x01;
    unsigned ge = (ug >> 23) & 0xFF;
    unsigned gf = ug & 0x7FFFFF;
    int scomp = fs - gs;
    int ecomp = fe - ge;
    int fcomp = ff - gf;
    if (fe == 0xFF) { // uf == NaN
        if (ff != 0)
            return 0;
    }
    if (ge == 0xFF) { // ug == NaN
        if (gf != 0)
            return 0;
    }
    if (fe == 0 && ff == 0) { // -0 == +0
        if (ge == 0 && gf == 0)
            return 0;
    }

    if (scomp != 0)
        return fs;
    if (ecomp != 0)
        return fs ^ (ecomp < 0);
    if (fcomp != 0)
        return fs ^ (fcomp < 0);
    return 0;
}
/*
 * floatScale4 - Return bit-level equivalent of expression 4*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale4(unsigned uf) {
    unsigned fs = uf & 0x80000000;
    unsigned fe = uf & 0x7F800000;
    unsigned de = fe >> 23;
    unsigned ff = uf & 0x007FFFFF;

    if (de == 0) { // denormalized
        if (ff == 0) { // +0 -0 
            return uf; 
        }
        uf = fs | uf << 1;
        fe = uf & 0x7F800000;
        de = fe >> 23;
        ff = uf & 0x007FFFFF;
        if (de == 0) return fs | uf << 1;
        de++;
        return fs | (de << 23) | ff;
    }
    if (de == 255) { // NaN
        return uf;
    }
    de++;
    if (de == 255) { // overflow: INF
        return fs | 0x7F800000;
    }
    de++;
    if (de == 255) { // overflow: INF
        return fs | 0x7F800000;
    }
    return fs | (de << 23) | ff;
}
