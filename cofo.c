


/*******************************************************
* Arquivo: cofo.c (Implementação)
* Descrição: Tipo abstrato de dados para representar Matrizes de valores reais alocadas
dinamicamente, com dimensões n por m fornecidas em tempo de execução.
* 
* Autor: Caio Bandeira Moreira
* Curso: Estrutura de Dados 1
* Professor: Anselmo Cardoso de Paiva
* Data: Novembro/2024
*******************************************************/


#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    int *item;
    int numItens;
    int maxItens;
} Cofo;

// Função para criar o cofo
Cofo *cofCreate(int maxItems) {
    if (maxItems <= 0) {
        return NULL;
    }

    Cofo *c = (Cofo *)malloc(sizeof(Cofo));
    if (c != NULL) {
        c->item = (int *)malloc(sizeof(int) * maxItems);
        if (c->item != NULL) {
            c->numItens = 0;
            c->maxItens = maxItems;
            return c;
        }
        free(c); // Caso a alocação falhe
    }
    return NULL;
}

// Função para destruir o cofo
int cofDestroy(Cofo *c) {
    if (c != NULL) {
        if (c->numItens == 0) {
            free(c->item);
            free(c);
            return TRUE;
        }
    }
    return FALSE;
}

// Função para inserir um item no cofo
int cofInsert(Cofo *c, int item) {
    if (c != NULL && c->numItens < c->maxItens) {
        c->item[c->numItens] = item;
        c->numItens++;
        return TRUE;
    }
    return FALSE;
}

// Função para consultar se o item está no cofo
int cofQuery(Cofo *c, int key) {
    if (c != NULL && c->numItens > 0) {
        for (int i = 0; i < c->numItens; i++) {
            if (c->item[i] == key) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

// Função para remover um item do cofo
int cofRemove(Cofo *c, int key) {
    if (c != NULL && c->numItens > 0) {
        int i, j;
        for (i = 0; i < c->numItens; i++) {
            if (c->item[i] == key) {
                // Remove o item
                for (j = i; j < c->numItens - 1; j++) {
                    c->item[j] = c->item[j + 1];
                }
                c->numItens--;
                return key; // Retorna o item removido
            }
        }
    }
    return FALSE;
}
