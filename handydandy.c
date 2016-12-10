#include "periodic.h"

int searchStr(char *input, char key){
    int position;
    while(input!='\0'){
        if(input==key)return position;
        else{
            input++;
            position++;
        }
    }
    return -1;
}
