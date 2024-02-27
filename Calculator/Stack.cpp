#pragma warning(disable:4996)
#include "C:\Users\elisa\Documents\Visual Studio 2022\Templates\ProjectTemplates\Visual C++ Project\Calculator\Calculator\Stack.hpp"
#include <iostream>
#include <string>
using namespace std;

Stack::Stack()
{
    capacitate = 0;
    date = nullptr;
    top = -1;
}

Stack::Stack(int maxDim)
{
    capacitate = maxDim;
    date = new char[capacitate];
    top = -1;
}

Stack::~Stack()
{
    delete[] date;
}

int Stack::getCapacitate()
{
    return capacitate;
}
void Stack::setCapacitate(int capacitate)
{
    if (capacitate > 0)
    {
        this->capacitate = capacitate;
    }
}

int Stack::getTop()
{
    return top;
}

void Stack::setTop(int top)
{
    if (top >= -1)
    {
        this->top = top;
    }
}

char* Stack::getDate()
{
    char* copie = new char[strlen(date) + 1];
    if (date != nullptr)
    {
        strcpy(copie, date);
    }
    return copie;
}

int Stack::size() const
{
    return top + 1;
}

void Stack::setDate(const char* date)
{
    if (date != nullptr)
    {
        if (this->date != nullptr)
        {
            delete[] this->date;
            date = nullptr;
        }
        this->date = new char[strlen(date) + 1];
        strcpy(this->date, date);
    }
}

Stack& Stack::operator=(const Stack& s)
{
    if (this != &s)
    {
        if (this->date != nullptr)
        {
            delete[] this->date;
            this->date = nullptr;
        }
        if (s.date != nullptr)
        {
            this->date = new char[strlen(s.date) + 1];
            strcpy(this->date, s.date);
        }
        this->capacitate = s.capacitate;
        this->top = s.top;
    }
    return *this;
}

Stack::Stack(const Stack& s)
{
    if (this->date != nullptr)
    {
        delete[] this->date;
        this->date = nullptr;
    }
    if (s.date != nullptr)
    {
        this->date = new char[strlen(s.date) + 1];
        strcpy(this->date, s.date);
    }
    this->capacitate = s.capacitate;
    this->top = s.top;
}

Stack& Stack::operator++()
{
    capacitate++;
    return *this;
}

Stack Stack::operator++(int i)
{
    Stack copie = *this;
    capacitate++;
    return copie;
}

Stack& Stack::operator--()
{
    capacitate--;
    return *this;
}

Stack Stack::operator--(int i)
{
    Stack copie = *this;
    capacitate--;
    return copie;
}

void Stack::push(char element)
{
    if (top < capacitate - 1)
    {
        top++;
        date[top] = element;
    }
}

char Stack::pop()
{
    if (top >= 0)
    {
        char element = date[top];
        top--;
        return element;
    }
    return '\0';
}

char Stack::peek() const
{
    if (top >= 0)
    {
        return date[top];
    }
    return '\0';
}

bool Stack::isEmpty() const
{
    return top == -1;
}

ostream& operator<<(ostream& out, const Stack& s)
{
    out << "Capacitate: " << s.capacitate << endl;
    out << "Top: " << s.top << endl;
    out << "Expresie: " << s.date << endl;
    return out;
}

istream& operator>>(istream& in, Stack& s)
{
    cout << "Expresie: ";
    string expresie;
    getline(in, expresie);
    s.setDate(expresie.c_str());
    cout << "Capacitate: ";
    in >> s.capacitate;
    cout << "Top: ";
    in >> s.top;
    return in;
}