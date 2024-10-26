#pragma once
#include <cstring>
#include <iostream>

class Base
{
private:
	char* name = nullptr;

public:
	// Default constructor
	Base();
	
	// Copy constructor
	Base(const Base& other);
	
	// Copy assignment operator
	Base& operator=(const Base& other);

	// Destructor
	~Base();
	
	// SetName method
	void SetName(const char* newName);

	// GetName method
	const char* GetName();

	// Pure virtual method
	virtual void DisplayRecord() = 0;
};

