#include "HistoryEntry.h"
#include <cstring>
#include <iostream>
using namespace std;

HistoryEntry::HistoryEntry(int newMonth,const char* newURL) :url(nullptr)
{
    setMonth(newMonth);
    setURL(newURL);
}

HistoryEntry::~HistoryEntry()
{
    //dtor
}
HistoryEntry::HistoryEntry(const HistoryEntry &historyEntry) :url(nullptr)
{
    setMonth(historyEntry.getMonth());
    setURL(historyEntry.getURL());

}

HistoryEntry& HistoryEntry::operator=(const HistoryEntry &historyEntry)
{
    if(this != &historyEntry)
    {
        setMonth(historyEntry.getMonth());
        setURL(historyEntry.getURL());

    }
    return *this;
}

void HistoryEntry::setMonth(int newMonth)
{
    if( newMonth<1 || newMonth>12 )
    {
        throw std::invalid_argument("month not in range [1;12]");

    }

    month=newMonth;
}

void HistoryEntry::setURL(const char* newURL)
{
    delete[] url;
    int length=strlen(newURL);
    url =new char[length];
    strcpy(url,newURL);
}

int HistoryEntry::getMonth() const
{
    return month;
}

char* HistoryEntry::getURL() const
{
    return url;
}

ostream& operator<<(ostream &os,const HistoryEntry &historyEntry)
{
    os<<historyEntry.getMonth()<< " "<<historyEntry.getURL()<<endl;
    return os;
}

istream& operator>>(istream &is,HistoryEntry &historyEntry)
{
    char url[50];
    cout<<"Enter url"<<endl;
    is.getline(url,50);
    historyEntry.setURL(url);
    cout<<"Enter month"<<endl;
    int month;
    is>>month;
    historyEntry.setMonth(month);
    return is;
}
HistoryEntry HistoryEntry::copy() const
{
    return  HistoryEntry(*this);
}
