#include <stdio.h>
#include <stdlib.h>
#include "PilhaPer.h"

void create (struct stack_node ** p) {
    *p = NULL;
}

int empty(const struct stack_node * p) {
    return p == NULL;
}

int push(struct stack_node ** p, struct person per) {
    struct stack_node * pnew = malloc(sizeof(struct stack_node));
    if (pnew != NULL) {
        pnew->per = per;
        pnew->prox = *p;
        *p = pnew;
    }
    return pnew != NULL;
}

struct person pop(struct stack_node ** p) {
    if (*p == NULL)
        return (struct person) {"", -1};
    struct person reply = (*p)->per;
    struct stack_node * tmp = *p;
    *p = (*p)->prox;
    free(tmp);
    return reply;
}

void clean(struct stack_node ** p) {
    while (*p) {
        struct stack_node * tmp = *p;
        *p = (*p)->prox;
        free(tmp);
    }
}

void print_person(struct person p) {
    printf("%s is %d years old\n", p.name, p.age);
};

void print_stack(struct stack_node * p) {
    // p is passed by value, so we are not modifying the original stack
    while (p != NULL) {
        print_person(p->per);
        p = p->prox;
    }
}

int size(const struct stack_node * p) {
    int count = 0;
    while (p) {
        count++;
        p = p->prox;
    }
    return count;
}

