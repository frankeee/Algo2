/* Completar */

#include "Periodo.h"



Periodo::Periodo(int anios, int meses, int dias) {
    _anios= anios;
    _meses=meses;
    _dias= dias;
}
int Periodo::anios()  {
    return _anios;
}

int Periodo::meses()  {
    return _meses;
}

int Periodo::dias() {
    return _dias;
}
