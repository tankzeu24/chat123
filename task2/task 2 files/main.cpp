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
    cout<<"Let change car to 11"<<endl;
    s.set("car",11);
    cout<<s;
    cout<<"Let change car to 12 and umbrella to 41"<<endl;
    s.set("car",12);
    s.set("umbrella",41);
    cout<<s;

    cout<<"======================"<<endl;

    cout<<"Current state of our s object :"<<endl;
    cout<<s<<endl;

    int x=99;
    cout<<"get [key]= \'car\' with param [value]=99 ,the result is : " <<s.get("car",x)<<endl; //returns 1 ,indeed there is car in the settings object
    cout<<"Did the param change from 99 to 12 ? " <<x<<endl; //indeed x changed from 99 to 12 which is in the settings object called s
    cout<<"get [key]=\'building\' with param [value]=12 ,the result is: "<<s.get("building",x)<<endl; //false because there isn't key called "building"
    cout<<"param [value]=12 was not change : "<<x<<endl;
    cout<<s;

    return 0;
}
