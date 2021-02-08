#include <stdio.h>
  
int main() {
    int i,n,prims[n],x=0,p,nums[n];
    n = 19000; // número hasta el que se quiere buscar
    for(i=2;i<=n;i++) {
        if(nums[i] != 1 || i == 2) {
            prims[x] = i;
            printf("El número %d es prim",i);
            for(p=2;(p*i)<=n;p++) {
                nums[(p*i)] = 1;
            }
            x++;
        }
    }
    printf("Hay %d números primos",x);
}
