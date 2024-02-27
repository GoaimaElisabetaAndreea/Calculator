#include "C:\Users\elisa\Documents\Visual Studio 2022\Templates\ProjectTemplates\Visual C++ Project\Calculator\Calculator\Interfata.hpp"
#include "C:\Users\elisa\Documents\Visual Studio 2022\Templates\ProjectTemplates\Visual C++ Project\Calculator\Calculator\Expresie.hpp"
#include "C:\Users\elisa\Documents\Visual Studio 2022\Templates\ProjectTemplates\Visual C++ Project\Calculator\Calculator\Stack.hpp"
#include <iostream>
using namespace std;

Interfata::Interfata(bool stare)
{
    this->stare = stare;
}

Interfata::Interfata()
{
    stare = true;
}

void Interfata::setStare(bool stare)
{
    this->stare = stare;
}

bool Interfata::getStare()
{
    return stare;
}

bool Interfata::operator!()
{
    return stare == true;
}

int Interfata::operator+(int valoare)
{
    valoare += expresie.getDimensiune() + valoare;
    return valoare;
}

void Interfata::afisare()
{
    cout << "Tasteaza exit pentru a iesi din program" << endl;
}

void Interfata::procesareExpresie()
{
    stare = this->getStare();
    Expresie expresie;
    string infixExpresie;
    while (stare)
    {
        cout << "Introdu o expresie: ";
        getline(cin, infixExpresie);
        if (infixExpresie == "exit")
        {
            this->setStare(false);
        }
        else
        {
            expresie.shuntingYard(infixExpresie);
        }
        stare = this->getStare();
    }
}

ostream& operator<<(ostream& out, const Interfata& i)
{
    out << i.expresie;
    return out;
}

istream& operator>>(istream& in, Interfata& i)
{
    in >> i.expresie;
    return in;
}