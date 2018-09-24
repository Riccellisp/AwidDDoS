#include"defs.h"
int isWindow (double firstPacketWindowTime, double packetWindowTime , double windowLength){
    double tFinal;
    tFinal = firstPacketWindowTime + windowLength;
    if (packetWindowTime <= tFinal)
        return 0;
        else
        return 1;
}
