#ifndef APLICARECREDIT_H
#define APLICARECREDIT_H

#include "Utilizator.h"
using namespace std;

class AplicareCredit : public Utilizator
{
private:
    string adresa;
    string email;
    double creditsuma;
    int duratacreditului;
    string dececredit;
    double dobanda;
    double salariu;
    double datorii;
    string altecrediteavute;

public:
    AplicareCredit(string n,string p, string adr, string emaill, double cs, int durata, string dece, double dob, double salar, double datorii, string istoriccredit);

    double calculeazaRata();
    double calculeazaDobandaLunara();
    double calculeazaDobandaFinala();
    bool verificaEligibilitate();
    void aratainfo();
    
};

#endif // APLICARECREDIT_H
