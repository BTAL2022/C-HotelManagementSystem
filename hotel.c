#include <stdio.h>
#include "hotel.h"

// Imprime informações do hotel na tela.
// Retorna 0 em caso de sucesso e -1 em caso de erro.
// A função verifica se o ponteiro do hotel passado é válido antes de acessar seus membros.
int imprimir_hotel(const Hotel *hotel) {
    if (hotel == NULL) {
        fprintf(stderr, "Erro: ponteiro do hotel inválido.\n");
        return -1;
    }

    printf("Nome: %s\n", hotel->nome);
    printf("Localização: %s\n", hotel->localizacao);
    printf("Quartos disponíveis: %d\n", hotel->quartos_disponiveis);
    printf("Preço por noite: %.2f\n", hotel->preco_por_noite);

    return 0;
}
