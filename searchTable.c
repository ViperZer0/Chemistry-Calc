#include "main.h"
#include <string.h>
/*Name: searchTable.c
 *Contains: searchTable()
 *Description: Searches a table for an element base on element number, symbol, or name
 */
int searchTable(int mode, char input[20],struct periodic *table){
	int i,j;
	char match[20];
	int found=0;

	for(i = 0; input[i]; i++){ //Convert the input string to lowercase
		input[i] = tolower(input[i]);
	}

	for(i=0;i<num_elements;i++){ //Compare the input string to the array.
		if(mode==0) strcpy(match,(table+i)->sym); //If we're checking symbols, copy the symbol of the current element to string match
		else strcpy(match,(table+i)->name); //If not, copy the entire name.
		for(j = 0; match[j]; j++){//Convert either element symbol or name to lowercase.
			match[j] = tolower(match[j]);
		}
		if(strcmp(match,input)==0){//If match and input are the same, we are done.
			found=1;
			break;
		}
	}
	if(found) return i;
	else return -1;
}
