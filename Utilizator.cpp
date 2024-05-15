#include "Utilizator.h"

Utilizator::Utilizator(string n, string p) : nume(n), prenume(p) {}

string Utilizator::getNume() {
    return nume;
}

string Utilizator::getPrenume() {
    return prenume;
}
