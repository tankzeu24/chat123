#ifndef BROWSERHISTORY_H
#define BROWSERHISTORY_H
#include "HistoryEntry.h"

class BrowserHistory
{
public:
    BrowserHistory(int newMaxSize);
    virtual ~BrowserHistory();
    BrowserHistory(const BrowserHistory &browserHistory);
    BrowserHistory& operator=(const BrowserHistory &BrowserHistory);
    void addWithConsole();
    void add(const HistoryEntry &historyEntry);
    void printWebsites() const;
    int totalMonths(int givenMonth) const;

    int getMaxSize() const;
    int getCurrentSize() const;
    HistoryEntry getElement(int pos) const;
    int getMaxID();
    BrowserHistory concat(const BrowserHistory &BrowserHistory);

private:


    int maxSize;
    int currentSize;
    HistoryEntry* list;

};

#endif // BROWSERHISTORY_H
