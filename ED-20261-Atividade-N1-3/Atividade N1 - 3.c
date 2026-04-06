/*----------------------------------------------------------------------------------*/
/*FATEC-Ipiranga                                                                    */        
/*ADS - Estrutura de Dados                                                          */
/*Id da Atividade: N1-3                                                             */
/*Objetivo: Simulador de Calculadora HP12c (Pilha RPN)                              */
/*                                                                                  */
/*Autor: Carolina Gusmão de França                                                           */
/*Data: 04/04/2026                                                                   */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    double valor;
    char comando[10];
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

void push(No **topo, double valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = *topo;
    *topo = novo;
}

double pop(No **topo) {
    if (*topo == NULL) return 0;
    No *aux = *topo;
    double valor = aux->valor;
    *topo = aux->proximo;
    free(aux);
    return valor;
}

void mostrarPilhaRecursiva(No *atual, char letra) {
    if (atual == NULL || letra > 'T') return;
    
    printf("%c: %10.2f\n", letra, atual->valor);
    
    mostrarPilhaRecursiva(atual->proximo, letra + 1); 
}


void enfileirar(Fila *f, char *item) {
    No *novo = (No*) malloc(sizeof(No));
    strcpy(novo->comando, item);
    novo->proximo = NULL;
    if (f->fim == NULL) {
        f->inicio = f->fim = novo;
    } else {
        f->fim->proximo = novo;
        f->fim = novo;
    }
}


void calcular(No **pilha, char op) {
    double x = pop(pilha);
    double y = pop(pilha);
    double resultado = 0;

    if (op == '+') resultado = y + x;
    else if (op == '-') resultado = y - x;
    else if (op == '*') resultado = y * x;
    else if (op == '/') resultado = y / x;

    push(pilha, resultado);
}

int main() {
    No *pilhaHP = NULL;
    Fila entrada;
    entrada.inicio = entrada.fim = NULL;

    char expressao[] = "5 1 2 + 4 * + 3 -";
    printf("Simulador HP12c - Fatec Ipiranga\n");
    printf("Processando: %s\n", expressao);

    char *token = strtok(expressao, " ");
    while (token != NULL) {
        enfileirar(&entrada, token);
        token = strtok(NULL, " ");
    }

    No *atual = entrada.inicio;
    while (atual != NULL) {
        printf("\nEntrada atual: %s\n", atual->comando);
        
        if (strlen(atual->comando) == 1 && strchr("+-*/", atual->comando[0])) {
            calcular(&pilhaHP, atual->comando[0]);
        } else {
            push(&pilhaHP, atof(atual->comando));
        }

        mostrarPilhaRecursiva(pilhaHP, 'X');
        atual = atual->proximo;
    }

    printf("\n O resultado da expressao algebrica e: %.0f\n", pilhaHP->valor);

    return 0;
}
