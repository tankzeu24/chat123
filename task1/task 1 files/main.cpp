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

    cout<<net<<endl;
    ElectricDevice fromNet=net["stove"];
    cout<<"Got this element from the ElectricNet :" <<fromNet<<endl;

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

    return 0;
}
