#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitura.h"
#include "hotel.h"

// Função auxiliar para contar o número de campos em uma linha do arquivo CSV.
int contar_campos(const char *linha) {
    int campos = 0;
    for (int i = 0; linha[i] != '\0'; i++) {
        if (linha[i] == ',') {
            campos++;
        }
    }
    return campos + 1;
}

// Lê os dados dos hotéis do arquivo CSV e armazena-os em um array de estruturas Hotel.
// Retorna 0 em caso de sucesso e -1 em caso de erro.
int ler_hoteis(const char *nome_arquivo, Hotel **hoteis, int *num_hoteis) {
    // Abre o arquivo para leitura.
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return -1;
    }

    char linha[1024];
    int linha_atual = 0;
    *num_hoteis = 0;

    // Lê o arquivo linha por linha.
    while (fgets(linha, sizeof(linha), arquivo)) {
        linha_atual++;

        // Ignora a linha de cabeçalho.
        if (linha_atual == 1) {
            continue;
        }

        // Verifica se o número de campos da linha é válido (4 campos esperados).
        if (contar_campos(linha) != 4) {
            fprintf(stderr, "Erro na linha %d: número incorreto de campos.\n", linha_atual);
            fclose(arquivo);
            return -1;
        }

        // Realoca memória para acomodar um novo hotel.
        *hoteis = realloc(*hoteis, (*num_hoteis + 1) * sizeof(Hotel));
        if (*hoteis == NULL) {
            perror("Erro ao realocar memória");
            fclose(arquivo);
            return -1;
        }

        // Lê e armazena os dados do hotel na estrutura.
        Hotel *hotel_atual = &(*hoteis)[*num_hoteis];
        sscanf(linha, "%[^,],%[^,],%d,%lf", hotel_atual->nome, hotel_atual->localizacao, &hotel_atual->quartos_disponiveis, &hotel_atual->preco_por_noite);

        // Incrementa o contador de hotéis.
        (*num_hoteis)++;
    }

    // Fecha o arquivo e retorna sucesso.
    fclose(arquivo);
    return 0;
}
