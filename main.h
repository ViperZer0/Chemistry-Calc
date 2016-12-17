#ifndef PERIODIC_H_INCLUDED
#define PERIODIC_H_INCLUDED
/*Contents of main.h:
 *1)Inclusions
 *2)Constant definitions
 *3)Type definitions
 *4)Function prototypes
 */

//Inclusions
#include <stdio.h>

//Constant Defintions
#define num_elements 118

//Type Definitions
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

/*Name: createTable()
 *Location: createTable.c 
 *Inputs: None
 *Outputs: A pointer to the first struct in an array of structures. Each structure is an element and its properties.
 
 *Description:Parses the file periodictable.csv in order to get all the properties of each element. Runs on program launch
 *and hopefully should not need to be called again. Format is as followed:
 *Number, Symbol
 *Name, Weight
 *Electron Config., Negativity
 *Radius, Ion Radius
 *van der Waals Radius, IE_1
 *EA, Oxidation States
 *Standard State, Bond Type
 *Melting Point, Boiling Point
 *Density, Type
 *Year
 ***TRY TO KEEP ALL REFRENCES TO THESE VALUES IN THESE TWO LINE GROUPS.***
 */ 
struct periodic * createTable();


/*Name: displayData()
 *Location: displayData.c
 *Description: Prints all the information regarding an element to the screen. It's worth nothing that in this specific case,
 *the rule about two per line is ignored simply due to the length of the lines, and readability. 
 *Inputs: struct periodic *element -- Pointer to the structure for any given element 
 *Outputs: None
 */
void displayData(struct periodic *element);


/*Name: searchTable()
 *Location: searchTable.c 
 *Description: Searches the array of structures for a matching element based on number, symbol or name.
 *Inputs: int mode -- Search by number, symbol, or name
 *        char input[20] -- Input string
 *        struct periodic *table -- Pointer to the start of periodic table array
 * 
 *Outputs: Index of correct element
 */
int searchTable(int mode, char input[20], struct periodic *table);

/*Name: countElements()
 *Location: parseEq.c
 *Description: Counts the number of elements in an equation before any parsing actually takes place. The function actually looks a LOT like parseEq, because it works the exact same way.
 *Inputs: char *tempInput -- The equation to be counted
 *        char *elemOrder -- A pointer to the order in which elemments are listed.
 *Outputs: The number of elements in the equation
 */
int countElements(char *tempInput, char *elemOrder);

/*Name: parseEq()
 *Location: parseEq.c
 *Description: Parses a chemical equation and creates a matrix for further calculating/solving.
 *Inputs: char *input -- The equation to be parsed
 *        int rows -- The number of rows
 *        int columns -- The number of columns
 *Outputs: A pointer to the matrix 
 */
int * parseEq(char *input, int rows, int columns);

/*Name: flush()
 *Location: main.c
 *Description: Flushes STDIN
 *Inputs: None
 *Outputs: None
 */
void flush();

/*Name: displayMatrix()
 *Location: main.c
 *Description: Displays a matrix
 *Inputs: int *matPtr -- Pointer to the start of the array
 *        int rows -- Number of rows in the matrix
 *        int columns -- Number of columns in the matrix
 *        char *elemOrder -- A char array that associates each row with an element
 *Outputs: None
 */ 
void displayMatrix(int *matPtr,int rows, int columns, char *elemOrder);

/*Name: displayFMatrix()
 *Location: main.c
 *Description: Displays a FLOAT matrix
 *Inputs: float *matPtr -- Pointer to the start of the FLOAT array
 *        int rows -- Number of rows in the matrix
 *        int columns -- Number of columns in the matrix
 *        char *elemOrder -- A char array that associates each row with an element
 *Outputs: None
 */ 
void displayFMatrix(float *matPtr, int rows, int columns, char *elemOrder);

/*Name: swapR()
 *Location: rowOp.c
 *Description: Swaps two rows in a matrix
 *Inputs: float *matPtr -- Pointer to the start of the FLOAt array
 *        int cols -- Number of columns
 *        int src -- Index of source row
 *        int dest -- Index of destination row
 *        char *elemOrder -- Char array that associates each row with an element
 *Outputs: None
 */ 
void swapR(float *matPtr, int cols, int src, int dest, char *elemOrder);

/*Name: mulR()
 *Location: rowOp.c
 *Description: Multiplies a row by a constant. 
 *Inputs: float *matPtr -- You've probably heard this one before.
 *        int cols -- Number of columns
 *        int src -- Source row
 *        int factor -- Number to multiply by
 *Outputs: None
 */ 
void mulR(float *matPtr, int cols, int src, int factor);

/*Name: addR()
 *Location: rowOp.c
 *Description: Adds a row to another row, optionally multiplying by a factor
 *Inputs: float *matPtr -- I have no idea /s
 *        int cols -- Number of coumns
 *        int src -- Source Row
 *        int desc -- Destination Row
 *        int factor -- Number to multiply the source row by.
 *Outputs: None
 */
void addR(float *matPtr, int cols, int src, int dest, int factor);

/*Name: getPos()
 *Location: main.c
 *Description: Turns a (x,y) coordinate into a single index. Essentially matrix -> array
 *Inputs: int rows -- Number of rows
 *        int columns -- Number of columns
 *        int i -- x coordinate
 *        int j -- y coordinates
 *Outputs: Array index
 */
int getPos(int rows, int columns, int i, int j);

#endif // PERIODIC_H_INCLUDED
