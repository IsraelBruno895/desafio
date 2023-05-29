#include <stdio.h>

int main() {
    int num, contador = 0, numInicial,x;

  printf("digite um numero:\n");
  scanf("%d",&num);

  printf("digite a base:\n");
  scanf("%d",&x);

  if(num%x >0 ){
    printf("nao e potencia");
  }else{
 
  numInicial = num;
   
    while (num>1){
      num /= x;
      contador ++;
    }
 
    printf("%d e potencia de %d pois %d^%d = %d", num,x,x, contador, numInicial);

  }
   
    return 0;
}

