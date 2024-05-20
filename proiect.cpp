#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <cmath>

using namespace std;

class Utilizator
{
protected:
    string nume;
    string prenume;

public:
    Utilizator(string n, string p) : nume(n), prenume(p) {}

    string getNume()
    {
        return nume;
    }

    string getPrenume()
    {
        return prenume;
    }
};

class ContBancar : public Utilizator
{
private:
    double balanta;
    int cod_pin;

public:
    ContBancar(string n, string p, double bal, int cp) : Utilizator(n, p), balanta(bal), cod_pin(cp) {}

    string getNume()
    {
        return nume;
    }
    string getPrenume()
    {
        return prenume;
    }
    double getBalanta()
    {
        return balanta;
    }

    int getCodPin()
    {
        return cod_pin;
    }

    void adaugareFinante(double suma)
    {
        balanta += suma;
    }

    void retragere(double suma2)
    {
        if (suma2 > balanta)
            cout << "Fonduri insuficiente" << endl;
        else
        {
            balanta -= suma2;
            cout << "Retragere succes" << endl;
        }
    }
};

class ManagementBanca : public Utilizator
{
private:
    vector<ContBancar> conturi;
    string parola_admin = "admin123";

public:
    ManagementBanca(string n, string p) : Utilizator(n, p) {}

    void adaugarecont(string n, string p, double bal, int cp)
    {
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

    void vizualizareconturi()
    {
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

    void cautarecont(int codpin)
    {
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

    ContBancar gasestecont(int codPin)
    {
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

    void adaugarefinante(int codPin, double suma)
    {
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

    void retragere(int codPin, double suma)
    {
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

    ContBancar formularlogin(ManagementBanca managbanca, int nrIncercari = 3)
    {
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
};

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
    AplicareCredit(string n, string p, string adr, string emaill, double cs, int durata, string dece, double dob, double salar, double datorii, string istoriccredit)
        : Utilizator(n, p), adresa(adr), email(emaill), creditsuma(cs),
          duratacreditului(durata), dececredit(dece), dobanda(dob),
          salariu(salar), datorii(datorii), altecrediteavute(istoriccredit) {}

    double calculeazaRata()
    {
        double rataLunara = calculeazaDobandaLunara();
        int numarLuni = duratacreditului;
        double rata = (creditsuma * rataLunara) / (1 - pow(1 + rataLunara, -numarLuni));
        return rata;
    }

    double calculeazaDobandaLunara()
    {
        double rataAnuala = dobanda / 100;
        double rataLunara = rataAnuala / 12;
        return rataLunara;
    }

    double calculeazaDobandaFinala()
    {
        double rataLunara = calculeazaDobandaLunara();
        int numarLuni = duratacreditului;
        double sumaFinala = creditsuma * pow(1 + rataLunara, numarLuni);
        return sumaFinala - creditsuma;
    }

    bool verificaEligibilitate()
    {
       
        if (salariu < 1500)
        {
            cout << "Salariul dvs. nu îndeplinește cerința minimă de 1500 RON." << endl;
            return false;
        }

     
        double rataLunara = calculeazaRata();
        if (rataLunara > 0.4 * salariu)
        {
            cout << "Rata lunară depășește 40% din salariul dvs." << endl;
            return false;
        }

       
        if (datorii > 5000)
        {
            cout << "Aveti datorii restante semnificative de peste 5000 RON." << endl;
            return false;
        }

        
        if (altecrediteavute.find("intarzieri frecvente") != string::npos)
        {
            cout << "Aveti un istoric de credit cu intarzieri frecvente." << endl;
            return false;
        }

        return true;
    }

    void aratainfo()
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
};

class InterfataBancara
{
private:
    ManagementBanca managbanca;
    vector<AplicareCredit> aplicatii_credit;

public:
    InterfataBancara() : managbanca("admin", "admin")
    {
        managbanca.adaugarecont("admin", "admin", 10000, 1234);
        managbanca.formularlogin(managbanca);
    }

    void adaugaAplicatieCredit(string nume, string prenume, string adresa, string email, double creditsuma, int duratacreditului, string dececredit, double dobanda, double salariu, double datorii, string altecrediteavute)
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

    void afiseazaAplicatiiCredit()
    {
        cout << "Lista aplicatiilor de credit:\n";
        for (auto &aplicatie : aplicatii_credit)
        {
            aplicatie.aratainfo();
            cout << endl;
        }
    }

    void logicainterfetei()
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
            cout << "5. Aplica pentru un credit" << endl;
            cout << "6. IESIRE" << endl;
            cout << "0000. Arata toate conturile" << endl;
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
                afiseazaAplicatiiCredit();
                break;
            }
            case 6:
            {
                cout << "La revedere!";
                managbanca.formularlogin(managbanca);
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
};

int main()
{
    InterfataBancara interfata;
    interfata.logicainterfetei();
    return 0;
}
