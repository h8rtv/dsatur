#include "main.h"

/* Testa as cores dos nós */
void test_dsatur (Grafo* grafo){
    printf("Começo do teste\n");
    for(int i = 0; i < grafo->v; i++){
        No* node = grafo->adj[i];
        while (node != NULL){
            if(grafo->color[i] != grafo->color[node->id]){
                printf("[Test Fail] ID 1: %d, ID 2: %d, Cor: %d\n", grafo->adj[i]->id, node->id, grafo->color[grafo->adj[i]->id]);
            }
            node = node->next;
        }
    }
    printf("Fim do teste\n");
}