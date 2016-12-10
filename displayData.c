#include "periodic.h"


void displayData(struct periodic *table){ //Display all the facts about an element!
    printf("Atomic Number: %d\n",table->num);
    printf("Atomic Symbol: %s\n",table->sym);
    printf("Element Name: %s\n",table->name);
    printf("Atomic Weight: %f au(g/mol)\n",table->weight);
    printf("Electronic Configuration: %s\n",table->config);
    printf("Electron Negativity: %.2f Paulings\n",table->neg);
    printf("Atomic Radius: %d pm\n ",table->rad);
    printf("Ion Radius: %f pm\n",table->ion_rad);
    printf("Van der Waals Radius: %d pm\n",table->vdW_rad);
    printf("Ionization Energy: %d kJ/mol\n",table->IE_1);
    printf("Electron affinity %d kJ/mol\n",table->EA);
    printf("Oxidation states: %s\n",table->oxi_st);
    printf("Standard state: %s\n",table->stn_st);
    printf("Bond Type: %s\n",table->bond_type);
    printf("Melting Point: %d K\n",table->melt);
    printf("Boiling Point: %d K\n",table->boil);
    printf("Density: %f g/mL\n",table->dens);
    printf("Type: %s\n",table->type);
    printf("Year Discovered: %s\n",table->year);
    }
