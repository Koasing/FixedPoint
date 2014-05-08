#pragma once

/**
 * Fixed Point fraction implementation : header
 * Author : koasing at gmail.com
 */


/* Fixed Point OFFSET... any even number (2, 4, 6, ..., 30) */
#define FIXED_OFFSET    16

/* Fixed Point Decimal Multiplier */
#define FIXED_DEC_MUL   (1 << FIXED_OFFSET)
#define FIXED_DEC_MASK  (FIXED_DEC_MUL - 1)

/* Integer part, offset adjusted */
#define INTPART(fp)     ((fp) >> FIXED_OFFSET)

/* Decimal part, offset NOT adjusted */
#define DECPART(fp)     ((fp)  & FIXED_DEC_MASK)

typedef int FIXED_POINT;

/* Convert Double Float to Fixed Point */
FIXED_POINT double2fixed(double in);

/* Convert Fixed Point to Double Float */
double      fixed2double(FIXED_POINT in);

/* basic operations */
FIXED_POINT fixed_add(FIXED_POINT a, FIXED_POINT b);
FIXED_POINT fixed_sub(FIXED_POINT a, FIXED_POINT b);
FIXED_POINT fixed_mul(FIXED_POINT a, FIXED_POINT b);
FIXED_POINT fixed_div(FIXED_POINT a, FIXED_POINT b);
