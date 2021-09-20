#include <stdio.h>
#include "calc_birthyear.h" //using headerfile


int main(void){
    int age = 10;
    printf("%ld\n", sizeof(age));
    printf("%ld\n", sizeof(int));

    age >=18 ? printf("You are an adult\n\n") : printf("You are underage\n\n");

    for(int i = 0; i<=10; i++){
        printf("%u\n", i);
    }

    printf("Your birthyear is %i", calcBirthyear(age)); //using header file

}

/*
Compile in Terminal and run in terminal

cd "path of the folder in which the script is"
gcc "script name" -o "name"
./"name"
*/