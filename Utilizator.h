#ifndef UTILIZATOR_H
#define UTILIZATOR_H

#include <string>
using namespace std;

class Utilizator {
protected:
    string nume;
    string prenume;

public:
    Utilizator(string n, string p);

    string getNume();

    string getPrenume();
};

#endif // UTILIZATOR_H
