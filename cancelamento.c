#include <stdio.h>
#include "cancelamento.h"
#include "hotel.h"

// Cancela uma reserva no hotel, aumentando o número de quartos disponíveis.
// Retorna 0 em caso de sucesso e -1 em caso de erro.
int cancelar_reserva(Hotel *hotel, int num_quartos) {
    // Verifica se o hotel é válido e se o número de quartos é maior que 0.
    if (hotel == NULL || num_quartos < 1) {
        fprintf(stderr, "Erro: hotel inválido ou número de quartos incorreto.\n");
        return -1;
    }

    // Aumenta o número de quartos disponíveis no hotel.
    hotel->quartos_disponiveis += num_quartos;
    return 0;
}
