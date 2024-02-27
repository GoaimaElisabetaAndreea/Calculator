#pragma once
#include <iostream>
using namespace std;

class Stack
{
private:
    char* date;
    int capacitate;
    int top;

public:
    Stack();
    Stack(int maxDim);
    Stack(const Stack& s);
    ~Stack();

    int getCapacitate();
    void setCapacitate(int);

    int getTop();
    void setTop(int);

    char* getDate();
    void setDate(const char*);

    Stack& operator=(const Stack& s);

    Stack& operator++();
    Stack operator++(int);
    Stack& operator--();
    Stack operator--(int);

    char pop();
    void push(char);
    int size() const;
    char peek() const;

    bool isEmpty() const;

    friend ostream& operator<<(ostream& out, const Stack& calc);
    friend istream& operator>>(istream& in, Stack& calc);
};
