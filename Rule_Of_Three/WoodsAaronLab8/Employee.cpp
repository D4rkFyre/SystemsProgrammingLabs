#include "Employee.h"
#include <iostream>

// Default constructor
Employee::Employee() {}

// SetSalary method
void Employee::SetSalary(int newSalary)
{
	salary = newSalary;
}

// Overridden DisplayRecord method
void Employee::DisplayRecord()
{
	// Use GetName() to get the name
	std::cout << "Employee Name: " << GetName() << std::endl;
	std::cout << "Salary: $" << salary << std::endl;
	
}
