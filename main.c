#include <stdio.h>
#include "proj1.c"

struct lista lt[100];

int main() {
    int  auxBool = 0, opcao, tam;
    int index_atualiza, prioridade_filtro, estado_filtro, prioridade_salvar;
    char categoria_filtro[300];
    char categoria_salvar[300];

    // VARIAVEIS PARA O FILTRO DUPLO
    int prioridade_categoria;
    char categoria_prioridade[300];
    char salva_categoria[300];
    int salva_prioridade;

    tam = tamanho(lt); // A VARIÁVEL 'tam' ARMAZENA O TAMANHO (NÚMERO DE TAREFAS) ATUAL DA LISTA.

    printf("LAURA DE SOUZA PARENTE - RA:22.123.033-7\n--- LISTA DE TAREFAS ---\n");

    while (1) {
        printf("\n--- MENU PRINCIPAL ---\n1. CRIAR TAREFA \n2. LISTAR TAREFAS\n3. DELETAR TAREFA \n4. ATUALIZAR TAREFA \n5. FILTRA PRIORIDADE \n6. FILTRA ESTADO \n7. FILTRA CATEGORIA \n8. SALVAR POR PRIORIDADE \n9. SALVAR POR CATEGORIA \n10. FILTRAR CATEGORIA E PRIORIDADE \n11. SALVAR POR CATEGORIA E PRIORIDADE \n0. SAIR\n\nDIGITE A OPCAO DESEJADA:    ");
        scanf("%d", &opcao);

        switch (opcao) {
            case(1):
                if(tam == 100){ // VERIFICA SE A LISTA ESTÁ "CHEIA" (100 TAREFAS) E EXIBE UMA MENSAGEM DE ERRO CASO ESTIVER.
                    printf("LIMITE DE TAREFAS ATINGIDO. DELETE UMA TAREFA PARA CRIAR MAIS.\n");
                }
                printf("\n--- CRIAR TAREFA ---\n");
                criaTarefa(&lt[tam]);
                tam++; // AUMENTA O TAMAHO DA LISTA DE TAREFAS EM 1, POIS FOI REGISTRADA UMA NOVA TAREFA.
                break;
            case(2):
                printf("\n--- LISTAR TAREFAS ---\n");
                listaTarefas(tam, lt);
                break;

            case(3):
                printf("\n--- DELETAR TAREFA ---\n");
                int posTarefa;
                printf("DIGITE A POSICAO DA TAREFA QUE DESEJA DELETAR: ");
                scanf("%d", &posTarefa);
                deletaTarefa(&tam, lt, posTarefa);
                break;
            case 4:
                printf("\n--- ATUALIZAR TAREFA ---\n");
                printf("POSICAO DA TAREFA A SER ALTERADA: ");
                scanf("%d", &index_atualiza);
                atualizaTarefa(tam, lt, index_atualiza);
                break;
            case 5:
                printf("\n--- FILTRA TAREFAS POR PRIORIDADE ---\n");
                printf("NIVEL DE PRIORIDADE: ");
                scanf("%d", &prioridade_filtro);

                filtraPrioridade(tam, lt, prioridade_filtro);

                break;
            case 6:
                printf("\n--- FILTRA TAREFAS POR ESTADO ---\n");
                printf("ESTADO (Completo, Em andamento, Não iniciado) [0, 1, 2 RESPECTIVAMENTE]: ");
                scanf("%d", &estado_filtro);

                filtraEstado(tam, lt, estado_filtro);

                break;

            case 7:
                printf("\n--- FILTRA TAREFAS POR CATEGORIA ---\n");
                printf("CATEGORIA: ");
                scanf("%s", categoria_filtro);

                filtraCategoria(tam,lt, categoria_filtro);

                break;
            case 8:
                printf("\n--- SALVA ARQUIVO POR PRIORIDADE ---\n");
                printf("PRIORIDADE: ");
                scanf("%d", &prioridade_salvar);

                salvaTexto(tam, lt, prioridade_salvar);
                break;

            case 9:
                printf("\n--- SALVA ARQUIVO POR CATEGORIA ---\n");
                printf("CATEGORIA: ");
                scanf("%s", categoria_salvar);

                salvaCategoria(tam, lt, categoria_salvar);
                break;
            case 10:
                printf("\n--- FILTRAR POR CATEGORIA E PRIORIDADE ---\n");
                printf("CATEGORIA: ");
                scanf("%s", categoria_prioridade);
                printf("\nPRIORIDADE: ");
                scanf("%d", &prioridade_categoria);

                filtraCategoriaPrioridade(tam, lt, prioridade_categoria, categoria_prioridade);
                break;
            case 11:
                printf("\n--- SALVAR POR CATEGORIA E PRIORIDADE ---\n");
                printf("CATEGORIA: ");
                scanf("%s", salva_categoria);
                printf("\nPRIORIDADE: ");
                scanf("%d", &salva_prioridade);

                salvaCategoriaPrioeidade(tam, lt, salva_prioridade, salva_categoria);
                break;
            case(0):
                printf("\nVOCE ESCOLHEU SAIR.\n");
                salvar(tam, lt);
                auxBool = 1; // MUDA O VALOR DE 'auxBool' PARA 1 PARA PARAR A ITERAÇÃO DO 'while'
                break;
            default:
                printf("\nOPCAO INVALIDA. DIGITE UM NUMERO VALIDO\n"); // PARA QUALQUER NÚMERO QUE NÃO TENHA UM 'case' EXIBE A MENSAGEM DE OPÇÃO INVÁLIDA
                break;
        }
        if(auxBool) // PARA A ITERAÇÃO DO 'while' SE 'auxBool' FOR IGUAL A 1
            break;
    }
}
