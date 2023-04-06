#include <stdio.h>
#include "menu.h"

// Define a instrução para limpar a tela de acordo com o sistema operacional.
#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

// Limpa a tela do terminal usando a instrução apropriada para o sistema operacional.
void limpar_tela() {
    system(CLEAR_SCREEN);
}

// Exibe um cabeçalho atraente no topo do menu.
void exibir_cabecalho() {
    printf("=======================================\n");
    printf("=     Sistema de Reservas de Hotéis    =\n");
    printf("=======================================\n");
}

// Exibe o menu principal com as opções disponíveis.
void exibir_menu() {
    limpar_tela();
    exibir_cabecalho();
    printf("\nMenu de opções:\n");
    printf("1. Listar hotéis\n");
    printf("2. Fazer reserva\n");
    printf("3. Verificar reservas\n");
    printf("4. Cancelar reserva\n");
    printf("5. Recomendar hotel\n");
    printf("6. Exportar dados\n");
    printf("0. Sair\n");
}

// Lê a opção escolhida pelo utilizador e retorna o valor.
int obter_opcao() {
    int opcao;

    printf("\nDigite a opção desejada e pressione ENTER: ");
    scanf("%d", &opcao);

    return opcao;
}

// Valida se a opção inserida pelo utilizador está dentro do intervalo permitido (0 a 6).
// Retorna 1 se a opção for válida, e 0 caso contrário.
int validar_opcao(int opcao) {
    if (opcao < 0 || opcao > 6) {
        printf("\nOpção inválida! Por favor, insira uma opção válida.\n");
        return 0;
    }
    return 1;
}
