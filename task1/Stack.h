/*
* Stack.h
*/

#ifndef STACK_H
#define STACK_H

double const MAX = 100;

class Stack
{
private:
	double *arr;	    // динамичен масив с елементите на стека
	int top;	    // индекс на последния елемент
	int size;

	// проверка дали стекът е пълен
	bool full() const;

	void grow();

public:

	// създаване на празен стек
	Stack();
	// Дестуктор
	~Stack();

	// функции за достъп

	// проверка дали стек е празен
	bool empty() const;

	// намиране на елемента на върха на стека
	double peek() const;

	// мутатори

	// включване на елемент
	void push(double);

	// изключване на елемент
	double pop();

};

#endif /* STACK_H_ */
