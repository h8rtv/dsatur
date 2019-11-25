#include "main.h"

Grafo* create_graph (int size)
{
    Grafo* grafo = (Grafo*) malloc(sizeof(Grafo));
    grafo->e = 0;
    grafo->v = size;
    grafo->adj= (No**) malloc(size * sizeof(No*));
    for (int i = 0; i < size; ++i)
        grafo->adj[i] = NULL;
    return grafo;
}

Grafo* free_graph (Grafo* grafo) {
    for (int i = 0; i < grafo->v; ++i)
        if (grafo->adj[i] != NULL)
            free(grafo->adj[i]);
    free(grafo->adj);
    free(grafo);
    return NULL;
}

No* add_node (No* prev, int out)
{
    No* new = (No*) malloc(sizeof(No));
    new->id = out;
    new->next = prev;
    return new;
}

void add_edge (Grafo* grafo, int in, int out, int directional)
{
    grafo->adj[in] = add_node(grafo->adj[in], out);
    if (!directional)
        grafo->adj[out] = add_node(grafo->adj[out], in);
}

void print_graph (Grafo* grafo) {
  for (int i = 0; i < grafo->v; putchar('\n'), ++i) {
    printf("%d -> ", i);
    No* no = grafo->adj[i];
    while (no != NULL) {
      printf("%d ", no->id);
      no = no->next;
    }
  }
  printf("\n\n");
}