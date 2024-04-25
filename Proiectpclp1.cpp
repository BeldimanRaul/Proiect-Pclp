
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
 
using namespace std;

class ContBancar {
private:
    double balanta;
    string nume;
    string prenume;
    int cod_pin;
    int test;

public:
    ContBancar(string n , string p , double bal, int cp) : nume(n), prenume(p), balanta(bal), cod_pin(cp) {}

    string getNume() {
        return nume;
    }
    string getPrenume() {
        return prenume;
    }
    double getBalanta() {
        return balanta;
    }

    int getCodPin() {
        return cod_pin;
    }

    void adaugareFinante(double suma) {
        balanta = balanta + suma;
    }

    void retragere(double suma2) {
        if (suma2 > balanta)
            cout << "fonduri insuficiente" << endl;
        else {
            balanta = balanta - suma2;
            cout << "retragere succes";
        }
    }
};

class ManagementBanca {
private:
    vector<ContBancar>conturi;

public:
    void adaugarecont(string n, string p, double bal, int cp) {
        conturi.push_back(ContBancar(n, p, bal, cp));
    }

    void vizualizareconturi() {
        cout << "Astea sunt toate conturile:" << endl;
        for (int i = 0; i < conturi.size(); i++) {
            cout << "Nume:" << conturi[i].getNume() << endl;
            cout << "Prenume:" << conturi[i].getPrenume() << endl;
            cout << "Balanta este:" << conturi[i].getBalanta() << endl;
            cout << "Codul pin este:" << conturi[i].getCodPin() << endl;
        }
    }

    void cautarecont(int codpin) {
        cout << "Detinatorul contului" << endl;
        for (int i = 0; i < conturi.size(); i++) {
            if (conturi[i].getCodPin() == codpin) {
                cout << "Nume:" << conturi[i].getNume() << endl;
                cout << "Prenume:" << conturi[i].getPrenume() << endl;
                cout << "Balanta este:" << conturi[i].getBalanta() << endl;
            }
        }
    }

    ContBancar *findAccount(int codPin) {
        for (int i = 0; i < conturi.size(); i++) {
            if (conturi[i].getCodPin() == codPin) {
                return &conturi[i];
            }
        }
        return nullptr;
    }

    void adaugarefinante(int codPin, double suma) {
        ContBancar* cont = findAccount(codPin);
        if (cont != nullptr) {
            cont->adaugareFinante(suma);
            cout << suma << " adaugate cu succes in contul lui " << cont->getNume() << " " << cont->getPrenume() << endl;
        } else {
            cout << "Contul nu a fost gasit." << endl;
        }
    }

    void retragere(int codPin, double suma) {
        ContBancar* cont = findAccount(codPin);
        if (cont != nullptr) {
            cont->retragere(suma);
        } else {
            cout << "Contul nu a fost gasit." << endl;
        }
    }
};

int main() {
    int alegere;
    char optiune;
    ManagementBanca bankManager;
    do {
        system("cls");

        cout << "Brasov Central Bank" << endl;
        cout << "Meniu Principal" << endl;
        cout << "1. Creare Cont" << endl;
        cout << "2. Arata toate conturile" << endl;
        cout << "3. Cauta cont" << endl;
        cout << "4. Adauga Numerar" << endl;
        cout << "5. Retragere Numerar" << endl;
        cout << "6. IESIRE" << endl;
        cout << "$$$$$$$$$$$$$$$$$$$$$" << endl;
        cout << "Alege :";
        cin >> alegere;
        switch (alegere) {
            
            case 1: {
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
                bankManager.adaugarecont(nume, prenume, balanta, cod_pin);
                break;
            }
            case 2: {
                bankManager.vizualizareconturi();
                break;
            }
            case 3: {
                int cod_pin;
                cout << "Introduceti codul pin pentru cautare: ";
                cin >> cod_pin;
                bankManager.cautarecont(cod_pin);
                break;
            }
            case 4: {
                int codPin;
                double suma;
                cout << "Introduceti Codul Pin pentru a adauga numerar: ";
                cin >> codPin;
                cout << "Introduceti Suma de adaugat: ";
                cin >> suma;
                bankManager.adaugarefinante(codPin, suma);
                break;
            }
            case 5: {
                int codPin;
                double suma;
                cout << "Introduceti Codul Pin pentru a retrage numerar: ";
                cin >> codPin;
                cout << "Introduceti Suma de retras: ";
                cin >> suma;
                bankManager.retragere(codPin, suma);
                break;
            }
            case 6: {
                cout << "La revedere!";
                return 0;
            }
            default: {
                cout << "Optiune invalida!" << endl;
                break;
            }
        }
        cout << "Doriti sa continuati sau sa iesiti [Da/Nu] ? ";
        cin >> optiune;
    } while (optiune == 'D' || optiune == 'd');

    return 0;
}
