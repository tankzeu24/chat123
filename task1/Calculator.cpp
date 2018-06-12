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


char* Calculator::appendCharToCharArray(char* array, const char a)
{
    size_t len = strlen(array);

    char* ret = new char[len+2];

    strcpy(ret, array);
    ret[len] = a;
    ret[len+1] = '\0';

    return ret;
}

double Calculator::calcuteRPN(const char* expression)
{
    int i = 0;
    double v1, v2, ret;
    v1 = ret = v2 = 0.0;
    Stack s;
    char* tok = "";
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
                char* newToken=appendCharToCharArray(tok,expression[i]);
                delete tok;
                tok=newToken;
                delete newToken;
                i++;
            }
            //Push on stack number.
            s.push(atof(tok));
            delete tok;

            tok = "";
        }
        //Check for operator
        else if (IsOp(expression[i]))
        {
            if (expression[i] == '+')
            {
                v1 = s.pop();
                v2 = s.pop();
                ret = (v1 + v2);
            }
            if (expression[i] == '-')
            {
                v1 = s.pop();
                v2 = s.pop();
                ret = v2 - v1;
            }
            if (expression[i] == '*')
            {
                v1 = s.pop();
                v2 = s.pop();
                ret = (v1 * v2);
            }
            if (expression[i] == '/')
            {
                v1 = s.pop();
                v2 = s.pop();

                if(v1==0.0)
                {
                    throw std::invalid_argument("division by 0"); //todo without std
                    break;
                }
                ret = (v2 / v1);
            }
            if(expression[i]=='%')
            {
                v1 = s.pop();
                v2 = s.pop();
                if ( trunc(v1)==v1 && trunc(v2)==v2)
                {
                    ret=( (int)v2 % (int)v1);
                }
                else
                {
                    throw std::invalid_argument("% used with two not whole numbers"); //todo without std
                }
            }

            //INC Counter
            i++;
            //Push result onto stack
            s.push(ret);
        }
        else
        {
            throw std::invalid_argument("invalid expression "); //todo without std
            break;
        }
    }
    //Return answer
    return s.pop();
}
