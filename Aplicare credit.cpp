
#include "AplicareCredit.h"
#include <iostream>
#include <cmath>
using namespace std;



double AplicareCredit::calculeazaRata()
{
    double ratalunara=dobanda/12/100;
    int n= duratacreditului;
    double numerator = creditsuma * ratalunara * pow(1 + ratalunara, n);
    double denominator = pow(1 + ratalunara, n) - 1;
    return numerator / denominator;
}

double AplicareCredit:: getDobanda()
{
    return dobanda;
}

bool AplicareCredit::valideazaAplicatia()  {
    return !adresa.empty() && !email.empty() && creditsuma > 0 &&
           duratacreditului > 0 && salariu > 0;
}

void AplicareCredit::aratainfo()  {
    cout << "Nume Aplicant: " << getNume() << "\n"
         << "Prenume Aplicant: " << getPrenume() << "\n"
         << "Adresa: " << adresa << "\n"
         << "Email: " << email << "\n"
         << "Suma Creditului: " << creditsuma << "\n"
         << "Durata Creditului: " << duratacreditului << " luni\n"
         << "Dobanda: " << dobanda << "%\n"
         << "Rata Lunara: " << calculeazaRata() << "\n";
}