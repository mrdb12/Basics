#include <stdio.h>
#include <string.h>

int main(void){
  int grade, check;
  scanf("%d", &grade);

  int lastNumber = -1;
  char filename[] = "myGrades.txt";
  FILE *file;
  file = fopen(filename, "r");

  while(fscanf(file, "%d", &check) != EOF){
    lastNumber = check;
  }
  fclose(file);

  if(grade != lastNumber){
    file = fopen(filename, "a");
    fprintf(file , " %d", grade);
    fclose(file);
  }

  file = fopen(filename, "r");
  while(fscanf(file, "%d", &check) != EOF){
    printf("%d ", check);
  }
  fclose(file);

  return 0;
}
