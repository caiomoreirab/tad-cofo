


/*******************************************************
* Arquivo: matrix.h (Especificações)
* Descrição: Tipo abstrato de dados para representar Matrizes de valores reais alocadas
dinamicamente, com dimensões n por m fornecidas em tempo de execução.
* 
* Autor: Caio Bandeira Moreira
* Curso: Estrutura de Dados 1
* Professor: Anselmo Cardoso de Paiva
* Data: Novembro/2024
*******************************************************/


#ifndef COFO_H
#define COFO_H

// Definição do tipo Cofo
typedef struct {
    int *item;     
    int numItens;   
    int maxItens;   
} Cofo;

// Funções para manipulação do Cofo
Cofo *cofCreate(int maxItems);        // Cria um cofo vazio com capacidade para maxItems
int cofDestroy(Cofo *c);              // Destroi o cofo e libera a memória
int cofInsert(Cofo *c, int item);     // Insere um item no cofo
int cofQuery(Cofo *c, int key);       // Consulta se um item está presente no cofo
int cofRemove(Cofo *c, int key);      // Remove um item do cofo

#endif // COFO_H
