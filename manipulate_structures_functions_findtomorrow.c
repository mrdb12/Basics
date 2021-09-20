#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

void printDate(struct date);
void readDate(struct date *);
struct date advanceDay(struct date);

int main(void) {
	struct date today, tomorrow;
	readDate(&today);
	printDate(today);
	tomorrow = advanceDay(today);
	printDate(tomorrow);
	return 0;
}

void readDate(struct date *dateptr){
  scanf("%d %d %d", &dateptr->year, &dateptr->month, &dateptr->day);
}


void printDate(struct date date){
  if(date.month/10 == 0) printf("0");
  printf("%d/", date.month);
  if(date.day/10 == 0) printf("0");
  printf("%d/%d\n", date.day, date.year);
}

struct date advanceDay(struct date today){
  struct date tomorrow;
  tomorrow.year = today.year;
  tomorrow.month = today.month;

  if(today.month == 12 && today.day == 31){
    tomorrow.year = today.year + 1;
    tomorrow.month = 1;
    tomorrow.day = 1;
  }
  else if(today.day == 31){
    tomorrow.month = today.month+1;
    tomorrow.day = 1;
  }else if(today.day == 30){
    if(today.month == 4 || today.month == 6 || today.month == 9 || today.month == 11){
      tomorrow.month = today.month+1;
      tomorrow.day = 1;
    } else{
      tomorrow.day = today.day+1;
    }
  }else if(today.month == 2 && today.day == 28){
      tomorrow.month = 3;
      tomorrow.day = 1;
  }else{
    tomorrow.day = today.day+1;
  }

  return tomorrow;
}
