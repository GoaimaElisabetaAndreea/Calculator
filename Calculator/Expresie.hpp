#pragma GCC diagnostic ignored "-Wc++11-extensions"
#pragma once
#include <iostream>
#include "C:\Users\elisa\Documents\Visual Studio 2022\Templates\ProjectTemplates\Visual C++ Project\Calculator\Calculator\Stack.hpp"
#include <string>
#include <cctype>
using namespace std;

class Expresie
{
private:
    char* expresie;
    double* numere;
    char* simboluri;
    int dimensiune;
    char eroare;
    const double PI;
    static string nume;

public:
    Expresie();
    Expresie(const char* expr, double* num, const char* simb, int dim);
    Expresie(const Expresie& expr);
    Expresie& operator=(const Expresie& expr);

    ~Expresie();

    char* getExpresie();
    void setExpresie(const char*);

    double* getNumere();
    void setNumere(double*, int);

    char* getSimboluri();
    void setSimboluri(const char* simb);

    int getDimensiune();
    void setDimensiune(int);

    const double getPI();

    string getNume();
    void setNume(string nume);

    bool operator!();
    char& operator[](int index);

    bool esteOperator(char c);
    int getPrecedenta(char op);
    void shuntingYard(const string& infixExpression);
    void convertParantezePatrate(string& expresie);
    void evaluarePostfix(const string& postfixExpression);
    explicit operator int();

    friend ostream& operator<<(ostream& out, const Expresie& expr);
    friend istream& operator>>(istream& in, Expresie& expr);
};

