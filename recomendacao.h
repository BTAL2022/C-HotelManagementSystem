#ifndef RECOMENDACAO_H
#define RECOMENDACAO_H

#include "hotel.h"

// Declara a função recomendar_hotel, que recomenda um hotel com base na localização e no preço máximo especificados.
// Retorna um ponteiro para o hotel recomendado ou NULL em caso de erro.
Hotel *recomendar_hotel(Hotel *hoteis, int num_hoteis, const char *localizacao, float preco_maximo);

#endif // RECOMENDACAO_H
