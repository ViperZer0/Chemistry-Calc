#include <stdio.h>
#include "periodic.h"
#include <stdlib.h>
#include <string.h>

int main()
{
	struct periodic *tablePtr;

	tablePtr = createTable();
	int i;
	for(i=0;i<num_elements;i++){
		displayData(tablePtr+i);	
	}
	
	printf("INFORMATION SHUTFF HERE\n");
	printf("(1)-View information about an element.\n");
	printf("(2)-Balance a chemical equation.\n");
	printf("(0)-Exit.\n");
	int num;
	printf("Enter your answer:");
	scanf("%d",&num); //Whitespace is removed automagically
	if(num==1){ //View Information about an element.
		printf("Please enter the element number, symbol, or name:");
		char input[20]="";
		scanf("%20s",input);
		printf("%s",input);	
		printf("\n");
		int ret = defInput(input);
		int index;
		if(ret==0){
			index=atoi(input)-1;
		}else if(ret==1){
			index=searchTable(0,input,tablePtr); //The mode from defInput() turns into a zero here. It does NOT stay a one.
		}
		else if(ret==2){
			index=searchTable(1,input,tablePtr);
		}
		if(index==-1)printf("Invalid element number, symbol, or name.");
		else displayData(tablePtr+index);

	}
	if(num==2){//Balance a chemical equation.
		//Documentation
		printf("Please enter the equation to be parsed.\n");
		printf("Be sure the first letter of every element is capitalized.\n");
		printf("Do not use spaces, and use an equals sign (=) in place of an arrow\n");
		printf("This program also does not yet support parentheses, as in (HO)2. Instead, expand and type H2O2.\n");

		//Get the string from the user and reallocate memory block accordingly.
		char *equation=malloc(500);
		flush();
		fgets(equation,500,stdin);
		equation=(char*)realloc(equation,strlen(equation)*sizeof(char)+1);

		int rows,columns=1,index=0;
		char curChar;

		//Count number of columns
		do{
			curChar=equation[index];
			if(curChar=='+'||curChar=='=')columns++;
			index++;
		}
		while(curChar!='\0');

		char *tempStr;
		tempStr = malloc(strlen(equation)*sizeof(char)+1);
		strcpy(tempStr,equation);

		char *elemOrder;
		elemOrder=(char*)calloc(strlen(equation)*3,sizeof(char));//Just to be safe and all that goodstuff.
		rows = countElements(tempStr,elemOrder);
		free(tempStr);
		int *mtxPtr = parseEq(equation,rows,columns);
		displayMatrix(mtxPtr,rows,columns,elemOrder);
		solveMat(mtxPtr,rows,columns,elemOrder);
		//displayMatrix(mtxPtr,rows,columns,elemOrder);

		free(mtxPtr);
		free(elemOrder);
		free(equation);
	}
	free(tablePtr);

	return 0;
}

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

