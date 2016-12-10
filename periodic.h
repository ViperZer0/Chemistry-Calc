#ifndef PERIODIC_H_INCLUDED
#define PERIODIC_H_INCLUDED
/*Contents of periodic.h:
 *1)Constant definitions
 *2)Type definitions
 *3)Global variables
 *4)Function prototypes
 */
#define num_elements 118

#include <stdio.h>

struct periodic  //Create a structure designed to create a model of the periodic table
{
    int num;
    char sym[3]; //Symbol of Element
    char name[20]; //Name of Element
    float weight; //Atomic Mass
    char config[100]; //Configuration
    float neg; //Electronegativity
    int rad; //Radius
    float ion_rad; //Ion Radius
    int vdW_rad; //Van der Waals radius
    int IE_1; //IE-1
    int EA; //EA
    char oxi_st[40];//Oxidation states
    char stn_st[7];//Standard state
    char bond_type[17];//Bonding type
    int melt; //Melting point
    int boil; //Boiling point
    float dens; //Density
    char type[40]; //Metal or nonmetal
    char year[7]; //Year Discovered

};


//Buncha Declarations. Hold onto your butts.
struct periodic * createTable();
void displayData(struct periodic *table);
int searchTable(int mode, char input[20], struct periodic *table);
char *strsep(char **stringp, const char *delim);
int * equToMatrix(int *rows, int *columns, char *input);
int countElements(char *tempInput, char *elemOrder);
int * parseEq(char *input, int rows, int columns);
void flush();
void displayMatrix(int *matPtr,int rows, int columns, char *elemOrder);
void displayFMatrix(float *matPtr, int rows, int columns, char *elemOrder);
void swapR(float *matPtr, int cols, int src, int dest, char *elemOrder);
void mulR(float *matPtr, int cols, int src, int factor);
int getPos(int rows, int columns, int i, int j);

#endif // PERIODIC_H_INCLUDED
