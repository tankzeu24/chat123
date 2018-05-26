#ifndef PAIR_H
#define PAIR_H
#include<iostream>
using namespace std;
#include <cstring>


template <class T>
class Pair
{
public:
    Pair();
    virtual ~Pair();
    Pair(const char* key,const T &value);
    Pair(const Pair &pair);
    Pair& operator=(const Pair &pair);

    bool operator==(const Pair &pair);
    bool operator!=(const Pair &pair);
    template<class U>
    friend ostream& operator<<(ostream &os,const Pair<U> &pair)
    {
        os<<pair.getKey()<< " "<<pair.getValue()<<endl;
        return os;
    }

    char* getKey() const;
    T getValue() const;
    void setValue( T value);


private:
    void copyKey(const char* key);
    char* key;
    T value;

};




template<class T>
void Pair<T>::copyKey(const char* toCopyKey)
{

    int length=strlen(toCopyKey);
    if(key)
    {
        delete[] key;
    }
    key=new char[length+1];
    strcpy(key,toCopyKey);
}
template<class T>
Pair<T>::Pair()
{

    copyKey("default key");

}



template<class T>
Pair<T>::Pair(const char* key,const T &val ) : key(nullptr)
{
    copyKey(key);
    setValue(val);

}
template<class T>
Pair<T>::~Pair()
{
    delete[] key;
}

template<class T>
Pair<T>::Pair(const Pair &pair) : key(nullptr)
{

    copyKey(pair.getKey());
    setValue(pair.getValue());

}

template<class T>
Pair<T>& Pair<T>::operator=(const Pair &pair)
{
    if(this != &pair)
    {
        copyKey(pair.getKey());
        setValue(pair.getValue());
    }
    return *this;
}


template<class T>
bool Pair<T>::operator==(const Pair<T> &pair)
{
    if(strcmp(getKey(),pair.getKey())==0 && pair.getValue()==pair.getValue())
    {
        return true;
    }
    return false;
}

template<class T>
bool Pair<T>::operator!=(const Pair<T> &pair)
{
    return !(*this==pair);
}


template<class T>
char* Pair<T>::getKey() const
{
    return key;
}

template<class T>
T Pair<T>::getValue() const
{
    return value;
}

template<class T>
void Pair<T>::setValue(T val)
{
    value=val;
}
#endif // PAIR_H
