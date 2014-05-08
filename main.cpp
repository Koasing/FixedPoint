#include <cstdio>

#include "FixedPoint.h"

using namespace std;


void logprint(const char *varname, double f, FIXED_POINT fp)
{
    printf("%s float(%12.6f) fixed(%12.6f) | INT=%5d DEC=%.6f\n",
            varname, f, fixed2double(fp),
            INTPART(fp), DECPART(fp) / (double)FIXED_DEC_MUL);
}

int main(int argc, char *argv[])
{
    double f1 = -56.7890f;
    double f2 = -12.3456f;

    FIXED_POINT fp1 = double2fixed(f1);
    FIXED_POINT fp2 = double2fixed(f2);

    logprint("fp1", f1, fp1);
    logprint("fp2", f2, fp2);

    logprint("add", f1 + f2, fp1 + fp2);
    logprint("sub", f1 - f2, fp1 - fp2);
    logprint("mul", f1 * f2, fixed_mul(fp1, fp2));
    logprint("div", f1 / f2, fixed_div(fp1, fp2));
}
