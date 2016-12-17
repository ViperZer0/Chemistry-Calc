/*Name: rowOp.c
 *Contains: swapR(), mulR(), addR()
 *Description: Some generic row operation functions for the float matrix that will be solved.
 */

#include "main.h"
#include <stdlib.h>

void swapR(float *matPtr,int cols, int src, int dest, char *elemOrder){
	int *tempRow = (int*)calloc(cols,sizeof(int)); //Make a temp row to store numbers in
	int i,count;
	char tempChar;
	for(i=0;i<3;i++){
		tempChar=elemOrder[3*src+i];
		elemOrder[3*src+i]=elemOrder[3*dest+i];
		elemOrder[3*dest+i]=tempChar;
	}

	for(i=0;i<cols;i++){
		tempRow[i]= *(matPtr+(dest*cols+i));
		*(matPtr+(dest*cols+i))=*(matPtr+(src*cols+i));
		*(matPtr+(src*cols+i))=tempRow[i];
	}
	free(tempRow);
}

void mulR(float *matPtr, int cols, int src, int factor){
	int i;
	for(i=0;i<cols;i++){
		*(matPtr+(src*cols+i))=*(matPtr+(src*cols+i))*factor;
	}
}

void addR(float *matPtr, int cols, int src, int dest, int factor){
	int i;
	for(i=0;i<cols;i++){
		*(matPtr+(dest*cols+i))=*(matPtr+(dest*cols+i))+(*(matPtr+(src*cols+i))*factor);
	}

}
