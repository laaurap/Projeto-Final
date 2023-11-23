#ifndef PROJETO_BIBLIOTECA_H
#define PROJETO_BIBLIOTECA_H

char status[3][15] = {"Completo", "Em Andamento", "Não iniciado"};

struct lista{ // DEFINIÇÃO DA STRUCT DA LISTA DE TAREFAS
        int prioridade; //VARIÁVEL QUE VAI ARMAZENAR A PRIORIDADE DA TAREFA (NÚMERO INTEIRO).
        char categoria[300]; //  ARRAY DE CARACTERES QUE VAI ARMAZENAR A CATEGORIA DA TAREFA
        char descricao[100]; // ARRAY DE CARACTERES QUE VAI ARMAZENAR A DESCRIÇÃO DA TAREFA
        int status;         // Corresponde ao indice d array de status
};

void criaTarefa(struct lista *lt);
void listaTarefas(int tam, struct lista *lt);
int tamanho(struct lista *lt);
void salvar(int tam, struct lista *lt);
void salvaTexto(int tam, struct lista *lt, int prioridade);
void deletaTarefa(int *tam, struct lista *lt, int posTarefa);
void atualizaTarefa(int tam, struct lista *lista, int index);
void filtraPrioridade(int tam, struct lista *lista, int prioridade);
void filtraEstado(int tam, struct lista *lista, int estado_indice);
void filtraCategoria(int tam, struct lista *lista, char categoria[300]);
void salvaCategoria(int tam, struct lista *lista, char categoria[300]);
void filtraCategoriaPrioridade(int tam, struct lista *lista, int prioridade, char categoria[300]);
void salvaCategoriaPrioeidade(int tam, struct lista *lista, int prioridade, char categoria[300]);
#endif
