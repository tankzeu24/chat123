#ifndef HISTORYENTRY_H
#define HISTORYENTRY_H
#include <iostream>
using namespace std;

struct HistoryEntry
{
public:

    HistoryEntry(int month=1,const char* url="default url");
    HistoryEntry(const HistoryEntry &historyEntry);
    HistoryEntry& operator=(const HistoryEntry &historyEntry);
    virtual ~HistoryEntry();


    int getMonth() const;
    char* getURL() const;
    void setURL(const char* url);
    void setMonth(int month);


    friend ostream& operator<<(ostream &os,const HistoryEntry &historyEntry);
    friend istream& operator>>(istream &is, HistoryEntry &historyEntry);

    HistoryEntry copy() const; //returns copy of element

private:

    int month;
    char* url;
};

#endif // HISTORYENTRY_H
