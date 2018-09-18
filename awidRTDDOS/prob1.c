#include"defs.h"
float prob1(char * sourceIPs, char *sourceIP, int len){
    int i,j,count;
    count = 1;
    i=1;
    //for (i=0;i<(len-1);i++){
       // como o vetor estar ordenado, ele só vai ser percorrido enquanto não chegar no próximo ip
       while (!strcmp(sourceIPs + 18*i,sourceIP)) {
    // conta
        count = count + 1;
        i++;
       }

    //}
    return (float)count/(float)(len-1);

}
