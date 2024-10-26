#include "Base.h"
#include <cstring>

// Default constructor
Base::Base() {}

// Copy constructor
Base::Base(const Base& other) 
{
	std::cout << "Copy constructor called." << std::endl;   // Un-comment this line to see where CC is called
	*this = other;
}

// Copy assignment operator
Base& Base::operator=(const Base& other) 
{
	std::cout << "Copy assignment operator called." << std::endl;  // Un-comment this line to see where CAO is called
	if (this != &other) {
		delete[] name;
		int length = strlen(other.name) + 1;
		name = new char[length];
		strcpy_s(name, length, other.name);
	}
	return *this;
}

// Destructor
Base::~Base() 
{
	std::cout << "Destructor called." << std::endl;  // Un-comment this line to see where destructor is called
	delete[] name;
}

// SetName method
void Base::SetName(const char* newName) 
{
	delete[] name;  
	int length = strlen(newName) + 1;
	name = new char[length];
	strcpy_s(name, length, newName);
}

// GetName method
const char* Base::GetName()
{
	return name;
}



