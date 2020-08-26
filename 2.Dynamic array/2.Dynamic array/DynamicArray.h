#pragma once

template <class T>
class DynamicArray
{
	size_t _max_size;

	size_t _size;

	T *array;



public:
	DynamicArray();
	DynamicArray(const DynamicArray&);
	virtual ~DynamicArray();

	size_t size();

	T& operator[](int i);
	DynamicArray<T> & operator= (const DynamicArray<T> & a);

	void Resize(int);

	void Add(const T &val);

private:
	void Enlarge(int);
	void Shrink(int);
};

template<class T>
DynamicArray<T>::DynamicArray() :_max_size(5), _size(0)
{

	array = new T[_max_size];
}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>&a) {
	_size = _max_size = 0;
	*this = a;
}


template<class T>
DynamicArray<T>::~DynamicArray()
{
	delete[]array;
}

template<class T>
size_t DynamicArray<T>::size() {
	return this->_max_size;
}


template<class T>
T&  DynamicArray<T>::operator[](int i) {
	if (i < 0 || i > _size)
		throw std::out_of_range("Out Of Range");
	return array[i];
}


template<class T>
DynamicArray<T> & DynamicArray<T>::operator= (const DynamicArray<T> & a) {
	Resize(_size - a._size);
	for (int ndx = 0; ndx < a._size; ++ndx) {
		this.array[i] = a.array[i];
	}
	return *this;
}


template<class T>
void  DynamicArray<T>::Enlarge(int d) {
	if ((_size += d) > _max_size) {
		_max_size = _size;
		T* nArray = new T[_max_size];
		T* oldArray = array;

		for (int ndx = 0; ndx < _size - d; ++ndx)
			nArray[ndx] = array[ndx];
		array = nArray;
		 delete[]oldArray;
	}

}

template<class T>
void DynamicArray<T>::Shrink(int d) {
	_size = d > _size ? 0 : _size - d;
}

template<class T>
void DynamicArray<T> ::Resize(int d) {
	if (d > 0)
		Enlarge(d);
	else if (d < 0)
		Shrink(std::abs(d));
}


template<class T>
void DynamicArray<T>::Add(const T &val) {
	Resize(1);
	array[_size-1] = val;
}