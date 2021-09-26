// Implementation file for linked StackType
#include "StackType.h"


template <class T>
StackType<T>::StackType()	// Class constructor.
{
  topPtr = nullptr;
}

template<class T>
StackType<T>::StackType(const StackType<T> &otherStack) {


    // Empty case
    if(otherStack.IsEmpty()) {
        this->topPtr = nullptr;
        return;
    }

    // Create the top
    this->topPtr = new NodeType;
    this->topPtr->next = nullptr;
    this->topPtr->info = otherStack.topPtr->info;

    NodeType* ptr1 = otherStack.topPtr->next;
    NodeType* ptr2 = this->topPtr;

    while(ptr1 != nullptr) {

        // Copy contents of ptr1
        ptr2->next = new NodeType;
        ptr2->next->info = ptr1->info;



        ptr1 = ptr2->next;
        ptr2 = ptr2->next;
    }
    ptr2->next = nullptr; // after everything has run, account for the end of
    // otherStack
}


template<class T>
void StackType<T>::operator=(const StackType<T> &otherStack) {

    // Empty case
    if(otherStack.IsEmpty()) {
        this->topPtr = nullptr;
        return;
    }

    // Create the top
    this->topPtr = new NodeType;
    this->topPtr->next = nullptr;
    this->topPtr->info = otherStack.topPtr->info;

    NodeType* ptr1 = otherStack.topPtr->next;
    NodeType* ptr2 = this->topPtr;

    while(ptr1 != nullptr) {

        // Copy contents of ptr1
        ptr2->next = new NodeType;
        ptr2->next->info = ptr1->info;



        ptr1 = ptr2->next;
        ptr2 = ptr2->next;
    }
    ptr2->next = nullptr; // after everything has run, account for the end of
    // otherStack
}


template<class T>
StackType<T>::~StackType() {
    while (topPtr != nullptr) {
        NodeType* temp = topPtr;
        topPtr = topPtr->next;
        delete temp;

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
    if ( IsFull()){
        throw FullStack();
    }
    if ( IsEmpty()) {
        topPtr = new NodeType;
        topPtr->next = nullptr;
        topPtr->info = item;
        return;
    }

    NodeType* newTop = new NodeType;
    newTop->next = topPtr;
    newTop->info = item;
    topPtr = newTop;




}

template<class T>
void StackType<T>::Pop() {
    if ( IsEmpty() ){
        throw EmptyStack();
    }

    NodeType* tempPtr;
    tempPtr = topPtr;
    topPtr = topPtr->next;
    delete tempPtr;

}

template<class T>
T StackType<T>::Top() {
    // returns a copy of the top item in the stack
        return topPtr->info;
}

