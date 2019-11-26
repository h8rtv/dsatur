#include "main.h"

void dsatur (Grafo* grafo)
{
	int i = get_highest_length_edge(grafo);
  printf("%d\n", i);
}

int main (void)
{
    char* filename = "samples/exemplo.csv";
    Grafo* grafo = read_csv(filename);
    print_graph(grafo);
    dsatur(grafo);
    write_grafo(grafo);
    free_graph(grafo);
    return 0;
}
