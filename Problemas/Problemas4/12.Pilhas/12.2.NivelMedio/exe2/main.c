#include <stdio.h>
#include "pilha.h"

int main() {
    struct stack_node *pilha = NULL;
    
    create(&pilha);
    
    // Empilhar alguns valores
    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);
    
    printf("Pilha inicial: "); print_stack(pilha); printf("\n");
    
    // Testar TOP
    int topo;
    if (top(pilha, &topo)) {
        printf("Topo: %d\n", topo);
    }
    
    // Testar DUPLICATE_TOP
    printf("Após duplicar topo: "); duplicate_top(&pilha); print_stack(pilha); printf("\n");
    
    // Testar SWAP_TOP  
    printf("Após trocar topo: "); swap_top(&pilha); print_stack(pilha); printf("\n");
    
    clean(&pilha);
    return 0;
}