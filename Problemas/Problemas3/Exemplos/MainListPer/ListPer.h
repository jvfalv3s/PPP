#define MAX 100

struct person {
    char name[MAX];
    int age;
};

struct list_node {
    struct person per;
    struct list_node * next;
};

struct list_node_2 {
    struct list_node * p_list_node;
    struct list_node_2 * next;
};

struct list_node * create(void) ;

int empty(struct list_node * list);

struct list_node * clean(struct list_node * list);

// Assumes the list is sorted by name
void search(struct list_node * list, char * key, struct list_node ** previous, struct list_node ** current);

void delete(struct list_node * list, char * key);

// Assumes the list is sorted by name and cannot handle duplicate names
void insert(struct list_node * list, struct person p1) ;

void print_person(struct person p);

void print(struct list_node * list);

//Second list

struct list_node_2 * create_2(struct list_node *l) ;

int empty_2(struct list_node_2 * list);

struct list_node_2 * clean_2(struct list_node_2 * list);

void search_2(struct list_node_2 * list, int key, struct list_node_2 ** previous, struct list_node_2 ** current);

void insert_2(struct list_node_2 * list, struct list_node *l) ;

void preenche_2 (struct list_node_2 * list, struct list_node *l);

void print_2(struct list_node_2 * list);