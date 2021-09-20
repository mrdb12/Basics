#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

void readDate(struct date *);
void printDate(struct date);

int main(void) {
	struct date today;
	readDate(&today);
	printDate(today);
	return 0;
}

void readDate(struct date *dateptr){
  scanf("%d %d %d", &(*dateptr).year, &(*dateptr).month, &(*dateptr).day); // (*dateptr).month equals dateptr->month
}


void printDate(struct date date){
  if(date.month/10 == 0) printf("0");
  printf("%d/", date.month);
  if(date.day/10 == 0) printf("0");
  printf("%d/%d", date.day, date.year);
}
