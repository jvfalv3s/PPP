#define MAX_NAME 100

struct person {
    char name[MAX_NAME];
    int age;
};

struct stack_node {
    struct person per;
    struct stack_node * prox;
};

void create (struct stack_node ** p) ;

int empty(const struct stack_node * p) ;

int push(struct stack_node ** p, struct person per) ;

struct person pop(struct stack_node ** p) ;

void clean(struct stack_node ** p) ;

void print_person(struct person p) ;

void print_stack(struct stack_node * p) ;

int size(const struct stack_node * p);
