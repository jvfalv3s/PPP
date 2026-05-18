#include <stdio.h>

#include "ficheiros.h"

int main(void)
{
    char letra;

    printf("Que letra deseja consultar? ");
    if (scanf(" %c", &letra) != 1) {
        return 1;
    }


    return 0;
}
