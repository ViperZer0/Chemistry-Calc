/*Name: displayData.c
 *Contains: displayData()
 *General Description: Displays all the relevant data about a given element.
 */
 
#include "periodic.h"

void displayData(struct periodic *element){ //Display all the facts about an element!
	printf("Atomic Number: %d\n",element->num);
	printf("Atomic Symbol: %s\n",element->sym);
	printf("Element Name: %s\n",element->name);
	printf("Atomic Weight: %f au(g/mol)\n",element->weight);
	printf("Electronic Configuration: %s\n",element->config);
	printf("Electron Negativity: %.2f Paulings\n",element->neg);
	printf("Atomic Radius: %d pm\n ",element->rad);
	printf("Ion Radius: %f pm\n",element->ion_rad);
	printf("Van der Waals Radius: %d pm\n",element->vdW_rad);
	printf("Ionization Energy: %d kJ/mol\n",element->IE_1);
	printf("Electron affinity %d kJ/mol\n",element->EA);
	printf("Oxidation states: %s\n",element->oxi_st);
	printf("Standard state: %s\n",element->stn_st);
	printf("Bond Type: %s\n",element->bond_type);
	printf("Melting Point: %d K\n",element->melt);
	printf("Boiling Point: %d K\n",element->boil);
	printf("Density: %f g/mL\n",element->dens);
	printf("Type: %s\n",element->type);
	printf("Year Discovered: %s\n",element->year);
}
