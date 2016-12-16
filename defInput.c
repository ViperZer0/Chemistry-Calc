/*Name: defInput.c
 *Contains: defInput()
 *General Description: Functions relating to determining the type of input
 *
 *--defInput()--
 *Inputs:A 20-length char array
 *Outputs: An integer that describes the type of input input[20] is.
 *Description: Determines if the char array is an element number, symbol, or name
 *0 = Number
 *1 = Symbol
 *2 = Name
 *-1 = Error
 */

#include "periodic.h"
#include <stdio.h>
#include <string.h>
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

