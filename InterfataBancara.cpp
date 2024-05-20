#include "InterfataBancara.h"
#include <iostream>
using namespace std;



InterfataBancara::InterfataBancara() : managbanca("admin", "admin")
{
    managbanca.adaugarecont("admin", "admin", 10000, 1234);
    managbanca.formularlogin(managbanca,3);
}

void InterfataBancara::adaugaAplicatieCredit(string nume, string prenume, string adresa, string email, double creditsuma, int duratacreditului, string dececredit, double dobanda, double salariu, double datorii, string altecrediteavute)
{
    AplicareCredit aplicatie(nume, prenume, adresa, email, creditsuma, duratacreditului, dececredit, dobanda, salariu, datorii, altecrediteavute);
    
    if (aplicatie.verificaEligibilitate())
    {
        aplicatii_credit.push_back(aplicatie);
        cout << "Aplicatia de credit a fost adaugata cu succes." << endl;
    }
    else
    {
        cout << "Aplicatia de credit nu a fost aprobata din cauza neindeplinirii cerintelor." << endl;
    }
}

void InterfataBancara::afiseazaAplicatiiCredit()
{
    cout << "Lista aplicatiilor de credit:\n";
    for (auto &aplicatie : aplicatii_credit)
    {
        aplicatie.aratainfo();
        cout << endl;
    }
}

void InterfataBancara::logicainterfetei()
{
    int alegere;
    char optiune;

    do
    {
        system("cls");

    cout << "Brasov Central Bank" << endl;
        cout << "Meniu Principal" << endl;
        cout << "1. Creare Cont" << endl;
        cout << "2. Cauta cont" << endl;
        cout << "3. Adauga Numerar" << endl;
        cout << "4. Retragere Numerar" << endl;
        cout << "5. Aplica pentru un credit" <<endl;
        cout << "6. IESIRE" << endl;
        cout << "0000. Arata toate conturile" <<endl;
        cout << "----------------------------" << endl;
        cout << "Alege: ";
        cin >> alegere;

        switch (alegere)
        {
        case 1:
        {
            string nume;
            string prenume;
            double balanta;
            int cod_pin;
            cout << "Introduceti numele dvs: ";
            cin >> nume;
            cout << "Introduceti prenumele dvs: ";
            cin >> prenume;
            cout << "Introduceti balanta dvs: ";
            cin >> balanta;
            cout << "Introduceti codul pin: ";
            cin >> cod_pin;
            managbanca.adaugarecont(nume, prenume, balanta, cod_pin);
            break;
        }
        case 0000:
        {
            managbanca.vizualizareconturi();
             afiseazaAplicatiiCredit();
            break;
        }
        case 2:
        {
            int cod_pin;
            cout << "Introduceti codul pin pentru cautare: ";
            cin >> cod_pin;
            managbanca.cautarecont(cod_pin);
            break;
        }
        case 3:
        {
            int codPin;
            double suma;
            cout << "Introduceti Codul Pin pentru a adauga numerar: ";
            cin >> codPin;
            cout << "Introduceti Suma de adaugat: ";
            cin >> suma;
            managbanca.adaugarefinante(codPin, suma);
            break;
        }
        case 4:
        {
            int codPin;
            double suma;
            cout << "Introduceti Codul Pin pentru a retrage numerar: ";
            cin >> codPin;
            cout << "Introduceti Suma de retras: ";
            cin >> suma;
            managbanca.retragere(codPin, suma);
            break;
        }
        case 5:
        {
            string nume, prenume, adresa, email, dececredit, altecrediteavute;
            double creditsuma, dobanda, salariu, datorii;
            int duratacreditului;

            cout << "Introduceti numele dvs: ";
            cin >> nume;
            cout << "Introduceti prenumele dvs: ";
            cin >> prenume;
            cout << "Introduceti adresa dvs: ";
            cin.ignore();
            getline(cin, adresa);
            cout << "Introduceti emailul dvs: ";
            cin >> email;
    cout << "Introduceti suma dorita: ";
            cin >> creditsuma;
            cout << "Introduceti durata creditului (in luni): ";
            cin >> duratacreditului;
            cout << "Introduceti scopul creditului: ";
            cin.ignore();
            getline(cin, dececredit);
            cout << "Introduceti dobanda anuala (%): ";
            cin >> dobanda;
            cout << "Introduceti salariul lunar: ";
            cin >> salariu;
            cout << "Introduceti suma datoriilor existente: ";
            cin >> datorii;
            cout << "Introduceti alte credite avute: ";
            cin.ignore();
        getline(cin, altecrediteavute);

            adaugaAplicatieCredit(nume, prenume, adresa, email, creditsuma, duratacreditului, dececredit, dobanda, salariu, datorii, altecrediteavute);
           
            break;
        }
        case 6:
        {
            cout << "La revedere!";
            managbanca.formularlogin(managbanca,9);
            break;
        }
        default:
        {
            cout << "Optiune invalida!" << endl;
            break;
        }
        }
        cout << "Doriti sa continuati sau sa iesiti [Da/Nu]? ";
        cin >> optiune;
    } while (optiune == 'D' || optiune == 'd');
}
