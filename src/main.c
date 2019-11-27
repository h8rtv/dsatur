#include "main.h"

void dsatur (Grafo* grafo)
{
    No* node = NULL;
  	int i = get_highest_length_edge(grafo);
    int notFirstTime = 0;
    while (i != -1)
    {
        grafo->color[i] = 1;
        node = grafo->adj[i];
        if (notFirstTime)
          while (node != NULL)
              if (grafo->color[node->id] == grafo->color[i])
              {
                  grafo->color[i]++;
                  node = grafo->adj[i];
              } else
                  node = node->next;
        else
          notFirstTime = 1;
        for (node = grafo->adj[i]; node != NULL; node = node->next)
            grafo->sat[node->id]++;
        i = get_highest_degree_edge(grafo);
    }
}

int main (void)
{

    clock_t start = clock();

    char* filename = "grafo06.csv";
    Grafo* grafo = read_csv(filename);
    print_graph(grafo);
    dsatur(grafo);
    write_graph(grafo);

    write_info(grafo, start);
    free_graph(grafo);
    return 0;
}
