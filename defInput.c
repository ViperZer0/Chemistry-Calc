#include "periodic.h"
#include <stdio.h>

/*This function reads a string and will return a numeric value depending on the type of value it is.
 *0 = Atomic number
 *1 = Atomic Symbol
 *2 = Atomic Name
 *-1 = Error
 */
int defInput(char input[20]){
    int num = atoi(input);
    if(!num){
        if(strlen(input)<=3){
            return 1;
        }
        else if(strlen(input)<=20){
            return 2;
        }
        else
            return -1;
        }
    else return 0;
}

