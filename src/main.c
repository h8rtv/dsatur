#include "main.h"

void dsatur (Grafo* grafo)
{
    No* node = NULL;
  	int i = get_highest_length_edge(grafo);
    int notFirstTime = 0;
    int done = 0;
    while (i != -1)
    {
        done = 0;
        grafo->color[i] = 1;
        // Caso seja a primeira passagem pelo loop, ou seja, o i seja do índice mais saturado.
        if (notFirstTime)
            // Seleciona a menor cor possível de acordo com a lista encadeada.
            while (!done)
            {
              done = 1;
              for (node = grafo->adj[i]; node != NULL; node = node->next)
                  if (grafo->color[node->id] == grafo->color[i])
                  {
                      grafo->color[i]++;
                      done = 0;
                  }
            }
        else
            notFirstTime = 1;
        // Satura todos os nós vizinhos
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

    test_dsatur(grafo);

    return 0;
}
