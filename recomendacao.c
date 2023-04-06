#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "recomendacao.h"
#include "hotel.h"

// Recomenda um hotel com base na localização e no preço máximo especificados.
// Retorna um ponteiro para o hotel recomendado ou NULL em caso de erro.
Hotel *recomendar_hotel(Hotel *hoteis, int num_hoteis, const char *localizacao, float preco_maximo) {
    // Verifica se os dados de entrada são válidos.
    if (hoteis == NULL || num_hoteis < 1 || localizacao == NULL || preco_maximo < 0) {
        fprintf(stderr, "Erro: dados inválidos.\n");
        return NULL;
    }

    // Inicializa o hotel recomendado como NULL.
    Hotel *recomendado = NULL;

    // Itera sobre a lista de hotéis para encontrar o hotel recomendado.
    for (int i = 0; i < num_hoteis; i++) {
        // Verifica se o hotel está na localização especificada e se o preço é menor ou igual ao preço máximo permitido pelo usuário.
        if (strcmp(hoteis[i].localizacao, localizacao) == 0 && hoteis[i].preco_por_noite <= preco_maximo) {
            // Verifica se o hotel atual é o mais barato até o momento e atualiza o hotel recomendado se for.
            if (recomendado == NULL || hoteis[i].preco_por_noite < recomendado->preco_por_noite) {
                recomendado = &hoteis[i];
            }
        }
    }

    // Retorna o hotel recomendado ou NULL se nenhum hotel foi recomendado.
    return recomendado;
}
