#ifndef STACK_H
#define STACK_H

double const MAX = 100;

class Stack
{
private:
    double *arr;
    int top;	    // индекс на последния елемент
    int size;


    bool full() const;

    void grow();

public:


    Stack();
    Stack(const Stack& stack)=delete;
    Stack& operator=(const Stack &stack)=delete;

    ~Stack();

    bool empty() const;

    double peek() const;

    void push(double);

    double pop();

};

#endif /* STACK_H_ */
