// Implementation file for linked StackType
#include "StackType.h"


template <class T>
StackType<T>::StackType()	// Class constructor.
{
  topPtr = nullptr;
}

template<class T>
StackType<T>::~StackType() {

}

template<class T>
bool StackType<T>::IsFull() const {
    return false;
}

template<class T>
bool StackType<T>::IsEmpty() const {
    return false;
}

template<class T>
void StackType<T>::Push(T item) {

}

template<class T>
void StackType<T>::Pop() {

}

template<class T>
T StackType<T>::Top() {
    return nullptr;
}