#include <stdio.h>
#include "lista.h"

int main() {
    struct list_node *agenda = create();
    struct contact c;
    
    // Inserir contactos
    strcpy(c.name, "Ana"); strcpy(c.phone, "912345678");
    insert(agenda, c);
    
    strcpy(c.name, "Bruno"); strcpy(c.phone, "923456789");
    insert(agenda, c);
    
    strcpy(c.name, "Carla"); strcpy(c.phone, "934567890");
    insert(agenda, c);
    
    printf("Agenda ordenada:\n");
    print_list(agenda);
    
    // Consultar
    if (search(agenda, "Bruno", &c)) {
        printf("\nBruno encontrado:\n");
        print_contact(c);
    }
    
    // Remover
    delete(agenda, "Ana");
    printf("\nApós remover Ana:\n");
    print_list(agenda);
    
    agenda = clean(agenda);
    return 0;
}