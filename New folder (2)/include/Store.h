#ifndef STORE_H
#define STORE_H
#include "Car.h"

class Store
{
    public:
    	Store();
	// деструктор
        Store(const Store &store);
        Store& operator=(const Store &store);
	~Store();

	void insert();				// вмъква контакт в списъка
	void lookup() const;		// търси име в списъка с контакти
	void remove(int id);				// изтрива контакт
	void update();				// обновява контакт
	void display() const;		// извежда списъка с контакти

    int getMaxSize() const;
    int getCurrentSize() const;
    Car getElement(int pos) const;
private:
    static int counter;
	int	maxSize,			// максимум брой контакти
		currentSize;		// текущ брой контакти
	Car* list;			// указател към динамичен масив с контакти
	void grow();			// увеличава maxSize когато е необходимо
	int findCar(int id) const;	// връща индекса на кантакт по зададено  име
};



#endif // STORE_H
