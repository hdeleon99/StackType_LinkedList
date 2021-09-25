// Implementation file for linked StackType
#include "StackType.h"


template <class T>
StackType<T>::StackType()	// Class constructor.
{
  topPtr = nullptr;
}

template<class T>
StackType<T>::~StackType() {
    while (!IsEmpty()){

    }
}

template<class T>
bool StackType<T>::IsFull() const {
    NodeType* location;
    try {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}

template<class T>
bool StackType<T>::IsEmpty() const {
    return (topPtr == nullptr);
}

template<class T>
void StackType<T>::Push(T item) {
    if ( IsFull() )
        throw "List is full";
    else{
        NodeType* current;
        current = new NodeType;
        current->info = item;
        topPtr = current;
    }



}

template<class T>
void StackType<T>::Pop() {
    if ( IsEmpty() ){
        throw EmptyStack();
    }
    else{
        NodeType* tempPtr;
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
}

template<class T>
T StackType<T>::Top() {
    // returns a copy of the top item in the stack
    if ( IsEmpty() )
        throw EmptyStack();
    else
        return topPtr->info;
}