#include "AplicareCredit.h"
#include <iostream>
#include <cmath>
using namespace std;

AplicareCredit::AplicareCredit(string n, string p, string adr, string emaill, double cs, int durata, string dece, double dob, double salar, double datorii, string istoriccredit)
    : Utilizator(n, p), adresa(adr), email(emaill), creditsuma(cs),
      duratacreditului(durata), dececredit(dece), dobanda(dob),
      salariu(salar), datorii(datorii), altecrediteavute(istoriccredit) {}

double AplicareCredit::calculeazaRata()
{
    double rataLunara = calculeazaDobandaLunara();
    int numarLuni = duratacreditului;
    double rata = (creditsuma * rataLunara) / (1 - pow(1 + rataLunara, -numarLuni));
    return rata;
}

double AplicareCredit::calculeazaDobandaLunara()
{
    double rataAnuala = dobanda / 100;
    double rataLunara = rataAnuala / 12;
    return rataLunara;
}

double AplicareCredit::calculeazaDobandaFinala()
{
    double rataLunara = calculeazaDobandaLunara();
    int numarLuni = duratacreditului;
    double sumaFinala = creditsuma * pow(1 + rataLunara, numarLuni);
    return sumaFinala - creditsuma;
}

bool AplicareCredit::verificaEligibilitate()
{
    if (salariu < 1500)
    {
        cout << "Salariul dvs. nu îndeplinește cerința minimă de 1500 RON." << endl;
        return false;
    }

    double rataLunara = calculeazaRata();
    if (rataLunara > 0.4 * salariu)
    {
        cout << "Rata lunara depaseste 40% din salariul dvs." << endl;
        return false;
    }

    if (datorii > 5000)
    {
        cout << "Aveti datorii restante semnificative de peste 5000 RON." << endl;
        return false;
    }

   

    return true;
}

void AplicareCredit::aratainfo()
{
    cout << "Nume: " << nume << endl;
    cout << "Prenume: " << prenume << endl;
    cout << "Adresa: " << adresa << endl;
    cout << "Email: " << email << endl;
    cout << "Credit Suma: " << creditsuma << endl;
    cout << "Durata Creditului: " << duratacreditului << " luni" << endl;
    cout << "De ce credit: " << dececredit << endl;
    cout << "Dobanda: " << dobanda << "%" << endl;
    cout << "Rata Lunara: " << calculeazaRata() << endl;
   cout << "Dobanda Finala: " << calculeazaDobandaFinala() << endl;
}

