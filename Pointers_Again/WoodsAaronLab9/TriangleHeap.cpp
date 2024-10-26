#include "TriangleHeap.h"

// Default constructor
TriangleHeap::TriangleHeap() : mBase(new float), mHeight(new float) {}

// Copy constructor
TriangleHeap::TriangleHeap(const TriangleHeap& other)
{
	// Newed member attributes from assigned object 'other'
	mBase = new float(*other.mBase);
	mHeight = new float(*other.mHeight);
}
// Copy assignment operator
TriangleHeap& TriangleHeap::operator=(const TriangleHeap& other)
{
	// Check to see if current object 'this' is different from assigned object 'other'
	if (this != &other) {
		// Delete existing memory allocated for mBase and mHeight
		delete mBase;
		delete mHeight;
		// Allocate new memory for mBase/mHeight pointers, and copy values from the assigned object 'other'
		mBase = new float(*other.mBase);
		mHeight = new float(*other.mHeight);
	}
	// Return current object
	return *this;
}

// Destructor
TriangleHeap::~TriangleHeap()
{
	delete mBase;
	delete mHeight;
}

// Setters
void TriangleHeap::SetBase(float base)
{
	*(mBase) = base;
}

void TriangleHeap::SetHeight(float height)
{
	*(mHeight) = height;
}

// GetArea method
float TriangleHeap::GetArea() const
{
	float result = (*mBase * *mHeight) / 2;
	return result;
}
