#pragma once


class TriangleHeap
{
private:
	// Dynamic memory attributes
	float* mBase;    
	float* mHeight;

public:
	// Default Constructor
	TriangleHeap();

	// Copy constructor
	TriangleHeap(const TriangleHeap& other);

	// Copy assignment operator
	TriangleHeap& operator=(const TriangleHeap& other);

	// Destructor
	~TriangleHeap();
	  
	// Setters
	void SetBase(float base);
	void SetHeight(float height);

	// GetArea method
	float GetArea() const;
};

