//estruturas de dados para o aluno e para a lista de alunos

// vou ter uma lista de alunos e uma lista de despesas gerais ou uma lista de alunos associado a uma lista de despesas?
//posso usar o mesmo exemplo da questao 13.3.3, uma lista com cada no com varios ponteiros, um para o aluno, outro para a despesa e assim por diante.
#ifndef ALUNO_H
#define ALUNO_H

//struct do aluno com alunos  (nome,  data  de nascimento,  curso,  ano,  número,  saldo).

//struct da despesa (descricao, valor, data, aluno associado) ainda decidindo se vou ter uma lista de despesas ou se vou associar as despess por aluno usando ponteiros

/*

aluno -> aluno -> aluno -> aluno
   |        |      |         |
   V        V      V         V
despesa  despesa  despesa  despesa
    |       |      |         |
    V       V      V         V
despesa  despesa  despesa  despesa

o struct aluno deve ter um "id" para associar as depesas, um ponteiro especifico para uma lista de despesas dele. entao tenho que ter uma lista de despesas, onde cada despesa tem um id do aluno associado.

*/

//struct da lista de alunos, com um ponteiro para o proximo aluno e um ponteiro para a lista de despesas do aluno

//struct da lista de despesas, com um ponteiro para o proximo despesa e um id do aluno associado

#endif
