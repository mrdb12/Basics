#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  int numPlants;
  double pricePlant, priceTotal;

  if(argv[1] != NULL && argv[2] != NULL){
    numPlants = atoi(argv[1]);
    pricePlant = atof(argv[2]);

    priceTotal =(double) numPlants * pricePlant;

    printf("%d plants for %.2f dollars each cost %.2f dollars.", numPlants, pricePlant, priceTotal);
  }else{
    printf("Invalid input.");
  }

  return 0;
}
