#pragma once

template <class U>
struct Item {
	U item;
	Item<U>* next;
	Item(U val, Item<U>* n) {
		item = val;
		next = n;
	}
};

template<class T>
class LinkedList
{

public:

	int _size;

	Item<T> *head;
	Item<T> *tail;
public:
	LinkedList();
	LinkedList(const LinkedList<T>&);
	virtual ~LinkedList();
	
	int size();

	Item<T> getHead();
	Item<T> getTail();

	T Head() const;
	T & Head();
	T Tail() const;
	T & Tail();

	void addLast(const LinkedList<T>&);
	void addHead(T);
	void addTail(T);

	bool RemoveFirst();
	bool Remove(int);
	bool Insert(int);

};

