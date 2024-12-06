#include <stdio.h>
#include "cofo.h"
#define FALSE 0
#define TRUE 1


int main() {
    // Cria um cofo com capacidade para 5 itens
    Cofo *cofo = cofCreate(5);
    
    if (cofo == NULL) {
        printf("Erro ao criar o cofo!\n");
        return 1;
    }

    // Inserir itens no cofo
    printf("Inserindo itens no cofo...\n");
    for (int i = 1; i <= 5; i++) {
        if (cofInsert(cofo, i)) {
            printf("Item %d inserido no cofo.\n", i);
        } else {
            printf("Erro ao inserir o item %d no cofo.\n", i);
        }
    }

    // Consultar se um item está no cofo
    printf("Consultando se o item 3 está no cofo...\n");
    if (cofQuery(cofo, 3)) {
        printf("Item 3 encontrado no cofo.\n");
    } else {
        printf("Item 3 não encontrado no cofo.\n");
    }

    // Remover um item do cofo
    printf("Removendo o item 3 do cofo...\n");
    int removedItem = cofRemove(cofo, 3);
    if (removedItem != FALSE) {
        printf("Item %d removido do cofo.\n", removedItem);
    } else {
        printf("Erro ao remover o item 3 do cofo.\n");
    }

    // Consultar se o item 3 ainda está no cofo
    printf("Consultando novamente se o item 3 está no cofo...\n");
    if (cofQuery(cofo, 3)) {
        printf("Item 3 encontrado no cofo.\n");
    } else {
        printf("Item 3 não encontrado no cofo.\n");
    }

    // Destruir o cofo e liberar a memória
    if (cofDestroy(cofo)) {
        printf("Cofo destruído com sucesso.\n");
    } else {
        printf("Erro ao destruir o cofo.\n");
    }

    return 0;
}
