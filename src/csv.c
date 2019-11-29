#include "main.h"

/* Escreve as cores dos nós */
void write_graph(Grafo* grafo)
{
    FILE *fp;

    fp = fopen("output.csv", "w+");
    fprintf(fp, "Nó, Cor\n");

    for(int i = 0; i < grafo->v; i++)
        fprintf(fp, "%d, %d\n", i, grafo->color[i]);
    fclose(fp);
}

/* Conta a quantidade de linhas num arquivo */
int count_lines (char* filename)
{
    int size = 0;
    FILE* stream = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stream))
    {
        if(strlen(line) > 1)
            size++;
    }
    return size;
}

/* Lê o CSV de entrada e retorna o Grafo */
Grafo* read_csv (char* filename)
{
    FILE* stream = fopen(filename, "r");
    Grafo* grafo = create_graph(count_lines(filename));

    char line[MAX_LINE_LENGTH];
    const char* delim = ",";
    while (fgets(line, MAX_LINE_LENGTH, stream))
    {
        if(strlen(line) <= 1) continue;

        char* tmp = strdup(line);
        char* field = strtok(tmp, delim);
        int first = atoi(field);

        while (field != NULL)
        {
            field = strtok(NULL, delim);
            if (field != NULL)
                add_edge(grafo, first - 1, atoi(field) - 1, 1);
        }

        free(tmp);
    }
    return grafo;
}

/* Escreve as informações necessárias */
void write_results(Grafo* grafo, clock_t start){
    int
        grau_min = -1,
        grau_max = -1,
        cores = 0;

    double
        grau_med = 0,
        grau_dp = 0;

    clock_t end = clock();
    float endtime = (float) (end - start) / CLOCKS_PER_SEC;

    
    // Define grau máximo, médio e mínimo, e o número de cores
    for(int i = 0; i < grafo->v; i++){
        if(grafo->length[i] < grau_min || grau_min == -1)
            grau_min = grafo->length[i];
        if(grafo->length[i] > grau_max || grau_max == -1)
            grau_max = grafo->length[i];
        
        grau_med += grafo->length[i];

        if(grafo->color[i] > cores)
            cores = grafo->color[i];
    }
    grau_med /= grafo->v;

    // Define o desvio padrão
    for(int i = 0; i < grafo->v; i++){
        grau_dp += (double) pow((double) (grafo->length[i] - grau_med), (double) 2);
    }
    grau_dp /= grafo->v;
    grau_dp = sqrt(grau_dp);

    FILE *fp;

    fp = fopen("resultados.csv", "w+");
    fprintf(fp, "No. nós, No. arestas, Grau mínimo, Grau máximo, Grau médio, Desvio padrão, No. cores, Run time (s)\n");
    fprintf(fp, "%d, %d, %d, %d, %.2f, %f, %d, %f\n",
                grafo->v,
                (int) floor(grafo->e/2),
                grau_min, grau_max, grau_med, grau_dp,
                cores,
                endtime);
    fclose(fp);
}