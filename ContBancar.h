#ifndef CONTBANCAR_H
#define CONTBANCAR_H

#include "Utilizator.h"

class ContBancar : public Utilizator {
private:
    double balanta;
    int cod_pin;

public:
    ContBancar(string n, string p, double bal, int cp);

    double getBalanta();

    int getCodPin();

    void adaugareFinante(double suma);

    void retragere(double suma2);
};

#endif // CONTBANCAR_H
