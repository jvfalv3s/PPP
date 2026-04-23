#include <stdio.h>
#include "lista.h"

int main() {
    struct list_node *l1 = create();
    struct list_node *l2 = create();
    struct list_node *diff;
    
    // L1: 1, 3, 5, 7
    insert(l1, (struct element){.value = 1});
    insert(l1, (struct element){.value = 3});
    insert(l1, (struct element){.value = 5});
    insert(l1, (struct element){.value = 7});
    
    // L2: 3, 5, 8, 9
    insert(l2, (struct element){.value = 3});
    insert(l2, (struct element){.value = 5});
    insert(l2, (struct element){.value = 8});
    insert(l2, (struct element){.value = 9});
    
    printf("Lista 1: "); print_list(l1);
    printf("Lista 2: "); print_list(l2);
    
    diff = difference(l1, l2);
    printf("Diferença (L1 U L2 - L1 ∩ L2): "); print_list(diff);
    
    l1 = clean(l1);
    l2 = clean(l2);
    diff = clean(diff);
    
    return 0;
}