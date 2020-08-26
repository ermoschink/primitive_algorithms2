#include "stdafx.h"
#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList():size(0), Head(0), tail(0)
{
}


template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>&):size(0), Head(0), tail(0) {
	this->a
}

template<class T>
LinkedList<T>::~LinkedList()
{
}

template<class T>
int LinkedList<T>::size()
{
}


template<class T>
Item<T> LinkedList<T>::getHead() {
	return this->Head;
}

template<class T>
Item<T> LinkedList<T>::getTail() {
	return this->tail;
}

template<class T>
T LinkedList<T>::Head() const {
	return this->head->item;
}

template<class T>
T & LinkedList<T>::Head() {
	return this->head->item;
}
template<class T>
T LinkedList<T>::Tail() const {
	return this->head->item;
}

template<class T>
T & LinkedList<T>::Tail() {
	return this->head->item;
}

template<class T>
void LinkedList<T>::addLast(const LinkedList<T>& s) {
	for (Item<T> *cur = s.getHead(); cur; cur = cur.next)
		this->addTail(cur->item);
}

template<class T>
void LinkedList<T>::addHead(T) {
}

template<class T>
void LinkedList<T>::addTail(T) {

}

template<class T>
bool LinkedList<T>::RemoveFirst() {
}
template<class T>
bool LinkedList<T>::Remove(int) {

}
template<class T>
bool LinkedList<T>::Insert(int) {

}