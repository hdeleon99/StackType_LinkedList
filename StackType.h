#include <string>
using namespace std;

#ifndef STACKTYPE
#define STACKTYPE

// MAX_ITEMS: the maximum number of items on the stack.
const int MAX_ITEMS = 5;

class FullStack
	// Exception class thrown by Push when stack is full.
{
public:
    string Msg() {
        return "Stack is full.";
    }
};

class EmptyStack
	// Exception class thrown by Pop and Top when stack is emtpy.
{
public:
    string Msg(){
        return "Stack is empty.";
    }
};


template <class T>
class StackType
{
public:

	StackType();
	// Class constructor.

	// Copying stuff from otherStack into "this"
	StackType(const StackType<T>& otherStack);

	// ASsignment operator
	void operator=(const StackType<T>& otherStack);


	// Define <
	//bool operator<(const StackType<T>& otherStack);

	// Define +
	//StackType<T> operator+(const StackType<T>& otherStack);
	~StackType();
	// Class de-constructor.
	bool IsFull() const;
	// Function: Determines whether the stack is full.
	// Pre:  Stack has been initialized.
	// Post: Function value = (stack is full)
	bool IsEmpty() const;
	// Function: Determines whether the stack is empty.
	// Pre:  Stack has been initialized.
	// Post: Function value = (stack is empty)
	void Push(T item);
	// Function: Adds newItem to the top of the stack.
	// Pre:  Stack has been initialized, and is not full.
	// Post: If (stack is full), FullStack exception is thrown;
	//     otherwise, newItem is at the top of the stack.
	void Pop();
	// Function: Removes top item from the stack.
	// Pre:  Stack has been initialized, and is not empty.
	// Post: If (stack is empty), EmptyStack exception is thrown;
	//     otherwise, top element has been removed from stack.
	T Top();
	// Function: Returns a copy of top item on the stack.
	// Pre:  Stack has been initialized.
	// Post: If (stack is empty), EmptyStack exception is thrown;
	//     otherwise, top element has been removed from stack.


private:

    struct NodeType
    {
        T info;
        NodeType* next;
    };

	NodeType* topPtr;
};



#endif