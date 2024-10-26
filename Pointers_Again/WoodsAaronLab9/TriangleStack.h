#pragma once


class TriangleStack
{
private:
	float mBase;
	float mHeight;

public:
	// Default Constructor
	TriangleStack();

	// Setters
	void SetBase(float base);
	void SetHeight(float height);

	// GetArea method
 	float GetArea() const;

};

