#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<iostream>
using namespace std;

class Calculator
{
public:
    Calculator();
    virtual ~Calculator();
    double calcuteRPN(const char* expression);

private:
    bool IsOp(char c);
    char* appendCharToCharArray(const char* array, const char a);

};

#endif // CALCULATOR_H
