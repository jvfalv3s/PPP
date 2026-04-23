#ifndef LISTA_H
#define LISTA_H

#define MAX_NAME 50
#define MAX_PHONE 20

struct contact {
    char name[MAX_NAME];
    char phone[MAX_PHONE];
};

struct list_node {
    struct contact data;
    struct list_node *next;
};

struct list_node *create(void);
int empty(struct list_node *list);
void insert(struct list_node *list, struct contact c);
void delete(struct list_node *list, const char *name);
int search(struct list_node *list, const char *name, struct contact *result);
void print_contact(struct contact c);
void print_list(struct list_node *list);
struct list_node *clean(struct list_node *list);

#endif