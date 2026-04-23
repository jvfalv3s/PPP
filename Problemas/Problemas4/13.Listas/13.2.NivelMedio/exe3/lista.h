#ifndef LISTA_H
#define LISTA_H

struct element {
    int value;
};

struct list_node {
    struct element data;
    struct list_node *next;
};

struct list_node *create(void);
int empty(struct list_node *list);
void insert(struct list_node *list, struct element e);
void print_list(const struct list_node *list);
struct list_node *clean(struct list_node *list);

// 13.2.3 específico
int contains(const struct list_node *list, int value);
struct list_node *difference(const struct list_node *l1, const struct list_node *l2);

#endif