#include <stdio.h>
#include "ListPer.h" 

int main() {
    struct person ps[] = {
        {"Raquel", 21},
        {"Leonardo", 19},
        {"Andre", 40},
        {"Sandra", 38}
    };
    struct list_node * plista;
    struct list_node_2 * plista_2;

    plista = create();
    plista_2 = create_2(plista);

    for (unsigned int i = 0; i < sizeof(ps) / sizeof(ps[0]); i++) {
        insert(plista, ps[i]);
    }
 
    printf("\nInitial list:\n");
    print (plista);

    printf("\nDelete():\n");
   
    delete (plista, "Sandra");

    print(plista);
    printf("\nPreenche_2():\n");
    preenche_2 (plista_2, plista);
    print_2 (plista_2);
    
    printf("\nAfter clean:\n");
    plista_2 = clean_2(plista_2);
    plista = clean(plista);
    if (plista) print(plista);
    return 0;
}