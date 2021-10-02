#include <stdio.h>

int main(void){
  int n, i;
  double number;
  FILE *file;

  file = fopen("numbers.txt", "r");

  fscanf(file, "%d", &n);
  printf("There are %d numbers in the file\n", n);

  for(i=0; i<n; i++){
    fscanf(file, "%lf", &number);
    printf("The number %.2f has been read\n", number);
  }

  fclose(file);

  return 0;
}
