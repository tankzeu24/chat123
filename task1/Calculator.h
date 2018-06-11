#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>
#include<iostream>
using namespace std;

class Calculator
{
    public:
        Calculator();
        virtual ~Calculator();

     bool IsOp(char c);
     double RPN(string expression);
    private:

};

#endif // CALCULATOR_H
