#include <iostream>

using namespace std;
#include "BrowserHistory.h"
int main()
{


    BrowserHistory b=BrowserHistory(1);
    BrowserHistory c=BrowserHistory(3);
    for(int i=0; i<1; i++)

    {
        b.addWithConsole();


    }
    cout<<"Enter second browser history"<<endl;
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

    return 0;
}
