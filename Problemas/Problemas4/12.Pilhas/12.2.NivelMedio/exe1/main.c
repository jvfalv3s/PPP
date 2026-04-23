#include <stdio.h>
#include "pilha.h"

int main() {
    struct stack_node *pilha = NULL;
    char str[MAX_STR + 1];
    char maior[MAX_STR + 1], menor[MAX_STR + 1];
    
    create(&pilha);
    
    printf("Introduza strings (Enter para terminar):\n");
    while (scanf("%50s", str) == 1) {
        if (push(&pilha, str) == 0) break;
    }
    
    printf("\nPilha completa:\n");
    print_stack(pilha);
    
    printf("\nTotal de strings: %d\n", size_stack(pilha));
    
    if (largest_string(pilha, maior)) {
        printf("Maior string: '%s' (%d chars)\n", maior, (int)strlen(maior));
    }
    
    if (smallest_string(pilha, menor)) {
        printf("Menor string: '%s' (%d chars)\n", menor, (int)strlen(menor));
    }
    
    clean(&pilha);
    return 0;
}