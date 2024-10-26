#pragma once

#include <iostream>
#define TH template<typename Type>

template<typename Type = int>
class DList
{
private:

	struct node
	{
		node* next, *prev;
		Type data;

		node(Type& _data, node* _prev) : data(_data), prev(_prev), next(nullptr) {}
	};

	int count;
	node* first, *last;

public:
	DList() { first = last = nullptr; count = 0; }
	~DList();

	int GetCount() { return count; }

	void push_back(Type _data);

	void push_front(Type _data);

	void Erase(int index);

	void Clear();

	Type& operator[](int _index);
	const Type& operator[](int _index) const;

};


TH
void DList<Type>::push_back(Type _data)
{
	node* n = new node(_data, last);

	if (last)
		last->next = n;
	else
		first = n;

	last = n;

	++count;
}

// push_front() method to push an item to the front of the list
TH
void DList<Type>::push_front(Type _data) {
	// create a newFront node ptr using the argument's _data, and nullptr for the prev value
	node* newFront = new node(_data, nullptr);
	// If list is empty, makes first/last point to newFront
	//      otherwise makes newFront's 'next' value = to first and set first = newFront.
	if (count == 0) {
		// set first/last = newFront (makes this address the first and last in the list, since it is the only one).
		first = last = newFront;
	}
	else {
		// If list has contents (count is NOT 0), set newFront's 'next' location = first, and sets the first = to newFront' location
		newFront->next = first;
		first = newFront;
	}
	// Increase the value of count by 1
	count = count + 1;
}

TH
void DList<Type>::Erase(int index) {
	// If entered index is invalid (less than 0 or more than the number of items in the list), give error message
	if (index < 0 || index >= count) {
		std::cout << "Index does not exist." << std::endl;
		return;
	}
	// If there is only 1 node, deletes that node and sets default values.
	if (count == 1) {
		delete first;
		first = last = nullptr;
		count = 0;
		return;
	}
	// Create a node ptr. 'current' pointing to the address at 'first'
	//     traverse to the node at the specified index, making current = next in each iteration
	node* current = first;
	for (int i = 0; i < index; ++i) {
		current = current->next;
	}
	// After 'current' has been set to the node we want to remove, begin the if/else cases to fix the surrounding pointers:
	
	// If the node before current is not nullptr (is a valid node),
	if (current->prev != nullptr) {
		// Change the 'next' pointer of the node before current, making it point to the node that comes after current,
		//     bypassing current in the list.
		current->prev->next = current->next;
	}
	else {
		// If there is no previous node (current is the first), update the first node to point at the next node.
		first = current->next;
	}
	// If the node after current is not nullptr (is a valid node)
	if (current->next != nullptr) {
		// change the 'prev' pointer of the node after current, making it point to the node that comes before current,
		//      bypassing current on the list.
		current->next->prev = (*current).prev;
	}
	else {
		// If there is no nex node (current is the last), update the last node to point at the node before current.
		last = current->prev;
	}
	// After all pointers before and after current are no longer pointing at current,
	//        Delete current, and decrease count by 1.
	delete current;
	count = count - 1;
}

template<typename Type>
DList<Type>::~DList()
{
	// Call the Clear() function for clean-up
	DList<Type>::Clear();
}

// CLear() function to reset list 
TH
void DList<Type>::Clear() {
	// Make a node ptr 'current' point to first node
	node* current = first;
	// While the position of 'current' is NOT pointing to nullptr,
	//     loop through nodes, setting the next node = current node's location,
	//     deleting the current node, and then setting the current node address = to the next node address.
	while (current != nullptr) {
		// Make a node ptr 'next' = 'current' ptr's 'next' location
		node* next = (*current).next;  // (*current).next OR current->next
		// Delete 'current' ptr
		delete current;
		// Set 'current' = next
		current = next;
		// If 'current' becomes nullptr after all this, (the end of the list) the loop breaks
	}
	// Now set the first and last node ptrs to nullptr, and set the count to 0.
	first = last = nullptr;
	count = 0;
}

template<typename Type>
Type& DList<Type>::operator[](int _index)
{
	node* temp = first;

	int i = 0;
	for (; i < _index; ++i)
		temp = temp->next;

	return temp->data;
}

template<typename Type>
const Type& DList<Type>::operator[](int _index) const
{
	node* temp = first;

	int i = 0;
	for (; i < _index; ++i)
		temp = temp->next;

	return temp->data;
}



