/*
* Stack.cpp
*/

#include "Stack.h"

#include <iostream>
using namespace std;

Stack::Stack()
{
    size = MAX;
    arr = new double[size];
    top = -1; // Празен стек
}

void Stack::grow()
{
    double *newArr = new double[2 * size];
    for (int i = 0; i < size; i++)
        newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
    size *= 2;
}

Stack::~Stack()
{
    delete[] arr;
}

bool Stack::empty() const
{
    return top == -1;
}

double Stack::peek() const
{
    if (empty())
    {
        cout << "Грешка: опит за поглеждане в празен стек!\n";
        return 0;
    }

    return arr[top];
}

void Stack::push(double x)
{
    if (full())
    {
        grow();
    }
    arr[++top] = x;
}

bool Stack::full() const
{
    return top == size - 1;
}

double Stack::pop()
{
    if (empty())
    {
        cout << "Грешка: опит за изключване от празен стек!\n";
        return 0;
    }
    return arr[top--];
}
