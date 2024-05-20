#ifndef APLICARECREDIT_H
#define APLICARECREDIT_H

#include "AplicareCredit.h"
#include "Utilizator.h"
#include <string>
using namespace std;


class AplicareCredit :public Utilizator
{
private:
    string adresa;
    string datanastere;
    string email;
    double creditsuma;
    int duratacreditului;
    string dececredit;
    double dobanda;
    double salariu;
    double datorii;
    string altecrediteavute;
    

public:
AplicareCredit() : Utilizator("", ""), adresa(""), email(""), creditsuma(0), duratacreditului(0), dececredit(""), dobanda(0), salariu(0), datorii(0), altecrediteavute("") {}

double calculeazaRata();
double getDobanda();
bool valideazaAplicatia();
void aratainfo();





};





#endif // APLICARECREDIT_H


