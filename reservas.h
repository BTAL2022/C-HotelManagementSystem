#ifndef RESERVAS_H
#define RESERVAS_H

#include "hotel.h"

int realizar_reserva(Hotel *hotel, int num_quartos);
int cancelar_reserva(Hotel *hotel, int num_quartos);

#endif // RESERVAS_H
