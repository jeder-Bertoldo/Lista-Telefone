#include <stdio.h>
#include <cstring>
#include <stdlib.h>

struct numeros{
	
 	char num[221];
};
              
int ORDEM(const void *num1, const void *num2)
{
    struct numeros *ia = (struct numeros *)num1; 
    struct numeros *ib = (struct numeros *)num2;
    return strcmp(ia->num, ib->num);
}  
              
int main(){
   
    int RESULTADO;
     int n, i, j;
    struct numeros comp;
    
    while(scanf("%d%*c",&n) != EOF){
        struct numeros array[n];
         RESULTADO = 0;
        for(i = 0; i < n; i++){
            scanf("%[^\n]%*c",&array[i].num);
        }
        qsort(array,n,sizeof(numeros),ORDEM);
        comp = array[0];
        for(i = 1; i < n; i++){
            for(j = 0; j < strlen(array[i].num); j++){
                  if(comp.num[0] != array[i].num[0]){
                             comp = array[i];
                             break;
                  }else if(comp.num[j] == array[i].num[j])  RESULTADO++;
                  else{
                    comp = array[i];
                    break;
                  }
            }
        }
        printf("%d\n", RESULTADO);
    }
    return 0;
}
