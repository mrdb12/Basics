#include <stdio.h>
#include <stdlib.h>

struct letter{
  char letter;
  struct letter *next;
};

struct letter * append(struct letter *end, struct letter *new);
struct letter * createLetter(char letter);
struct letter * delete(struct letter *start, int pos);
void printLetters (struct letter *start);
struct letter * readletters(void);
void freeLetters(struct letter *start);
void changeLetter(struct letter *start, int pos, char newChar);
struct letter * insertIntoSorted(struct letter *sortedStart, struct letter *newLetter);
struct letter * sortedCopy(struct letter *start);
int countSpecLetter(struct letter *start, char c);


int main(void){
  struct letter *start, *end, *sortedStart;
  int num = 0;
  start = readletters();
  printLetters(start);
  changeLetter(start, 1, 'x');
  printLetters(start);

  sortedStart = sortedCopy(start);
  printLetters(sortedStart);

  num = countSpecLetter(start, 'a');
  printf("\n The letter 'a' is present %d times in the linked list.", num);

  freeLetters(sortedStart);
  freeLetters(start);

  return 0;
}

struct letter * append(struct letter *end, struct letter *new){
  end->next = new;
  return new; //returns new end
}

struct letter * createLetter(char letter){
  struct letter *newletter =(struct letter *) malloc(sizeof(struct letter));
  int i;
  newletter->letter = letter;
  newletter->next = NULL;

  return newletter;
}

struct letter * delete(struct letter *start, int pos){ //deletes the node at a certain position
  struct letter *ptr = start;
  struct letter *prev;
  int i;

  for(i=1; i<pos; i++){
    prev = ptr;
    ptr = ptr->next;
  }

  prev->next = ptr->next;
  free(ptr);

  ptr = start;
  while(ptr->next != NULL){
    ptr = ptr->next;
  }
  return ptr; //returns new end
}

void printLetters (struct letter *start){
  struct letter *ptr = start;

  while(ptr != NULL){
    printf("%c", ptr->letter);
    ptr = ptr->next;
  }
}

struct letter * readletters(void){
  struct letter *start, *end, *newletter;

  start = NULL;
  char c = 'p';
  while(c != '\n'){
    scanf("%c", &c);
    newletter = createLetter(c);
    if(start == NULL){
      start = end = newletter;
    }else{
      end = append(end, newletter);
    }
  }

  return start;
}

void freeLetters(struct letter *start){
  struct letter *ptr, *next;
  ptr = next = start;

  while(ptr != NULL){
    ptr = next;
    next = ptr->next;
    free(ptr);
  }
}

void changeLetter(struct letter *start, int pos, char newChar){
  int i;

  for(i=1; i<pos; i++){
    start = start->next;
  }
  start->letter = newChar;
}

struct letter * insertIntoSorted(struct letter *sortedStart, struct letter *newLetter){
  struct letter *ptr = sortedStart;
  struct letter *prev = NULL;

  while(ptr != NULL && ptr->letter < newLetter->letter){
    prev = ptr;
    ptr = ptr->next;
  }
  if(prev == NULL){
    newLetter->next = sortedStart;
    sortedStart = newLetter;
  }else{
    prev->next = newLetter;
    newLetter->next = ptr;
  }

  return sortedStart;
}

struct letter * sortedCopy(struct letter *start){
  struct letter *ptr = start;
  struct letter *newLetter;
  struct letter *sortedStart = NULL;

  while(ptr->next != NULL){
    newLetter = createLetter(ptr->letter);

    if(sortedStart == NULL){
      sortedStart = newLetter;
    }else{
      sortedStart = insertIntoSorted(sortedStart, newLetter);
    }
    ptr = ptr->next;
  }

  return sortedStart;
}

int countSpecLetter(struct letter *start, char c){
  int num = 0;
  struct letter *ptr = start;

  while(ptr != NULL){
    if(ptr->letter == c) num+=1;

    ptr = ptr->next;
  }

  return num;
}
