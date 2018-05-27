#include <iostream>

using namespace std;
#include "List.h"
#include "ElectricDevice.h"
#include "ElectricNet.h"

int main()
{


    ElectricNet net =ElectricNet(10);
    cout<<"Is there something in the net? : "<<!net<<endl;
    cout<<"check one more time with ! operator? : "<<!net<<endl;

    ElectricDevice stove = ElectricDevice("stove",3);
    net+=stove;
    cout<<"There are devices in the net ? : "<<!net<<endl;
    ElectricDevice lamp = ElectricDevice("lamp",4);
    net+=lamp;

    cout<<"Current state of the net : "<<endl;
    cout<<net<<endl;
    cout<<"Try to add big device with consumption 99 : "<<endl;
    ElectricDevice bigDevice = ElectricDevice("big device",99);
    net+=bigDevice;
    cout<<"Retrieve the device called \'stove\' from the net"<<endl;
    ElectricDevice fromNet=net["stove"];
    cout<<"Got this element from the ElectricNet with [] operator :" <<fromNet<<endl;

    ElectricNet copyNet=net;
    cout<<copyNet;
    net-=lamp;

    cout<<"-------"<<endl;

    copyNet++;
    copyNet+=stove;
    cout<<net<<endl;
    cout<<copyNet<<endl;

    cout<<"-------"<<endl;

    cout<<"[ Corner case with maxConsumption=3 ] "<<endl;
    ElectricNet smallNet=ElectricNet(3);
    smallNet--;
    cout<<smallNet;
    smallNet--;
    cout<<smallNet;

    cout<<"--------"<<endl;
    cout<<"example of + operator"<<endl;
    ElectricNet someNet=ElectricNet(15);
    ElectricDevice dev=ElectricDevice("mixer",4);
    ElectricNet firstNet=someNet+dev;
    cout<<"Result from + operator : "<<endl; //ElectricNet firstNet=dev+someNet is the same;
    cout<<firstNet<<endl;
    cout<<"Result from - operator : "<<endl;
    ElectricNet secondNet=firstNet-dev; // ElectricNet secondNet=dev-firstNet is the same
    cout<<secondNet;


    return 0;
}
