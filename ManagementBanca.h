#ifndef MANAGEMENTBANCA_H
#define MANAGEMENTBANCA_H

#include "Utilizator.h"
#include "ContBancar.h"
#include <vector>

class ManagementBanca : public Utilizator {
private:
    vector<ContBancar> conturi;
    string parola_admin = "admin123";

public:
    ManagementBanca(string n, string p);

    void adaugarecont(string n, string p, double bal, int cp);

    void vizualizareconturi();

    void cautarecont(int codpin);

    ContBancar gasestecont(int codPin);

    void adaugarefinante(int codPin, double suma);

    void retragere(int codPin, double suma);

    ContBancar formularlogin(ManagementBanca managbanca, int nrIncercari);
};

#endif // MANAGEMENTBANCA_H
