#include <stdio.h>
  
int main() {
    int n = 19000; // número hasta el que se quiere buscar
    int i,prims[n],x=0,p,nums[n];
    for(i=2;i<=n;i++) {
        if(nums[i] != 1 || i == 2) {
            prims[x] = i;
            printf("El número %d es primo \n",i);
            for(p=2;(p*i)<=n;p++) {
                nums[(p*i)] = 1;
            }
            x++;
        }
    }
    printf("Hay %d números primos \n",x);
}
