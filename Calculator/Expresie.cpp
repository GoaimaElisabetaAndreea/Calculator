#pragma GCC diagnostic ignored "-Wc++11-extensions"
#pragma warning(disable:4996)
#include "C:\Users\elisa\Documents\Visual Studio 2022\Templates\ProjectTemplates\Visual C++ Project\Calculator\Calculator\Stack.hpp"
#include "C:\Users\elisa\Documents\Visual Studio 2022\Templates\ProjectTemplates\Visual C++ Project\Calculator\Calculator\Expresie.hpp"
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

string Expresie::nume = "Calculator stiintific";
Expresie::Expresie() : PI(3.14159265359)
{
    expresie = nullptr;
    numere = nullptr;
    simboluri = nullptr;
    dimensiune = 0;
    eroare = '0';
}

Expresie::Expresie(const char* expr, double* num, const char* simb, int dim) : PI(3.14159265359)
{
    if (expr != nullptr)
    {
        if (expresie != nullptr)
        {
            delete[] expresie;
            expresie = nullptr;
        }
        expresie = new char[strlen(expr) + 1];
        strcpy(expresie, expr);
    }

    if (num != nullptr && dim > 0)
    {
        if (numere != nullptr)
        {
            delete[] numere;
            numere = nullptr;
        }
        numere = new double[dim];
        for (int i = 0; i < dim; i++)
        {
            numere[i] = num[i];
        }
    }

    if (simb != nullptr)
    {
        if (simboluri != nullptr)
        {
            delete[] simboluri;
            simboluri = nullptr;
        }
        simboluri = new char[strlen(simb) + 1];
        strcpy(simboluri, simb);
    }
}

string Expresie::getNume()
{
    return nume;
}
void Expresie::setNume(string nume)
{
    Expresie::nume = nume;
}

void Expresie::setExpresie(const char* expr)
{
    if (expr != nullptr)
    {
        if (expresie != nullptr)
        {
            delete[] expresie;
            expresie = nullptr;
        }
        expresie = new char[strlen(expr) + 1];
        strcpy(expresie, expr);
    }
}

char* Expresie::getExpresie()
{
    char* copie = new char[strlen(expresie) + 1];
    if (expresie != nullptr)
    {
        strcpy(copie, expresie);
    }
    return copie;
}

void Expresie::setNumere(double* num, int dim)
{
    if (num != nullptr && dim > 0)
    {
        if (numere != nullptr)
        {
            delete[] numere;
            numere = nullptr;
        }
        numere = new double[dim];
        for (int i = 0; i < dim; i++)
        {
            numere[i] = num[i];
        }
    }
}

double* Expresie::getNumere()
{
    double* copie = new double[dimensiune];
    if (numere != nullptr)
    {
        for (int i = 0; i < dimensiune; i++)
            copie[i] = numere[i];
    }
    return copie;
}

char* Expresie::getSimboluri()
{
    char* copie = new char[strlen(simboluri) + 1];
    if (simboluri != nullptr)
    {
        strcpy(copie, simboluri);
    }
    return copie;
}

void Expresie::setSimboluri(const char* simb)
{
    if (simb != nullptr)
    {
        if (simboluri != nullptr)
        {
            delete[] simboluri;
            simboluri = nullptr;
        }
        simboluri = new char[strlen(simb) + 1];
        strcpy(simboluri, simb);
    }
}

void Expresie::setDimensiune(int dimensiune)
{
    if (dimensiune > 0)
    {
        this->dimensiune = dimensiune;
    }
}

int Expresie::getDimensiune()
{
    return dimensiune;
}

Expresie::~Expresie()
{
    if (simboluri != nullptr)
    {
        delete[] simboluri;
        simboluri = nullptr;
    }

    if (numere != nullptr)
    {
        delete[] numere;
        numere = nullptr;
    }

    if (expresie != nullptr)
    {
        delete[] expresie;
        expresie = nullptr;
    }
}
const double Expresie::getPI()
{
    return PI;
}

Expresie& Expresie::operator=(const Expresie& e)
{
    if (this != &e)
    {
        if (this->expresie != nullptr)
        {
            delete[] this->expresie;
            this->expresie = nullptr;
        }
        if (e.expresie != nullptr)
        {
            this->expresie = new char[strlen(e.expresie) + 1];
            strcpy(this->expresie, e.expresie);
        }
        if (this->numere != nullptr)
        {
            delete[] this->numere;
            this->numere = nullptr;
        }
        if (e.numere != nullptr && e.dimensiune > 0)
        {
            this->numere = new double[e.dimensiune];
            for (int i = 0; i < e.dimensiune; i++)
            {
                this->numere[i] = e.numere[i];
            }
            this->dimensiune = e.dimensiune;
        }
        if (e.simboluri != nullptr)
        {
            this->simboluri = new char[strlen(e.simboluri) + 1];
            strcpy(this->simboluri, e.simboluri);
        }
    }

    return *this;
}

