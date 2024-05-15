#include "ManagementBanca.h"
#include <iostream>
#include <cstdlib>

ManagementBanca::ManagementBanca(string n, string p) : Utilizator(n, p) {}

void ManagementBanca::adaugarecont(string n, string p, double bal, int cp) {
   if (to_string(cp).length() != 4)
    {
        cout << "Codul PIN trebuie sa aiba exact 4 cifre. Va rugam reintroduceti." << endl;
        return;
    }

    
    for (size_t i = 0; i < conturi.size(); i++)
    {
        if (conturi[i].getCodPin() == cp)
        {
            cout << "Codul PIN introdus este deja folosit. Va rugam reintroduceti." << endl;
            return;
        }
    }
    conturi.push_back(ContBancar(n, p, bal, cp));
}

void ManagementBanca::vizualizareconturi() {
  string parola;
        cout << "Introduceti parola de admin: ";
        cin >> parola;
        if (parola == parola_admin)
        {
            cout << "Astea sunt toate conturile:" << endl;
            for (int i = 0; i < conturi.size(); i++)
            {
                cout << "Nume: " << conturi[i].getNume() << endl;
                cout << "Prenume: " << conturi[i].getPrenume() << endl;
                cout << "Balanta este: " << conturi[i].getBalanta() << endl;
                cout << "Codul pin este: " << conturi[i].getCodPin() << endl;
            }
        }
        else
        {
            cout << "Parola incorecta!" << endl;
        }
}

void ManagementBanca::cautarecont(int codpin) {
   cout << "Detinatorul contului" << endl;
        for (int i = 0; i < conturi.size(); i++)
        {
            if (conturi[i].getCodPin() == codpin)
            {
                cout << "Nume: " << conturi[i].getNume() << endl;
                cout << "Prenume: " << conturi[i].getPrenume() << endl;
                cout << "Balanta este: " << conturi[i].getBalanta() << endl;
            }
        }
}

ContBancar ManagementBanca::gasestecont(int codPin) {
    ContBancar contGol("", "", 0.0, 0);
        for (int i = 0; i < conturi.size(); i++)
        {
            if (conturi[i].getCodPin() == codPin)
            {
                return conturi[i];
            }
        }
        return contGol;
}

void ManagementBanca::adaugarefinante(int codPin, double suma) {
  ContBancar cont = gasestecont(codPin);
        if (cont.getCodPin() != 0)
        {
            cont.adaugareFinante(suma);
            cout << suma << " adaugate cu succes in contul lui " << cont.getNume() << " " << cont.getPrenume() << endl;
        }
        else
        {
            cout << "Contul nu a fost gasit." << endl;
        }
}

void ManagementBanca::retragere(int codPin, double suma) {
      ContBancar cont = gasestecont(codPin);
        if (cont.getCodPin() != 0)
        {
            cont.retragere(suma);
        }
        else
        {
            cout << "Contul nu a fost gasit." << endl;
        }
}

ContBancar ManagementBanca::formularlogin(ManagementBanca managbanca, int nrIncercari) {
    if (nrIncercari == 0)
        {
            cout << "Ati depasit numarul maxim de incercari. Va rugam sa incercati mai tarziu." << endl;
            exit(0);
        }

        int codPin;
        system("cls");
        cout << "Brasov Central Bank - Autentificare" << endl;
        cout << "Introduceti Codul Pin: ";
        cin >> codPin;
        ContBancar cont = managbanca.gasestecont(codPin);
        if (cont.getCodPin() != 0)
        {
            cout << "Autentificare reusita pentru " << cont.getNume() << " " << cont.getPrenume() << endl;
            return cont;
        }
        else
        {
            cout << "Autentificare esuata. Cod Pin invalid." << endl;
            return formularlogin(managbanca, nrIncercari - 1);
        }
    
}
