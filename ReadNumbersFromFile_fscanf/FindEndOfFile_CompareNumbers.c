#include <stdio.h>

int main(void){
  double myAve, diffAve;
  int count = 1;
  int check = 0;
  FILE *ifile;

  ifile = fopen("gradeComparison.txt", "r");
  fscanf(ifile, "%lf", &myAve);

  while(fscanf(ifile, "%lf", &diffAve) != EOF){
    count++;
    if(myAve < diffAve){
      printf("No %d\n", count);
      check = 1;
      break;
    }
  }
  if(check == 0){
    printf("Yes\n");
  }


  return 0;
}
