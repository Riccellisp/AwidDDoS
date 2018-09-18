#include"defs.h"
#include <stdlib.h>
#include <string.h>

       static int
       cmpstringp(const void *p1, const void *p2)
       {
           /* The actual arguments to this function are "pointers to
              pointers to char", but strcmp(3) arguments are "pointers
              to char", hence the following cast plus dereference */

           return strcmp(* (char * const *) p1, * (char * const *) p2);
       }


float sourceIPsEntropy(char *sourceIPs,int len){
//    size_t len = strlen(sourceIPs);
    int i,j;
    float result = 0.0;
    
    float total=0.0;

    // ordena a lista de IPs
    qsort(sourceIPs, len - 1, 18, strcmp);
    
    // calcula a probabilidade do primeiro ip da lista ordenada
    result=prob1(sourceIPs, sourceIPs,len);

    printf("prob de %s é %f\n",sourceIPs,result);
    // acumula ...e no final o acumulado tem q dar 1
    total+=result;

    // varre o restante da lista ordenada, por isso i comeca em 1
    for (i=1;i<(len-1);i++) {

      // calcula e acumula a probabilidade do elemento i, caso já não tenha sido calculada, por isso comparação 
      if (strcmp(sourceIPs+18*(i-1),sourceIPs+18*i)) {
		result=prob1(sourceIPs+18*i, sourceIPs+18*i,len);
		total+=result;
      		printf("prob de %s é %f\n",sourceIPs+18*i,result);
      }

    }

    return total;

    /*for (i=0;i<(len-1);i++){
       printf("sourceIPs=%s\n", sourceIPs+18*i);
    }
    for (i=0;i<len;i++){
        for (j=0;j<18;j++){

        result = result + 
        prob1(sourceIPs, 
        *(sourceIPs + 18*i + j),&len) + log2(prob1(sourceIPs, 
        *(sourceIPs + 18*i + j),&len)

);
        }
    }*/

    //return result;


}
