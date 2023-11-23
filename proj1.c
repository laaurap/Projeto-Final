#include "proj1.h"
#include <stdio.h>
#include <string.h>

void criaTarefa(struct lista *lt) { // FUNÇÃO UTILIZADA PARA CRIAR UMA NOVA TAREFA QUE RECEBE UM PONTEIRO PARA O STRUCT.
    int prioridade, estado;

    do { // SOLICITAÇÃO E VALIDAÇÃO DAMPRIORIDADE DA TAREFA
        printf("DIGITE A PRIORIDADE DA TAREFA (1-10): ");
        scanf("%d", &prioridade);

        if (prioridade < 1 || prioridade > 10) {
            printf("\ERRO: DIGITE UM NUMERO ENTRE 1 E 10\n");
        }
    } while (prioridade < 1 || prioridade > 10);

    printf("ESTADO DA TAREFA (COMPLETO, EM ANDAMENTO, NÃO INICIADO) [0, 1, 2 resopectivamente]: ");
    scanf("%d", &estado);

    lt->prioridade = prioridade;
    lt->status = estado;
    // SOLICITAÇÃO DAS OUTRAS CARACTERÍSTICAS DA TAREFA
    printf("\nDIGITE A CATEGORIA DA TAREFA: ");
    scanf(" %299[^\n]", lt->categoria);
    printf("\nDIGITE A DESCRICAO DA TAREFA: ");
    scanf(" %99[^\n]", lt->descricao);
}

void listaTarefas(int tam, struct lista *lt){ // FUNÇÃO UTILIZADA PARA LISTAR AS TAREFAS
    for(int i = 0; i < tam; i++){
        printf("TAREFA %d\n", i+1);
        printf("PRIORIDADE: %d\n",lt[i].prioridade);
        printf("CATEGORIA: %s\n",lt[i].categoria );
        printf("DESCRICAO: %s\n",lt[i].descricao);
        printf("ESTADO: %s\n\n", status[lt[i].status]);
    }
}

void atualizaTarefa(int tam, struct lista *lista, int index) {
    int prioridade_novo, estado_novo, resposta;

    printf("\nQUAL CAMPO DESEJA ALTERAR? (Prioridade, categoria, descrição, estado) [1, 2, 3, 4, respectivamente]");
    scanf("%d", &resposta);

    switch(resposta) {
    case 1:
        printf("\nDIGITE A PRIORIDADE DA TAREFA (1-10) [novo]: ");
        scanf("%d", &prioridade_novo);
        lista[index - 1].prioridade = prioridade_novo;
        break;
    case 2:
        printf("\nDIGITE A CATEGORIA DA TAREFA [novo]: ");
        scanf(" %299[^\n]", lista[index - 1].categoria);
        break;
    case 3:
        printf("\nDIGITE A DESCRICAO DA TAREFA [novo]: " );
        scanf(" %99[^\n]", lista[index - 1].descricao);
        break;
    case 4:
        printf("\nESTADO DA TAREFA (COMPLETO, EM ANDAMENTO, NÃO INICIADO) [0, 1, 2 respectivamente]: ");
        scanf("%d", &estado_novo);

        lista[index - 1].status = estado_novo;
        break;
    default:
        break;
    }
}

int tamanho(struct lista *lt) { // FUNÇÃO QUE RETORNA O TAMANHO ATUAL DA LISTA DE TAREFAS
    FILE *strArquivo = fopen("ListaDeTarefas", "rb");
    int aux = 0;
    if (strArquivo) {
        // CONTA O NÚMERO DE TAREFAS (STRUCTS) PRESENTES NO ARQUIVO ATRAVÉS DA VARIÁVEL 'aux'
        while (fread(&lt[aux], sizeof(struct lista), 1, strArquivo) == 1) {
            aux++;
        }
        fclose(strArquivo);
    }
    else {
        printf("ARQUIVO NAO ENCONTRADO.");
    }
    return aux;
}

void deletaTarefa(int *tam, struct lista *lt, int posTarefa) { // FUNÇÃO PARA DELETAR UMA TAREFA.
    if (posTarefa < 1 || posTarefa > *tam) { // AQUI É ESCOLHIDA A POSIÇÃO DA TAREFA QUE O USUÁRIO DESEJA DELETAR NO ARRAY DA LISTA
        printf("OPCAO INVALIDA. DIGITE UM NUMERODE 1 A %d.\n", *tam);
        return;
    }

    for (int i = posTarefa - 1; i < *tam - 1; i++) { // SUBSTITUI AS INFORMAÇÕES DAS POSIÇÕES PELA POSIÇÃO SEGUINTE (MOVE AS OUTRAS TAREFAS PARA "TRÁS" PARA PREENCHER O "BURACO"
        lt[i] = lt[i + 1];
    }

    (*tam)--; // DIMINUI O TAMANHO DA LISTA EM 1
    printf("A TAREFA %d FOI DELETADA COM SUCESSO.\n", posTarefa);
}

void filtraPrioridade(int tam, struct lista *lista, int prioridade) {
      for(int i = 0; i < tam; i++){
            if(prioridade==lista[i].prioridade){
                printf("TAREFA %d\n", i+1);
                printf("PRIORIDADE: %d\n",lista[i].prioridade);
                printf("CATEGORIA: %s\n",lista[i].categoria );
                printf("DESCRICAO: %s\n",lista[i].descricao);
                printf("ESTADO: %s\n\n", status[lista[i].status]);
            }
      }
}

