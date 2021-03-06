#include "main.h"

Grafo* create_graph (int size)
{
    Grafo* grafo = (Grafo*) malloc(sizeof(Grafo));
    grafo->e = 0;
    grafo->v = size;
    grafo->adj = (No**) malloc(size * sizeof(No*));
    grafo->length = (int*) malloc(size * sizeof(int));
    grafo->sat = (int*) malloc(size * sizeof(int));
    grafo->color = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        grafo->adj[i] = NULL;
        grafo->length[i] = 0;
        grafo->sat[i] = 0;
        grafo->color[i] = 0;
    }
    return grafo;
}

Grafo* free_graph (Grafo* grafo) {
    for (int i = 0; i < grafo->v; ++i)
        if (grafo->adj[i] != NULL)
          free(grafo->adj[i]);
    free(grafo->adj);
    free(grafo->length);
    free(grafo->sat);
    free(grafo->color);
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
    ++grafo->length[in];
    if (!directional)
    {
        grafo->adj[out] = add_node(grafo->adj[out], in);
        ++grafo->length[out];
        ++grafo->e;
    }
    ++grafo->e;
}

void print_graph (Grafo* grafo)
{
    for (int i = 0; i < grafo->v; putchar('\n'), ++i)
    {
        printf("%d -> ", i);
        No* no = grafo->adj[i];
        while (no != NULL)
        {
            printf("%d ", no->id);
            no = no->next;
        }
    }
    printf("\n\n");
}

int get_highest_length_edge (Grafo* grafo)
{
    int index = 0;
    for (int i = 0; i < grafo->v; i++)
        if (grafo->length[i] > grafo->length[index])
            index = i;
    return index;
}

int get_highest_degree_edge (Grafo* grafo)
{
    int index = -1;
    for(int i = 0; i < grafo->v; i++)
      if (grafo->color[i] == 0)
        if (grafo->sat[i] > grafo->sat[index])
            index = i;
        else if (grafo->sat[i] == grafo->sat[index] &&
          grafo->length[i] > grafo->length[index])
            index = i;
    return index;
}
