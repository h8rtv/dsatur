#include "main.h"

































int count_lines (char* filename) {
    if (fseek(filename, 0L, SEEK_END) != 0) {
        printf("Erro ao ler arquivo.\n");
        return -1;
    }

    int size = ftell(filename);
    if (fseek(filename, 0L, SEEK_SET) != 0) {
        printf("Erro ao ler arquivo.\n");
        return -1;
    }
    return size;
}

/* Lê as parada */
Grafo* read_csv (char* filename) {
    Grafo* grafo = create_graph(count_lines(filename));
    FILE* stream = fopen(filename, "r");

    char line[MAX_LINE_LENGTH];
    while(fgets(line, MAX_LINE_LENGTH, stream)){
        char* tmp = strdup(line);
        char* field = strtok(tmp, ',');
        int first = atoi(field);
        
        while(field != NULL){
            
            field = strtok(NULL, ',');
        }
        
        free(tmp);
    }
}


