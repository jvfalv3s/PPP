#include <stdio.h>
#include "pilha.h"

int main() {
    char original[100] = "PROGRAMACAO";
    char invertida[100];
    
    printf("String original: %s\n", original);
    
    reverse_string(original, invertida, 100);
    
    printf("String invertida: %s\n", invertida);
    
    return 0;
}