#ifndef INTERFATABANCARA_H
#define INTERFATABANCARA_H

#include "ManagementBanca.h"
#include "AplicareCredit.h"
#include <vector>
using namespace std;

class InterfataBancara
{
private:
    ManagementBanca managbanca;
    vector<AplicareCredit> aplicatii_credit;

public:
    InterfataBancara();
    void logicainterfetei();
    void adaugaAplicatieCredit(string nume, string prenume, string adresa, string email, double creditsuma, int duratacreditului, string dececredit, double dobanda, double salariu, double datorii, string altecrediteavute);
    void afiseazaAplicatiiCredit();
    
};

#endif // INTERFATABANCARA_H
