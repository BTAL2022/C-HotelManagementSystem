#ifndef ESCRITA_H
#define ESCRITA_H

#include "hotel.h"

// Declara a função escrever_hoteis, que escreve os dados dos hotéis no arquivo CSV.
// Retorna 0 em caso de sucesso e -1 em caso de erro.
int escrever_hoteis(const char *nome_arquivo, const Hotel *hoteis, int num_hoteis);

#endif // ESCRITA_H
