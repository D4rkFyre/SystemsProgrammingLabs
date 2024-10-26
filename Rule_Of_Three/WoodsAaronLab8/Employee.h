#pragma once
#include "Base.h"

class Employee : public Base
{
private:
	int salary = 0;

public:
	// Default constructor
	Employee();

	// SetSalary method
	void SetSalary(int newSalary);

	// Override DisplayRecord method
	void DisplayRecord() override;
};

