#include <stdio.h>
#include <stdlib.h>
#include "leitura.h"
#include "escrita.h"
#include "hotel.h"
#include "menu.h"

#define MAX_HOTEIS 100

int main() {
    // Lê os dados dos hotéis do arquivo CSV.
    Hotel hoteis[MAX_HOTEIS];
    int num_hoteis = ler_hoteis_csv("hoteis.csv", hoteis, MAX_HOTEIS);
    if (num_hoteis == -1) {
        fprintf(stderr, "Erro ao ler o arquivo CSV de hotéis.\n");
        return EXIT_FAILURE;
    }

    // Cria uma reserva para testar o programa.
    int num_quartos_reservados = 2;
    Hotel *hotel_reservado = reservar_quartos(hoteis, num_hoteis, "Hotel 1", num_quartos_reservados);
    if (hotel_reservado == NULL) {
        fprintf(stderr, "Erro ao criar reserva.\n");
        return EXIT_FAILURE;
    }

    // Imprime os dados do hotel reservado.
    printf("Reserva criada:\n");
    imprimir_hotel(hotel_reservado);

    // Cancela a reserva.
    if (cancelar_reserva(hotel_reservado, num_quartos_reservados) == -1) {
        fprintf(stderr, "Erro ao cancelar reserva.\n");
        return EXIT_FAILURE;
    }

    // Imprime os dados atualizados do hotel reservado.
    printf("Reserva cancelada:\n");
    imprimir_hotel(hotel_reservado);

    // Executa o menu do programa.
    int opcao = -1;
    while (opcao != 0) {
        opcao = exibir_menu();
        switch (opcao) {
            case 1:
                exibir_hoteis(hoteis, num_hoteis);
                break;
            case 2:
                reservar_quartos_menu(hoteis, num_hoteis);
                break;
            case 3:
                exibir_reservas(hoteis, num_hoteis);
                break;
            case 4:
                cancelar_reserva_menu(hoteis, num_hoteis);
                break;
            case 5:
                recomendar_hotel_menu(hoteis, num_hoteis);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    }

    // Escreve os dados dos hotéis e das reservas em um arquivo CSV.
    if (escrever_dados_csv("dados.csv", hoteis, num_hoteis) == -1) {
        fprintf(stderr, "Erro ao escrever o arquivo CSV de dados.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
