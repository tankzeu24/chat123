#include <iostream>
using namespace std;
#include "BrowserHistory.h"



int main()
{
    BrowserHistory b=BrowserHistory(1);
    BrowserHistory c=BrowserHistory(3);

      cout<<"Enter first browser history (1 element only)"<<endl;
    b.addWithConsole();



    cout<<"Enter second browser history (3 elements only)"<<endl;
    for(int i=0; i<3; i++)
    {
        c.addWithConsole();
    }
    cout<<"First BrowserHistory is with 1 element"<<endl;
    b.printWebsites();
    cout<<"First BrowserHistory is with 3 elements"<<endl;
    c.printWebsites();
    cout<<" most common element from the second list is "<<endl;
    cout<<c.getMaxID()<<endl;
    cout<<"Second list changed to : "<<endl;
    c.printWebsites();

    BrowserHistory d1=b;
    BrowserHistory d2(d1);


    return 0;
}
