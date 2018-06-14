#include <iostream>
//
using namespace std;
#include "Calculator.h"
#include "math.h"

int main(int argc, char *argv[])
{

    Calculator c = Calculator();
    cout<<c.calcuteRPN("6.0 3.0 %")<<endl ; // 0
    cout<<c.calcuteRPN("   4.0 3.0 %")<<endl ; // 1
    cout<<c.calcuteRPN("   4.0 3 %")<<endl ; // 1
    cout<<c.calcuteRPN("5 1 2 + 4 * + 3 -")<<endl;  // 5 + ((1 + 2) * 4) - 3  equal to  14
    cout<<c.calcuteRPN("15 7 1 1 + - / 3 * 2 1 1 + + -")<<endl;  // ((15 ÷ (7 − (1 + 1))) × 3) − (2 + (1 + 1)) equal to  5

    try
    {
        c.calcuteRPN("######123");


    }
    catch(std::invalid_argument &e)
    {
        cout<< e.what()<<endl;
    }
}
