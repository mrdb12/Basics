#include <stdio.h>
#include <math.h>

int main(void){
  int number;
  double sqrtnum;
  double e;

  scanf("%d", &number);

  sqrtnum = sqrt(number);
  printf("%.8f\n", sqrtnum);

  e = exp(1);
  printf("%.10f\n", e);

  return 0;
}
