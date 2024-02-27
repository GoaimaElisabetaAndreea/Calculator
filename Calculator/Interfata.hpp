#pragma once
#include <iostream>
#include "C:\Users\elisa\Documents\Visual Studio 2022\Templates\ProjectTemplates\Visual C++ Project\Calculator\Calculator\Expresie.hpp"
#include "C:\Users\elisa\Documents\Visual Studio 2022\Templates\ProjectTemplates\Visual C++ Project\Calculator\Calculator\Stack.hpp"
using namespace std;

class Interfata
{
private:
    bool stare;
    Expresie expresie;

public:
    Interfata();
    Interfata(bool stare);

    void setStare(bool);
    bool getStare();

    bool operator!();
    int operator+(int valoare);

    void procesareExpresie();
    void afisare();

    friend ostream& operator<<(ostream& out, const Interfata& i);
    friend istream& operator>>(istream& in, Interfata& i);
}; 
