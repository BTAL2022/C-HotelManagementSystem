#ifndef HOTEL_H
#define HOTEL_H

// Define a estrutura Hotel com informações sobre o hotel,
// incluindo nome, localização, número de quartos disponíveis e preço por noite.
typedef struct {
    char nome[100];
    char localizacao[100];
    int quartos_disponiveis;
    double preco_por_noite;
} Hotel;

// Declara a função imprimir_hotel, que imprime informações do hotel na tela.
int imprimir_hotel(const Hotel *hotel);

#endif // HOTEL_H
