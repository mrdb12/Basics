//TO USE THE MAKEFILE IN TERMINAL, GET INTO THE RIGHT DIRECTORY AND TYPRE "make"

#include <stdio.h>
#include "calc.h"


int main(void){
  int num1, num2;
  scanf("%d %d", &num1, &num2);

  printf("Addition: %d\n", add(num1, num2));
  printf("Subtraction: %d\n", sub(num1, num2));

  return 0;
}