void filtraEstado(int tam, struct lista *lista, int estado_indice){
    for(int i = 0; i < tam; i++){
            if(estado_indice==lista[i].status){
                printf("TAREFA %d\n", i+1);
                printf("PRIORIDADE: %d\n",lista[i].prioridade);
                printf("CATEGORIA: %s\n",lista[i].categoria );
                printf("DESCRICAO: %s\n",lista[i].descricao);
                printf("ESTADO: %s\n\n", status[lista[i].status]);
            }
      }
}

void salvaTexto(int tam, struct lista *lista, int prioridade) {
    char nome[300];

    printf("Digite o nome do arquivo para salvar (insira '.txt' ao final do nome): ");
    scanf("%s", nome);
    FILE *arquivo = fopen(nome, "w");

    fprintf(arquivo, "\n--- LISTA DE TAREFAS PRIORIDADE: %d", prioridade);
    if(arquivo){
        for(int i = 0; i < tam; i++){
                if(prioridade==lista[i].prioridade){
                    fprintf(arquivo, "\nPRIORIDADE: %d", lista[i].prioridade);
                    fprintf(arquivo, "\nCATEGORIA: %s", lista[i].categoria);
                    fprintf(arquivo, "\nESTADO: %s", status[lista[i].status]);
                    fprintf(arquivo, "\nDESCRIÇÃO: %s", lista[i].descricao);
                    fprintf(arquivo, "\n");
                }
        }

        fclose(arquivo);
    }

}

int compara_sort(const void *a, const void *b) {
    return ((struct lista*)b)->prioridade - ((struct lista*)a)->prioridade;
}

void filtraCategoria(int tam, struct lista *lista, char categoria[300]){
    qsort(lista, tam, sizeof(struct lista), compara_sort);

    for(int i = 0; i < tam; i++){
            if(strcmp(categoria, lista[i].categoria) == 0){
                printf("TAREFA %d\n", i+1);
                printf("PRIORIDADE: %d\n",lista[i].prioridade);
                printf("CATEGORIA: %s\n",lista[i].categoria );
                printf("DESCRICAO: %s\n",lista[i].descricao);
                printf("ESTADO: %s\n\n", status[lista[i].status]);
            }
      }
}

void salvaCategoria(int tam, struct lista *lista, char categoria[300]){
    char nome[300];

    printf("Digite o nome do arquivo para salvar (insira '.txt' ao final do nome): ");
    scanf("%s", nome);
    FILE *arquivo = fopen(nome, "w");

    fprintf(arquivo, "\n--- LISTA DE TAREFAS CATEGORIA: %s\n", categoria);
    if(arquivo){
        qsort(lista, tam, sizeof(struct lista), compara_sort);
         for(int i = 0; i < tam; i++){
            if(strcmp(categoria, lista[i].categoria) == 0){
                fprintf(arquivo, "PRIORIDADE: %d\n",lista[i].prioridade);
                fprintf(arquivo, "CATEGORIA: %s\n",lista[i].categoria );
                fprintf(arquivo, "DESCRICAO: %s\n",lista[i].descricao);
                fprintf(arquivo, "ESTADO: %s\n\n", status[lista[i].status]);
                fprintf(arquivo, "\n");
            }
        }

        fclose(arquivo);
    }
}

void filtraCategoriaPrioridade(int tam, struct lista *lista, int prioridade, char categoria[300]){
    qsort(lista, tam, sizeof(struct lista), compara_sort);

     for(int i = 0; i < tam; i++){

            if((prioridade==lista[i].prioridade) && (strcmp(categoria, lista[i].categoria) == 0)){
                printf("TAREFA %d\n", i+1);
                printf("PRIORIDADE: %d\n",lista[i].prioridade);
                printf("CATEGORIA: %s\n",lista[i].categoria );
                printf("DESCRICAO: %s\n",lista[i].descricao);
                printf("ESTADO: %s\n\n", status[lista[i].status]);
            }
      }

}

void salvaCategoriaPrioeidade(int tam, struct lista *lista, int prioridade, char categoria[300]){
     char nome[300];

    printf("Digite o nome do arquivo para salvar (insira '.txt' ao final do nome): ");
    scanf("%s", nome);
    FILE *arquivo = fopen(nome, "w");

    fprintf(arquivo, "\n--- LISTA DE TAREFAS CATEGORIA E PRIORIDADE: %s\n", categoria);
    if(arquivo){
         qsort(lista, tam, sizeof(struct lista), compara_sort);

         for(int i = 0; i < tam; i++){
                if((prioridade==lista[i].prioridade) && (strcmp(categoria, lista[i].categoria) == 0)){
                    fprintf(arquivo, "PRIORIDADE: %d\n",lista[i].prioridade);
                    fprintf(arquivo, "CATEGORIA: %s\n",lista[i].categoria );
                    fprintf(arquivo, "DESCRICAO: %s\n",lista[i].descricao);
                    fprintf(arquivo, "ESTADO: %s\n\n", status[lista[i].status]);
                    fprintf(arquivo, "\n");
                }
        }

        fclose(arquivo);
    }
}

void salvar(int tam, struct lista *lt) { // FUNÇÃO PARA ESCREVER A LISTA DE TAREFAS NO ARQUIVO.
    FILE *strArquivo= fopen("ListaDeTarefas", "wb");;

    if (strArquivo) {
        // Escreve as tarefas no arquivo
        fwrite(lt, sizeof(struct lista), tam, strArquivo);
    }
    fclose(strArquivo);
}
