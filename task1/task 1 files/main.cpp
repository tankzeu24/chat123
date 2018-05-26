#include <iostream>

using namespace std;
#include "List.h"
#include "ElectricDevice.h"
#include "ElectricNet.h"

int main()
{




ElectricNet net =ElectricNet(10);

ElectricDevice a = ElectricDevice("stove",3);
net+=a;
ElectricDevice b = ElectricDevice("lamp",4);
net+=b;
net-=a;

cout<<!net<<endl;
net--;
net--;
cout<<net;
    /*

List<int> mylist= List<int>();
mylist.add(5);
mylist.add(14);
mylist.add(30);
mylist.printList();

List<int> b=List<int>();
b.add(99);
b.printList();
b=mylist;

b.printList();
b.remove(5);

mylist.printList();
b.printList();

*/
    return 0;
}
