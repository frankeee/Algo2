//
// Created by fcolombini on 28/08/19.
//

#ifndef SOLUCION_PERIODO_H
#define SOLUCION_PERIODO_H

class Periodo {
public:
    Periodo(int anios, int meses, int dias);

    int anios();
    int meses();
    int dias();

private:
    int _anios;
    int _meses;
    int _dias;
};









#endif //SOLUCION_PERIODO_H
