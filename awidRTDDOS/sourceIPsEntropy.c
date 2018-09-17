#include"defs.h"
float sourceIPsEntropy(char *sourceIPs,int len){
//    size_t len = strlen(sourceIPs);
    int i,j;
    float result = 0.0;
    for (i=0;i<len;i++){
        for (j=0;j<18;j++){
        result = result + prob1(sourceIPs, *(sourceIPs + 18*i + j),&len) + log2(prob1(sourceIPs, *(sourceIPs + 18*i + j),&len));
        }
    }

    return result;


}
