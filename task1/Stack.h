/*
* Stack.h
*/

#ifndef STACK_H
#define STACK_H

double const MAX = 100;

class Stack
{
private:
	double *arr;	    // ��������� ����� � ���������� �� �����
	int top;	    // ������ �� ��������� �������
	int size;

	// �������� ���� ������ � �����
	bool full() const;

	void grow();

public:

	// ��������� �� ������ ����
	Stack();
	// ���������
	~Stack();

	// ������� �� ������

	// �������� ���� ���� � ������
	bool empty() const;

	// �������� �� �������� �� ����� �� �����
	double peek() const;

	// ��������

	// ��������� �� �������
	void push(double);

	// ���������� �� �������
	double pop();

};

#endif /* STACK_H_ */
