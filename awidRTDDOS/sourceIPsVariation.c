#include"defs.h"
#include<stdlib.h>
float sourceIPsVariation(char *sourceIPs, int len){
    int i,j,k;
        for(i=0; i<len; i++){
            for(j=i+1;j<len;){
                if(strcmp(sourceIPs[i],sourceIPs[j])==0){
                    for (k=j+1; k<N; k++){
                        // memcpy(a[k], a[k+1], 6);
                        // two errors here:
                        // 1. You only have 5 bytes per element, so copy only 5
                        // 2. this is *off by one* for the array index
                        // correct version:
                        memcpy(a[k-1], a[k], 5);
                        // (or use strcpy())
                    }
                    len--;
                }else{
                    j++;
                }
            }
        }



}
