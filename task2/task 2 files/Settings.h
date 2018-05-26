#ifndef SETTINGS_H
#define SETTINGS_H
#include "List.h"
#include "Pair.h"
#include<iostream>
using namespace std;

template<class T>
class Settings
{
public:
    Settings();
    virtual ~Settings();
    Settings(const Settings &settings);
    Settings& operator=(const Settings &settings);

    template<class U>
    friend ostream& operator<<(ostream &os, const Settings<U> &settings);



    int count() const;
    void set(const char* key,const T value);
    bool get(const char* key, T &value);
protected:

private:
    const List<Pair<T>>& getPairs() const;
    List<Pair<T>> pairs;
};



template <class T>
const List<Pair<T>>& Settings<T>::getPairs() const
{
    return pairs;
}

template <class T>
Settings<T>::Settings()
{
    pairs=List<Pair<T>>();
}

template <class T>
Settings<T>::~Settings()
{
    //dtor
}

template <class T>
Settings<T>::Settings(const Settings<T>  &settings)
{
    pairs=settings.getPairs();
}

template <class T>
Settings<T>& Settings<T>::operator=(const Settings<T> &settings)
{
    if(this != &settings)
    {
        pairs=settings.getPairs();

    }
    return *this;
}

template<class T>
ostream& operator<<(ostream &os,const Settings<T> &settings)
{
    os<<"Object of type Settings information :"<<endl;
    for(int i=0; i<settings.getPairs().getSize(); i++)
    {
        os<<settings.getPairs()[i];
    }
    os<<endl;
    return os;
}

template<class T>
int Settings<T>::count() const
{
    return pairs.getSize();

}

template <class T>
void Settings<T>::set(const char* key,const T value)
{
    bool hasKey=false;
    int index=0;
    for(int i=0; i<pairs.getSize(); i++)
    {
        if(strcmp(pairs[i].getKey(),key)==0)
        {
            hasKey=true;
            index=i; //save the position of the pair so u won't iterate once more if you change it
            break;
        }
    }

    if(hasKey==false)
    {
        Pair<T> pair=Pair<T>(key,value);
        pairs.add(pair);
    }
    else
    {
        pairs[index].setValue(value);
    }
}

template<class T>
bool Settings<T>::get(const char* key, T& value)
{
    for(int i=0; i<pairs.getSize(); i++)
    {
        if(strcmp(pairs[i].getKey(),key)==0)
        {
            value=pairs[i].getValue();
            return true;
        }

    }
    return false;

}




#endif // SETTINGS_H
