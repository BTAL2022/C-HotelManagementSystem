#ifndef MENU_H
#define MENU_H

// Exibe o menu principal com as opções disponíveis.
void exibir_menu();

// Lê a opção escolhida pelo utilizador e retorna o valor.
int obter_opcao();

// Valida se a opção inserida pelo utilizador está dentro do intervalo permitido (0 a 6).
// Retorna 1 se a opção for válida, e 0 caso contrário.
int validar_opcao(int opcao);

#endif // MENU_H

