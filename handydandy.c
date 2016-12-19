#include "main.h"
#include <stdio.h>
void flush(){
	char c;
	while((c = getchar()) != '\n' && c != '\0')
		/* discard */ ;
}

void displayMatrix(int *matPtr, int rows, int columns, char *elemOrder){
	int index=0,i,j;
	for(i=0;i<rows;i++){
		for(j=0;j<3;j++){
			printf("%c",elemOrder[index]);
			index++;
		}
		printf(":\t");
		for(j=0;j<columns;j++){
			printf("%d\t",*(matPtr+(i*columns)+j));
		}
		printf("\n");
	}
}

void displayFMatrix(float *matPtr, int rows, int columns, char *elemOrder){
	int index=0,i,j;
	for(i=0;i<rows;i++){
		for(j=0;j<3;j++){
			printf("%c",elemOrder[index]);
			index++;
		}
		printf(":\t");
		for(j=0;j<columns;j++){
			printf("%f\t",*(matPtr+(i*columns)+j));
		}
		printf("\n");
	}
}

int getPos(int rows, int columns, int i, int j){
	return i*columns+j;
}