Expresie::Expresie(const Expresie& expr) : PI(3.14159265359)
{
    if (expr.expresie != nullptr)
    {
        expresie = new char[strlen(expr.expresie) + 1];
        strcpy(expresie, expr.expresie);
    }
    else
        expresie = nullptr;

    if (expr.simboluri != nullptr)
    {
        simboluri = new char[strlen(expr.simboluri) + 1];
        strcpy(simboluri, expr.simboluri);
    }
    else
        simboluri = nullptr;

    if (expr.numere != nullptr && expr.dimensiune > 0)
    {
        numere = new double[expr.dimensiune];
        for (int i = 0; i < expr.dimensiune; i++)
            numere[i] = expr.numere[i];
        dimensiune = expr.dimensiune;
    }
    else
    {
        numere = nullptr;
        dimensiune = 0;
    }
}

char& Expresie::operator[](int index)
{
    if (index >= 0 && index < dimensiune)
    {
        return expresie[index];
    }
    else
        return eroare;
}

ostream& operator<<(ostream& out, const Expresie& expr)
{
    out << "Expresia: " << expr.expresie << endl;

    out << "Simboluri: ";
    for (int i = 0; i < expr.dimensiune; i++)
    {
        out << expr.simboluri[i] << " ";
    }
    out << endl;

    out << "Numere: ";
    for (int i = 0; i < expr.dimensiune; i++)
    {
        out << expr.numere[i] << " ";
    }
    out << endl;

    return out;
}

istream& operator>>(istream& in, Expresie& expr)
{
    cout << "Expresie: ";

    string expresie;
    getline(in, expresie);

    expr.setExpresie(expresie.c_str());

    return in;
}

bool Expresie::operator!()
{
    return expresie == nullptr;
}

Expresie::operator int()
{
    return dimensiune;
}

bool Expresie::esteOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '#');
}

int Expresie::getPrecedenta(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^' || c == '#')
        return 3;
    else if (c == '(')
        return 4;
    else if (c == '[')
        return 5;
    return 0;
}

void Expresie::shuntingYard(const string& infixExpresie)
{
    string postfixExpresie;
    Stack operatorStack(100);

    string expresieConvertita = infixExpresie;
    convertParantezePatrate(expresieConvertita);

    for (size_t i = 0; i < expresieConvertita.size(); ++i)
    {
        char c = expresieConvertita[i];
        if (isdigit(c))
        {
            postfixExpresie += c;
        }
        else if (esteOperator(c))
        {
            while (!operatorStack.isEmpty() && getPrecedenta(operatorStack.peek()) >= getPrecedenta(c))
            {
                postfixExpresie += operatorStack.pop();
            }
            operatorStack.push(c);
        }
        else if (c == '(')
        {
            operatorStack.push(c);
        }
        else if (c == ')')
        {
            while (!operatorStack.isEmpty() && operatorStack.peek() != '(')
            {
                postfixExpresie += operatorStack.pop();
            }
            operatorStack.pop(); // Elimina '(' din stiva
        }
    }

    while (!operatorStack.isEmpty())
    {
        postfixExpresie += operatorStack.pop();
    }

    evaluarePostfix(postfixExpresie);
}

void Expresie::convertParantezePatrate(string& expresie)
{
    for (size_t index = 0; index < expresie.size(); ++index)
    {
        char& c = expresie[index];
        if (c == '[')
            c = '(';
        else if (c == ']')
            c = ')';
    }
}

void Expresie::evaluarePostfix(const string& postfixExpresie)
{
    Stack operandStack(100);
    double rezultat = 0.0;
    bool eroare = false;

    for (size_t i = 0; i < postfixExpresie.size(); i++)
    {
        char c = postfixExpresie[i];
        if (isdigit(c))
        {
            operandStack.push(c - '0');
        }
        else if (esteOperator(c))
        {
            double operand2 = operandStack.pop();
            double operand1 = operandStack.pop();

            switch (c)
            {
            case '+':
                rezultat = operand1 + operand2;
                operandStack.push(rezultat);
                break;
            case '-':
                rezultat = operand1 - operand2;
                operandStack.push(rezultat);
                break;
            case '*':
                rezultat = operand1 * operand2;
                operandStack.push(rezultat);
                break;
            case '/':
                if (operand2 != 0)
                {
                    rezultat = operand1 / operand2;
                    operandStack.push(rezultat);
                }
                else
                {
                    cout << "Eroare! Impartire la 0." << endl;
                    eroare = true;
                }
                break;
            case '^':
                rezultat = pow(operand1, operand2);
                operandStack.push(rezultat);
                break;
            case '#':
                rezultat = pow(operand1, 1.0 / operand2);
                operandStack.push(rezultat);
                break;
            }
        }
    }

    if (!eroare)
    {
        cout << "Rezultat: " << rezultat << endl;
    }
}



