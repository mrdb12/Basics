#include <stdio.h>
#include <stdlib.h>

struct point{
  int x;
  int y;
  struct point* next;
};

struct point* append(struct point*, struct point*);
void printList(struct point*);
void freeList(struct point* );

int main(void){
  int n, i;
  struct point *end, *start, *currentpt;

  scanf("%d", &n);

  for(i=0; i<n; i++){
    currentpt = (struct point*) malloc(sizeof(struct point));
    if(i==0){
      end = start = currentpt;
    }
    scanf("%d %d", &(currentpt->x), &(currentpt->y));
    currentpt->next = NULL;
    end = append(end, currentpt);
  }
  printList(start);
  freeList(start);

  return 0;
}

struct point* append(struct point* end, struct point* newpt){
  end -> next = newpt;
  return(end->next);
}

void printList(struct point* start){
  struct point * ptr;
  ptr = start;

  while (ptr != NULL){
    printf("[%d, %d]\n", ptr->x, ptr->y);
    ptr = ptr->next;
  }
}

void freeList(struct point* start){
  struct point *now = start;
  struct point *next = start->next;
  free(start);
  while(next != NULL){
    now = next;
    next = now->next;
    free(now);
  }
}
