#include <stdio.h>
#include "PilhaPer.h" 

int main() {
    struct person ps[] = {
        {"Raquel", 21},
        {"Leonardo", 19},
        {"Andre", 40},
        {"Sandra", 38}
    };
    struct stack_node * pstack;

    create(&pstack);
    for (unsigned int i = 0; i < sizeof(ps) / sizeof(ps[0]); i++) {
        if (!push(&pstack, ps[i])) {
            perror("Cannot push person to stack");
            return 1;
        }
    }

    printf("Initial stack:\n");
    print_stack(pstack);

    printf("\nPop():\n");
    struct person  per = pop(&pstack);
    if (per.age != -1)
        print_person(per);

    printf("\nStack Size: %d\n", size(pstack));
    
    printf("\nAfter clean:\n");
    clean(&pstack);
    print_stack(pstack);

    return 0;
}
