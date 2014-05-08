#include "FixedPoint.h"

/**
 * Fixed Point decimal implementation : implementation
 * Author : koasing at gmail.com
 */


/* Use "long long" integer (64bit) for mul/div */
#define USE_LONG_LONG       0

/* Use iterative multiplication. High precision? (I can't sure.) */
#define USE_ITERATIVE_MUL   1


FIXED_POINT double2fixed(double in)
{
    return (FIXED_POINT)(in * FIXED_DEC_MUL);
}

double fixed2double(FIXED_POINT in)
{
    return in / (double)FIXED_DEC_MUL;
}

FIXED_POINT fixed_add(FIXED_POINT a, FIXED_POINT b)
{
    return a + b;
}

FIXED_POINT fixed_sub(FIXED_POINT a, FIXED_POINT b)
{
    return a - b;
}

FIXED_POINT fixed_mul(FIXED_POINT a, FIXED_POINT b)
{
#if USE_LONG_LONG
    long long bigint = a;
    bigint *= b;

    // intended cutoff
    return (FIXED_POINT)(bigint >> FIXED_OFFSET);
#elif USE_ITERATIVE_MUL
    FIXED_POINT mul_int = a * INTPART(b);
    FIXED_POINT mul_dec = 0;

    for (int i = 0; i < FIXED_OFFSET; i++) {
        // sum multiplication
        if (b & 0x00000001) mul_dec += a;
        
        // adjust offset
        mul_dec >>= 1;
        b >>= 1;
    }

    return mul_int + mul_dec;
#else
    FIXED_POINT int_int = DECPART(a);
    FIXED_POINT dec_dec = DECPART(b);

    FIXED_POINT int_dec = INTPART(a) * dec_dec;     // INTPART(a) * DECPART(b);
    FIXED_POINT dec_int = INTPART(b) * int_int;     // DECPART(a) * INTPART(b);

    dec_dec = int_int * dec_dec;                    // DECPART(a) * DECPART(b);
    int_int = INTPART(a) * INTPART(b);

    return (int_int << FIXED_OFFSET) + int_dec + dec_int + (dec_dec >> FIXED_OFFSET);
#endif
}

FIXED_POINT fixed_div(FIXED_POINT a, FIXED_POINT b)
{
#if USE_LONG_LONG
    long long bigint = a;
    bigint <<= FIXED_OFFSET;

    // intended cutoff
    return (FIXED_POINT)(bigint/b);
#else
    FIXED_POINT div = 0;

    // div iteration.
    for (int i = 0; i < FIXED_OFFSET; i++) {
        // divider
        FIXED_POINT d = a / b;

        // remainder
        a -= b * d;

        // sum divider
        div += d;

        // adjust offset
        div <<= 1;
        a <<= 1;
    }

    return div;
#endif
}
