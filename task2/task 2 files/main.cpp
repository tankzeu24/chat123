#include <iostream>
using namespace std;

#include "Pair.h"
#include "Settings.h"


int main()
{



    Settings<int> s= Settings<int>();
    s.set("car",10);
    s.set("ball",20);
    s.set("umbrella",40);
    cout<<s;
    s.set("car",11);
    cout<<s;
    s.set("car",12);
    s.set("umbrella",41);
    cout<<s;

    cout<<"======================"<<endl;
    cout<<"Current state of our s object :"<<endl;
    cout<<s<<endl;

    int x=99;
    cout<<s.get("car",x)<<endl; //returns 1 ,indeed there is car in the settings object
    cout<<s.get("building",x)<<endl; //false because there isn't key called "building"
    cout<<s;
    cout<<x<<endl; //indeed x changed from 99 to 12 which is in the settings object called s
    return 0;
}
