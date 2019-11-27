#ifndef CSV_H
#define CSV_H

#include "main.h"

/* Escreve as cores dos nós */
void write_graph (Grafo* grafo);
/* Conta a quantidade de linhas num arquivo */
int count_lines (char* stream);
/* Lê o CSV de entrada e retorna o Grafo */
Grafo* read_csv (char* filename);
/* Escreve as informações necessárias */
void write_info(Grafo* grafo, clock_t start);

#endif
