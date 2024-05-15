#include "InterfataBancara.h"
#include <iostream>

InterfataBancara::InterfataBancara() : managbanca("test", "test") {
    managbanca.adaugarecont("test", "test", 9998, 1234);
    managbanca.formularlogin(managbanca,3);
}

void InterfataBancara::logicainterfetei() {
  
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
            cout << "5. IESIRE" << endl;
            cout << "0000. Arata toate conturile" << endl;
            cout << "----------------------------" << endl;
            cout << "Alege :";
            cin >> alegere;
            switch (alegere)
            {

            case 1:
            {
                string nume;
                string prenume;
                double balanta;
                int cod_pin;
                cout << "Introduceti numele dvs:" << endl;
                cin >> nume;
                cout << "Introduceti prenumele dvs:" << endl;
                cin >> prenume;
                cout << "Introduceti balanta dvs:" << endl;
                cin >> balanta;
                cout << "Introduceti codul pin:" << endl;
                cin >> cod_pin;
                managbanca.adaugarecont(nume, prenume, balanta, cod_pin);
                break;
            }
            case 0000:
            {
                managbanca.vizualizareconturi();
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
                cout << "La revedere!";
                managbanca.formularlogin(managbanca,3);
                break;
            }
            default:
            {
                cout << "Optiune invalida!" << endl;
                break;
            }
            }
            cout << "Doriti sa continuati sau sa iesiti [Da/Nu] ? ";
            cin >> optiune;
        } while (optiune == 'D' || optiune == 'd');
    }

