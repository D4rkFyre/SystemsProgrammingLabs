#pragma once
#include "Base.h"


class Student : public Base
{
private:
	float gpa = 0.0f;

public:
	// Default constructor
	Student();

	// SetGPA method
	void SetGPA(float newGPA);

	// Override DisplayRecord method
	void DisplayRecord() override;
};

