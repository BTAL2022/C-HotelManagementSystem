#include <stdio.h>
#include "reservas.h"
#include "hotel.h"

// Realiza uma reserva no hotel, reduzindo o número de quartos disponíveis.
// Retorna 0 em caso de sucesso e -1 em caso de erro.
int realizar_reserva(Hotel *hotel, int num_quartos) {
    if (hotel == NULL || num_quartos < 1) {
        fprintf(stderr, "Erro: hotel inválido ou número de quartos incorreto.\n");
        return -1;
    }

    if (hotel->quartos_disponiveis < num_quartos) {
        fprintf(stderr, "Erro: não há quartos disponíveis suficientes no hotel.\n");
        return -1;
    }

    hotel->quartos_disponiveis -= num_quartos;
    return 0;
}

// Cancela uma reserva no hotel, aumentando o número de quartos disponíveis.
// Retorna 0 em caso de sucesso e -1 em caso de erro.
int cancelar_reserva(Hotel *hotel, int num_quartos) {
    if (hotel == NULL || num_quartos < 1) {
        fprintf(stderr, "Erro: hotel inválido ou número de quartos incorreto.\n");
        return -1;
    }

    hotel->quartos_disponiveis += num_quartos;
    return 0;
}
