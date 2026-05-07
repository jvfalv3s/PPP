//estruturas de dados para o aluno e para a lista de alunos

// vou ter uma lista de alunos e uma lista de despesas gerais ou uma lista de alunos associado a uma lista de despesas?
//posso usar o mesmo exemplo da questao 13.3.3, uma lista com cada no com varios ponteiros, um para o aluno, outro para a despesa e assim por diante.
#ifndef ALUNO_H
#define ALUNO_H


#define MAX 100

//struct do aluno com alunos  (nome,  data  de nascimento,  curso,  ano,  número,  saldo).
struct aluno{
    char nome[MAX];
    char curso[MAX];
    char data_nascimento[MAX]; //lembrar de especificar o formato de leitura de data
    
    //dados com duvida em tipo.
    char ano;
    char numero;
    float saldo; //excessao a regra do char
    
    //ponteiro para a lista de despesas do aluno
    struct lista_despesas *despesas;
};

//struct da lista de alunos, com um ponteiro para o proximo aluno e um ponteiro para a lista de despesas do aluno
struct lista_alunos{
    struct aluno al;
    struct lista_alunos *next;
};

//struct da despesa (descricao, valor, data, aluno associado) ainda decidindo se vou ter uma lista de despesas ou se vou associar as despess por aluno usando ponteiros

struct despesas{
    float valor;//excessao a regra do char
    char descricao[MAX];
    char data[MAX];
    char id_aluno;//id do aluno associado a despesa, numero do aluno para ser comparado com o numero do aluno na struct aluno
};

//struct da lista de despesas, com um ponteiro para o proximo despesa e um id do aluno associado
struct lista_despesas{
    struct despesas desp;
    struct lista_despesas *next;
};



//prototipos das funcoes:
//create_lista_alunos
struct lista_alunos *create_lista_alunos(void);
//create_lista_despesas
struct lista_despesas *create_lista_despesas(void);
//empty
int empty_alunos(struct lista_alunos *list);
int empty_despesas(struct lista_despesas *list);
//clean
struct lista_alunos *clean_lista_alunos(struct lista_alunos *list);
struct lista_despesas *clean_lista_despesas(struct lista_despesas *list);
//search
void search_alunos(struct lista_alunos *list, char *key, struct lista_alunos **previous,struct lista_alunos **current);
void search_despesas(struct lista_despesas *list, char *key, struct lista_despesas **previous,struct lista_despesas **current);
//delete
void delete_aluno(struct lista_alunos *list, char *key);
void delete_despesa(struct lista_despesas *list, char *key);
//insert
void insert_aluno(struct lista_alunos *list, struct aluno a1);
void insert_despesa(struct lista_despesas *list, struct despesas d1, char *id_aluno);//atentar para qual aluno a despesa esta associada, usar o id_aluno para comparar com o numero do aluno na struct aluno e assim associar a despesa ao aluno correto
//print_aluno
void print_aluno(struct aluno a);
//print_lista_alunos em ordem alfabetica
void print_lista_alunos(struct lista_alunos *list);
//print_despesa_aluno (printar a despesa total de um aluno, total de saldo (saldo inicial - total de despesas))
void print_despesa_aluno(struct aluno a);
//print_lista_despesas_aluno
void print_lista_despesas_aluno(struct lista_despesas *list, char *id_aluno);
//carregar_conta (adicionar saldo a um aluno)
void carregar_conta(struct lista_alunos *list, char *id_aluno, float valor);
//gravar_dados (gravar os dados da lista de alunos e despesas para um ficheiro binario) para proxima semana// to fraco de ficheiros
//abrir ficheiro(com as infos de ambas as listas?) -> ler os dados do ficheiro e carregar para a memoria, vai ser chamada bastante nas funcoes de comparacao


#endif