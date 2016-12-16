/*Name: createTable.c
 *Contains: createTable()
 *General Description: Functions relating to the creation of the periodic table
 *Notes: 

 ***12/15/2016***
Somehow we are getting a totally empty periodic table later on in the program. This function is PROBABLY the cause of it. It may be a Win-to-Linux issue, or it could be something
that's just gone unnoticed for a while. If you're wondering why on earth NOTHING in the program is working, THIS IS WHY. THERE IS NO PERIODIC TABLE. Actually, there is, but it's all zeros. 
Check the bookmark (//ISSUE) for a possible source of this issue.
 */ 
 

#include "periodic.h"
#include <stdio.h>
#include <stdlib.h>
struct periodic *createTable(){

	char format[] ="%d\t%3s\t" //This is the format code.
		"%20s\t%f\t"
		"%100[^\t]\t%f\t"
		"%d\t%f\t"
		"%d\t%d\t"
		"%d\t%40[^\t]\t"
		"%7s\t%17[^\t]\t"
		"%d\t%d\t"
		"%f\t%40[^\t]\t"
		"%7s\n";

	struct periodic *tablePtr = malloc(sizeof(*tablePtr)*num_elements); //Create a new array of structures
	FILE *fp;
	fp = fopen("periodictable.csv","r"); 
	char buff[200];
	char strcopy[220];//Extended to hold all of buff plus extra zeros.
	struct periodic * const initPtr = tablePtr; //Remember where the array starts!
	int i,j, o;
	for(i=0;i<num_elements;i++){//Repeat for all the elements of the periodic table.
		if(fgets(buff,200,fp)){
			o=1;//Move all the characters from buff into strcopy, inserting a 0 between two consecutive tabs (\t\t) //ISSUE
			for(j = 0; j < 200; j++){
				if (j > 0){
					if (buff[j] == '\t' && buff[j-1] == '\t' ){
						strcopy[j+o] = '0';
						o++;
					}
				}
				strcopy[j+o] = buff[j];
			}

			sscanf(strcopy,format,&(tablePtr->num),&(tablePtr->sym),
					&(tablePtr->name),&(tablePtr->weight),
					&(tablePtr->config),&(tablePtr->neg),
					&(tablePtr->rad),&(tablePtr->ion_rad),
					&(tablePtr->vdW_rad),&(tablePtr->IE_1),
					&(tablePtr->EA),&(tablePtr->oxi_st),
					&(tablePtr->stn_st),&(tablePtr->bond_type),
					&(tablePtr->melt),&(tablePtr->boil),
					&(tablePtr->dens),&(tablePtr->type),
					&(tablePtr->year)
			      );
			tablePtr++;
		}
	}
	return initPtr;
}
