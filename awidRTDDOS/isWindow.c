#include"defs.h"
int isWindow (double t0, double t1, double windowLength){
    double tFinal;
    tFinal = t0 + windowLength;
    if (t1 <= tFinal)
        return 0;
        else
        return 1;
}
