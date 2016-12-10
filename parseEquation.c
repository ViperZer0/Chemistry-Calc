#include <string.h>
#include "periodic.h"

/*Parses a string that contains a chemical equation and turns it into a matrix system of equations.
 *int *rows is a pointer. This pointer will contain the number of rows and can be referenced by other things. Same with *pointer
 *char *input is the string containing the chemical equation
 *returns a pointer to the matrix itself

 *The string will have the following format.
 *Hopefully, there will be no coefficents. Hopefully.
 *+ will separate chemicals, plus possibly spaces.
 *= will separate products from reactants.
 */

int countElements(char *tempInput, char *elemOrder){
    int numElem=0;
    int i,j=0,occur,big_Ol_Index=0,index=0;
    char tempStr[3] ="";
    char numStr[10] =""; //Why anyone would have so many chemicals is beyond me.
    char cToStr[2]="0\0"; //DON'T... STOP... BELIEVING!
    char curChar = tempInput[0];

    while(tempInput[big_Ol_Index]){
        if(curChar=='\n')break; //This is definitely the end.
        if(curChar=='+'||curChar=='='){big_Ol_Index++;index=big_Ol_Index;curChar=tempInput[index];continue;}//Big difference between break and continue, apparently. TIL.
        if(curChar==' '){big_Ol_Index++;index=big_Ol_Index;curChar=tempInput[index];continue;}

        curChar = tempInput[index];//We know the first character will always be a capital. NO WAIT WE DONT!
        cToStr[0]=curChar;
        strcat(tempStr,cToStr);
        tempInput[index]=' ';
        index++;
        curChar = tempInput[index];

        while(curChar>=97&&curChar<=122){//Find the rest of the element
            cToStr[0]=curChar;
            strcat(tempStr,cToStr);
            tempInput[index]=' ';
            index++;
            curChar = tempInput[index];
        }

        strcat(elemOrder,tempStr);//Append the element to the thing
        for(i=0;i<3-strlen(tempStr);i++)strcat(elemOrder," ");

        while(curChar>=48&&curChar<=57){//Is first element followed by a number?
            cToStr[0]=curChar;
            strcat(numStr,cToStr);
            tempInput[index]=' ';
            index++;
            curChar=tempInput[index];
        }

        //We have an element. Count number of different elements
        numElem++;
        for(i=0;i<=9;i++)numStr[i]='\0';

        big_Ol_Index=index; //REMEMBER WHERE WE LEFT OFF

        //Now lets find all other occurrences of that element.
        char checkStr[4] = "0\0\0\0";
        int numdex;
        for(i=index;i<(strlen(tempInput)-strlen(tempStr));i++){
            for(j=0;j<strlen(tempStr);j++){
                checkStr[j]=tempInput[i+j];
            }

            if(strcmp(checkStr,tempStr)==0){
                for(j=0;j<strlen(tempStr);j++){
                    tempInput[i+j]=' ';
                }
                numdex=i+j;
                while(tempInput[numdex]>=48&&tempInput[numdex]<=57){
                    cToStr[0]=tempInput[numdex];
                    strcat(numStr,cToStr);
                    tempInput[numdex]=' ';
                    numdex++;
                }
            }
            for(j=0;j<3;j++)checkStr[j]='\0';//Screw you, C.
            for(j=0;j<10;j++)numStr[j]='\0'; //;n;
        }
        for(j=0;j<3;j++)tempStr[j]='\0'; //I REALLY hate you, C.
    }
    return numElem;
}

int * parseEq(char *input, int rows, int columns){

    int index=0;//Use this again too
    int i,j=0,count=0,occur,big_Ol_Index=0;
    int curRow=0,curCol=0,permCol=0;
    char tempStr[3] ="";
    char numStr[10] =""; //Why anyone would have so many chemicals is beyond me.
    char cToStr[2]="0\0"; //DON'T... STOP... BELIEVING!
    char curChar = "0\0";

    //Get the matrix ready
    int *matPtr; //HOLY QUACAMOLE.
    matPtr = (int*)calloc(rows*columns,sizeof(int));//Use calloc, and then we don't even need that whole loop thing.

    /*Thing follows this format:
        *1) Find first element
        *2) Find number
        *3) Find other occurrences of element
        *4) Check for number after said elements.
        *5) Repeat for each element!
        */
    while(input[big_Ol_Index]){
        curChar=input[big_Ol_Index];
        if(curChar=='\n')break; //This is definitely the end.
        if(curChar=='+'||curChar=='='){big_Ol_Index++;index=big_Ol_Index;curChar=input[index];permCol++;continue;}//Big difference between break and continue, apparently. TIL.
        if(curChar==' '){big_Ol_Index++;index=big_Ol_Index;curChar=input[index];continue;}
        curChar = input[index];//We know the first character will always be a capital. NO WAIT WE DONT!
        cToStr[0]=curChar;
        strcat(tempStr,cToStr);
        input[index]=' ';
        index++;
        curChar = input[index];

        while(curChar>=97&&curChar<=122){//Find the rest of the element
            cToStr[0]=curChar;
            strcat(tempStr,cToStr);
            input[index]=' ';
            index++;
            curChar = input[index];
        }

        //We have an element. Let's find out how many there are.

        while(curChar>=48&&curChar<=57){//Is first element followed by a number?
            cToStr[0]=curChar;
            strcat(numStr,cToStr);
            input[index]=' ';
            index++;
            curChar=input[index];

        }
        occur=atoi(numStr);

        if(occur==0)occur=1;
        *(matPtr+getPos(rows, columns, curRow, permCol))=occur;

        for(i=0;i<=9;i++)numStr[i]='\0';

        big_Ol_Index=index; //REMEMBER WHERE WE LEFT OFF
        //Now lets find all other occurrences of that element.
        char checkStr[4] = "0\0\0\0";
        int numdex;
        curCol=permCol; //No idea if this is gonna work or not.
        for(i=index;i<(strlen(input)-strlen(tempStr));i++){
            if(input[i]=='+'||input[i]=='='){
                curCol++; //Move over a column each time we hit a + or =
            }
            for(j=0;j<strlen(tempStr);j++){
                checkStr[j]=input[i+j];
            }
            if(strcmp(checkStr,tempStr)==0){
                for(j=0;j<strlen(tempStr);j++){
                    input[i+j]=' ';
                }
                numdex=i+j;
                while(input[numdex]>=48&&input[numdex]<=57){
                    cToStr[0]=input[numdex];
                    strcat(numStr,cToStr);
                    input[numdex]=' ';
                    numdex++;
                }

                occur=atoi(numStr);
                if(occur==0)occur=1;
                *(matPtr+getPos(rows, columns, curRow, curCol))=occur;

            }

            for(j=0;j<3;j++)checkStr[j]='\0';//Screw you, C.

            for(j=0;j<10;j++)numStr[j]='\0'; //;n;
        }
        for(j=0;j<3;j++)tempStr[j]='\0'; //I REALLY hate you, C.

        curRow++; //Move on to the next element
        curCol = 0; //Reset current column.
    }
    return matPtr;
}




