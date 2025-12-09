#include "Array.hpp"

template <typename T>
Array<T>::Array() : arr(NULL), s(0){}

template <typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]()), s(n) {}

template <typename T>
Array<T>::Array(const Array& other) : arr(new T[other.size()]()), s(other.size()) {
	for (unsigned int i = 0; i < s; i++)
		arr[i] = other.arr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other){
	if (this != &other){
		delete[] arr;
		s = other.size();
		arr = new T[s];
		for (unsigned int i = 0; i < s; i++)
			arr[i] = other.arr[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array(){
	delete[] arr;
}

template <typename T>
T& Array<T>::operator[](unsigned int n){
	if (n >= s)
		throw OutOfRange(/* "Index out of range!" */);
	else
		return (arr[n]);
}

template <typename T>
unsigned int Array<T>::size() const{
	return (s);
}


template <typename T>
const char* Array<T>::OutOfRange::what() const throw() {
	return ("Index out of range!");
}