#include "BrowserHistory.h"

BrowserHistory::BrowserHistory(int newMaxSize)
{
    if(newMaxSize < 1)
    {
        throw std::invalid_argument("invalid size number  ,must be >0");
    }
    list=new HistoryEntry[newMaxSize];
    N=newMaxSize;
    currentSize=0;
}



BrowserHistory::BrowserHistory(const BrowserHistory& browserHistory)
{
    N=browserHistory.getMaxSize();
    currentSize=browserHistory.getCurrentSize();
    list=new HistoryEntry[N];
    for(int i=0; i<currentSize; i++)
    {
        list[i]=browserHistory.getElement(i);
    }
}

BrowserHistory& BrowserHistory::operator=(const BrowserHistory& browserHistory)
{
    if(this != &browserHistory)
    {
        N=browserHistory.getMaxSize();
        currentSize=browserHistory.getCurrentSize();
        delete[] list;
        list=new HistoryEntry[N];
        for(int i=0; i<currentSize; i++)
        {
            list[i]=browserHistory.getElement(i);
        }

    }
    return *this;
}
BrowserHistory::~BrowserHistory()
{
    delete[] list;
}

HistoryEntry BrowserHistory::getElement(int pos) const
{
    if( pos<0  || pos>=currentSize)
    {
        throw std::invalid_argument("out of range error");
    }
    return list[pos].copy(); //return copies :)

}
int BrowserHistory::getCurrentSize() const
{
    return currentSize;
}

int BrowserHistory::getMaxSize() const
{
    return N;
}

void BrowserHistory::addWithConsole()
{
    if (currentSize == N)
    {
        throw std::invalid_argument("you cannot add anymore elements");
    }

    cin >> list[currentSize++];
    cin.ignore();
}

void BrowserHistory::add(const HistoryEntry &historyEntry)
{
    if (currentSize == N)
    {
        throw std::invalid_argument("you cannot add anymore elements");
    }

    list[currentSize++]=historyEntry;

}

void BrowserHistory::printWebsites() const
{
    for(int i=0; i<currentSize; i++)
    {
        cout<<list[i]<<endl;
    }
}

int BrowserHistory::totalMonths(int givenMonth) const
{
    if( givenMonth<1 || givenMonth>12 )
    {
        throw std::invalid_argument("month not in range");

    }

    int counter=0;
    for(int i=0; i<currentSize; i++)
    {
        if(list[i].getMonth()==givenMonth)
        {
            counter++;
        }
    }
    return counter;
}

int BrowserHistory::getMaxID()
{


    if(currentSize==0)
    {
        //no point in searching
        throw std::invalid_argument("empty list exception");
    }

    if(currentSize==1)
    {
        //return the current element which is only one
        currentSize--;
        return list[0].getMonth();
    }




    //find the id of the most common month
    int count = 0, curr_cnt = 1, freq_num = 0, key = 0;
    for(int i = 0; i < currentSize-1; i++)
    {
        key = list[i].getMonth();
        for(int j =i+1; j < currentSize; j++)
        {
            if(key == list[j].getMonth() && freq_num != key)
            {
                curr_cnt++;
            }
        }
        if(count < curr_cnt)
        {
            count = curr_cnt;
            curr_cnt = 1;
            freq_num = key;
        }
    }


    //reduce the elements by 1 and return the value
    currentSize--;
    return freq_num;
}


BrowserHistory BrowserHistory::concat(const BrowserHistory& browserHistory)
{
    //get total elements to be added
    int newCurrentSize=getCurrentSize()+browserHistory.getCurrentSize();

    //make new object with x2 newCurrentSize so we can further add
    BrowserHistory newBrowser=BrowserHistory(newCurrentSize*2);
    for(int i=0; i<getCurrentSize(); i++)
    {
        newBrowser.add(getElement(i));
    }
    for(int i=0; i<browserHistory.getCurrentSize(); i++)
    {
        newBrowser.add(browserHistory.getElement(i));
    }
    return newBrowser;
}
