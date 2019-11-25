#ifndef GRAFO_H
#define GRAFO_H

/* Nó da lista encadeada */
typedef struct _node
{
    /* Chave do nó */
    int id;
    /* Próximo elemento da lista encadeada */
    No* next;
} No;

/* Estrutura de grafo em lista de adjacências */
typedef struct _grafo
{
    /* Número de vértices */
    int v;
    /* Número de arestas */
    int e;
    /* Lista de adjecências */
    No** adj;
} Grafo;

/* Cria um grafo baseado no tamanho passado */
Grafo* create_graph (int);
/* Limpa o grafo da memória */ 
Grafo* free_graph (Grafo*);
/* Cria um nó para a lista de adjacências */
No* add_node (No*, int);
/* Adiciona uma aresta nova à lista de adjacências. O último atributo inteiro implica se a aresta é direcionada ou não */
void add_edge (Grafo*, int, int, int);

#endif