#include "Calculator.h"
using namespace std;
#include "Stack.h"
#include <math.h>
#include <cstring>
Calculator::Calculator()
{
    //ctor
}

Calculator::~Calculator()
{
    //dtor
}


bool Calculator::IsOp(char c)
{
    //Check for operators.
    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
        return true;
    default:
        return false;
    }
}


char* Calculator::appendCharToCharArray(const char* array, const char a)
{
    size_t len = strlen(array);

    char* newChar = new char[len+2];

    strcpy(newChar, array);
    newChar[len] = a;
    newChar[len+1] = '\0';

    return newChar;
}

double Calculator::calcuteRPN(const char* expression)
{
    if(expression==nullptr)
    {
        throw std::invalid_argument("cannot calculate nullptr expression");
    }
    else if(strlen(expression) >100 )
    {
        throw std::invalid_argument("RPN expression longer than 100 symbols");
    }

    int i = 0;
    double v1, v2, stackNumber;
    v1 = stackNumber = v2 = 0.0;
    Stack s;
    const char* inputNumber = ""; //possible number to read

    int totalLength=strlen(expression);


    while (i < totalLength)
    {
        //Skip white space
        while (isspace(expression[i]))
        {
            i++;
        }
        //Check for digits and .
        if (isdigit(expression[i]) || expression[i] == '.')
        {
            while (isdigit(expression[i]) || expression[i] == '.')
            {
                char* newToken=appendCharToCharArray(inputNumber,expression[i]);
                delete inputNumber;
                inputNumber=newToken;
                i++;
            }
            //Push on stack number.
            s.push(atof(inputNumber));
            delete inputNumber; //since we have created something

            inputNumber = ""; //go back to the previous state,since we may read more doubles
        }

        //Check for operator
        else if (IsOp(expression[i]))
        {
            if (expression[i] == '+')
            {
                v1 = s.pop();
                v2 = s.pop();
                stackNumber = (v1 + v2);
            }
            if (expression[i] == '-')
            {
                v1 = s.pop();
                v2 = s.pop();
                stackNumber = v2 - v1;
            }
            if (expression[i] == '*')
            {
                v1 = s.pop();
                v2 = s.pop();
                stackNumber = (v1 * v2);
            }
            if (expression[i] == '/')
            {
                v1 = s.pop();
                v2 = s.pop();

                if(v1==0.0)
                {
                    throw std::invalid_argument("division by 0");
                    break;
                }
                stackNumber = (v2 / v1);
            }
            if(expression[i]=='%')
            {
                v1 = s.pop();
                v2 = s.pop();
                if ( trunc(v1)==v1 && trunc(v2)==v2)
                {

                    stackNumber=( (int)v2 % (int)v1);
                }
                else
                {
                    throw std::invalid_argument("% used with two not whole numbers");
                }
            }

            //increment counter
            i++;
            //Push result onto stack
            s.push(stackNumber);
        }
        else
        {
            throw std::invalid_argument("invalid expression ");
            break;
        }
    }
    delete inputNumber; //delete the pointer we created and assigned value
    //Return answer
    return s.pop();
}
