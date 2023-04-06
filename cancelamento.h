#ifndef CANCELAMENTO_H
#define CANCELAMENTO_H

#include "hotel.h"

// Declara a função cancelar_reserva, que cancela uma reserva em um hotel,
// aumentando o número de quartos disponíveis.
// Retorna 0 em caso de sucesso e -1 em caso de erro.
int cancelar_reserva(Hotel *hotel, int num_quartos);

#endif // CANCELAMENTO_H
