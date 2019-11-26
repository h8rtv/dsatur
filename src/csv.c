#include "main.h"

/* Escreve as cores dos nós */
void write_grafo(Grafo* grafo){
    FILE *fp;

    fp = fopen("output.csv", "w+");
    fprintf(fp, "Nó, Cor\n");

    for(int i = 0; i < grafo->v; i++){
        fprintf(fp, "%d, %d\n", i, grafo->color[i]);
    }
    fclose(fp);
}

/* Conta a quantidade de linhas num arquivo */
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

/* Lê o CSV de entrada e retorna o Grafo */
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
