#include "ContBancar.h"
#include <iostream>

ContBancar::ContBancar(string n, string p, double bal, int cp) : Utilizator(n, p), balanta(bal), cod_pin(cp) {}

double ContBancar::getBalanta() {
    return balanta;
}

int ContBancar::getCodPin() {
    return cod_pin;
}

void ContBancar::adaugareFinante(double suma) {
    balanta = balanta + suma;
}

void ContBancar::retragere(double suma2) {
    if (suma2 > balanta)
        cout << "Fonduri insuficiente" << endl;
    else {
        balanta = balanta - suma2;
        cout << "Retragere succes" << endl;
    }
}
