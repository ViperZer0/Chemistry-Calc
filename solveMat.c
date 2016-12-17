/*Name: solveMat.c
 *Contains: solveMat()
 *Description: Solves a matrix (system of linear equations, i.e, chemical equations.)
 *Notes: Does not work yet. Needs revision and a new algorithm.
 */

#include "main.h"
#include <stdlib.h>
float * solveMat(int *matPtr, int rows, int cols, char *elemOrder){
    /*Be sure the first row has a number in the very first column.
    There's gotta be one, and TECHNICALLY, there should be no way that a zero will be in position 0,0 due to parser
    But in case things change in the future, this will fix the matrix.
    */
    int lead=0,curRow=0,curCol=0,i;
	float t;

	//We're gonna copy matPtr into a float matrix
	float *a = malloc(rows*cols*sizeof(float));

	for(i=0;i<rows*cols;i++)*(a+i)=*(matPtr+i);

    for(curRow=0;curRow<rows;i++){
        if(curCol<=lead)continue;
        i=curRow;
        while(*a+getPos(rows,cols,i,lead)==0){
            i++;
            if(rows==i){
                i = curRow;
                lead++;
                if(cols==lead){continue;}
            }
        }
        swapR(a,cols,i,curRow,elemOrder);
        if(*(a+getPos(rows,cols,curRow,lead))!=0){
            mulR(a,cols,curRow,1/(*(a+getPos(rows,cols,curRow,lead))));
        }
        for(i=0;i<rows;i++){
            if(i!=curRow)addR(a,cols,curRow,i,-(*(a+getPos(rows,cols,i,lead))));
        }
        lead++;
    }
    return a;
}
