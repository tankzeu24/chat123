#include <iostream>
//
using namespace std;
#include "Calculator.h"
#include "math.h"

int main(int argc, char *argv[]){

    Calculator c = Calculator();
    cout<<c.RPN("6.0 5.0 %");

}
