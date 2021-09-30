#include <stdio.h>

int main(void){
  int n, i;
  double grade;
  double average = 0;
  FILE *file;

  file = fopen("studentGrades.txt", "r");

  fscanf(file ,"%d", &n);

  for(i=0; i<n; i++){
    fscanf(file, "%lf", &grade);
    average += grade;
  }

  average = average/n;
  printf("%.2f", average);

  return 0;
}
