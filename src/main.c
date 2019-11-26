#include "main.h"

int count_lines (FILE* stream)
{
    int size = 0;
    for (char c = getc(stream); c != EOF; c = getc(stream))
        if (c == '\n')
            ++size;

    if (fseek(stream, 0L, SEEK_SET) != 0)
    {
        printf("Erro ao ler arquivo.\n");
        return -1;
    }
    return size + 1;
}

/* Lê as parada */
Grafo* read_csv (char* filename)
{
    FILE* stream = fopen(filename, "r");
    Grafo* grafo = create_graph(count_lines(stream));

    char line[MAX_LINE_LENGTH];
    const char* delim = ",";
    while (fgets(line, MAX_LINE_LENGTH, stream))
    {
        char* tmp = strdup(line);
        char* field = strtok(tmp, delim);
        int first = atoi(field);

        while (field != NULL)
        {
            field = strtok(NULL, delim);
            if (field != NULL)
                add_edge(grafo, first - 1, atoi(field), 1);
        }

        free(tmp);
    }
    return grafo;
}

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
    free_graph(grafo);
    return 0;
}
