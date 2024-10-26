#include "TriangleStack.h"

// Default constructor
TriangleStack::TriangleStack() : mBase(0.0f), mHeight(0.0f) {}

// Setters
void TriangleStack::SetBase(float base)
{
	mBase = base;
}

void TriangleStack::SetHeight(float height)
{
	mHeight = height;
}

// GetArea method
float TriangleStack::GetArea() const
{
	float result = (mBase * mHeight) / 2;
	return result;
}
