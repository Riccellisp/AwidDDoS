#include"defs.h"
float prob1(char * sourceIPs, char *sourceIP, int len){
    int i,j,count;
    count = 0;
    for (i=0;i<len;i++){
       if (strcmp(*(sourceIPs + 18*i),sourceIP)){
    // conta
        count = count + 1;
       }

    }
    return count/len;

}
