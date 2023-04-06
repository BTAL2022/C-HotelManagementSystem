#include <stdio.h>
#include "escrita.h"
#include "hotel.h"

// Escreve os dados dos hotéis no arquivo CSV.
// Retorna 0 em caso de sucesso e -1 em caso de erro.
// A função verifica se a lista de hotéis e o número de hotéis são válidos antes de escrever no arquivo.
// Também realiza o tratamento de erros ao abrir o arquivo para escrita.
int escrever_hoteis(const char *nome_arquivo, const Hotel *hoteis, int num_hoteis) {
    // Verifica se a lista de hotéis é válida e se o número de hotéis é maior que 0.
    if (hoteis == NULL || num_hoteis < 1) {
        fprintf(stderr, "Erro: lista de hotéis inválida.\n");
        return -1;
    }

    // Abre o arquivo para escrita e verifica se foi aberto corretamente.
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return -1;
    }

    // Escreve o cabeçalho do arquivo CSV.
    fprintf(arquivo, "Nome,Localização,Quartos Disponíveis,Preço por Noite\n");

    // Itera sobre a lista de hotéis e escreve cada hotel no arquivo CSV.
    for (int i = 0; i < num_hoteis; i++) {
        fprintf(arquivo, "%s,%s,%d,%.2f\n", hoteis[i].nome, hoteis[i].localizacao, hoteis[i].quartos_disponiveis, hoteis[i].preco_por_noite);
    }

    // Fecha o arquivo.
    fclose(arquivo);
    return 0;
}
