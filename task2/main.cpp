#include <iostream>
using namespace std;
#include "BrowserHistory.h"



int main()
{


    cout<<"============="<<endl;
    BrowserHistory browserCommons = BrowserHistory(5);
    browserCommons.add( HistoryEntry(1,"test"));
    browserCommons.add( HistoryEntry(2,"test"));
    browserCommons.add( HistoryEntry(2,"test"));
    browserCommons.add( HistoryEntry(2,"test"));
    browserCommons.add( HistoryEntry(4,"test"));

    cout<<"Month 2(february) is in the history  "<<browserCommons.totalMonths(2)<< " times"<<endl;

    cout<<"Most visited months are in month number : " <<browserCommons.getMaxID()<<endl; //should be 2
    cout<<"Current state of browserCommons"<<endl;
    browserCommons.printWebsites(); // month 4 is gone from browserCommons

    cout<<"============="<<endl;

    BrowserHistory d1=browserCommons; //memory leak test
    BrowserHistory d2(browserCommons); //memory leak test

    BrowserHistory secondHistory =BrowserHistory(4);
    secondHistory.add(HistoryEntry(10,"www.google.com"));
    secondHistory.add(HistoryEntry(10,"www.google.com"));
    secondHistory.add(HistoryEntry(11,"www.sporal.bg"));


    BrowserHistory concatedHistory=browserCommons.concat(secondHistory);
    cout<<"Concat result is"<<endl;
    concatedHistory.printWebsites();

    cout<<"Change concated history"<<endl;
    cout<<"Most visited months are in month number : " <<concatedHistory.getMaxID()<<endl;//should be 2 again
    cout<<"Current state of concatedHistory object"<<endl;
    concatedHistory.printWebsites();

    cout<<"The two objects browserCommons and secondHistory didn't change"<<endl;
    cout<<"browserCommons state is : "<<endl;
    browserCommons.printWebsites();
    cout<<"secondHistory state is : "<<endl;
    secondHistory.printWebsites();




    return 0;
}
