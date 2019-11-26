#include "main.h"

void dsatur (Grafo* grafo)
{
    int j = 0;
    No* node = NULL;
  	int i = get_highest_length_edge(grafo);
    grafo->color[i] = 1;
    for (node = grafo->adj[i]; node != NULL; node = node->next)
        grafo->sat[node->id]++;
    while (1)
    {
        i = get_highest_degree_edge(grafo);
        if (i == -1) break;
        grafo->color[i] = 1;
        node = grafo->adj[i];
        while (node != NULL)
            if (grafo->color[node->id] == grafo->color[i])
            {
                grafo->color[i]++;
                node = grafo->adj[i];
            } else
                node = node->next;
        for (node = grafo->adj[i]; node != NULL; node = node->next)
            grafo->sat[node->id]++;
    }
}

int main (void)
{
    char* filename = "samples/exemplo.csv";
    Grafo* grafo = read_csv(filename);
    print_graph(grafo);
    dsatur(grafo);
    write_graph(grafo);
    free_graph(grafo);
    return 0;
}
