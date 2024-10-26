#include <iostream>
#include<string>

// <<<<<<<<<<<<<<< PROGRAM 3: PART 1 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Color enum
enum EnumColorDefinition {
	Red,
	Blue,
	Green,
	Yellow,
};
// Car struct
struct Car {
	char Make[32];
	char Model[32];
	int Year;
	int Mileage;
	EnumColorDefinition Color;
};
// <<<<<<<<<<<< PROGRAM 2 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Method to print values/locations of an array 
void PrintIntPointers(int value, int* ptr);
// <<<<<<<<<<<< PROGRAM 3: PART 2 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Method to repaint a specific car in the Car array
void repaintCar(Car* ptrCar, EnumColorDefinition newColor);
// <<<<<<<<<<<<< PROGRAM 3: PART 3 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Method to print out a single car using values
void printCar(Car c);
// Method to print out a single car using pointers
void printCarPointer(Car* ptrCar);
// <<<<<<<<<<<<< PROGRAM 3: PART 4 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// Method to add mileage to a specific car in the Car array
void addMileage(Car* ptrCar, int milesToAdd);
// Method to print out the Car array after re-painting *NOT A REQUIRED METHOD FROM LAB INSTRUCTIONS*
void PrintCarArray(Car cArray[]);


int main()
{
	// <<<<<<<<<< PROGRAM 1 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	int numArray[15] = {};
	// fill numArray with random numbers
	for (int i = 0; i < 15; ++i) {
		numArray[i] = std::rand();
	}
	std::cout << "First random int array:\n\n";
	//loop through numArray and print values/memory addresses
	for (int i = 0; i < 15; ++i) {
		std::cout << "(Value: " << numArray[i] << ")   (Address: " << &numArray[i] << ")\n";
	}
	std::cout << "----------------------------------------------------\n";
	// <<<<<<<<<<<<<<<<<<< PROGRAM 2 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	int numArray2[15];
	//fill numArray2 with random numbers
	for (int i = 0; i < 15; ++i) {
		numArray2[i] = std::rand();
	}
	std::cout << "\nSecond random int array:\n\n";
	//loop through numArray2 and pass values to PrintIntPointers method
	for (int i = 0; i < 15; ++i) {
		PrintIntPointers(numArray2[i], &numArray2[i]);
	}
	std::cout << "----------------------------------------------------\n";
	// <<<<<<<<<<<<<<<< PROGRAM 3: PART 1 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	Car carArray[3] = {};
	std::cout << "\nLet's make a couple cars.\n";
	// loop through carArray and get user's input for values to store
	for (int i = 0; i < 3; ++i) {
		std::cout << "\nEnter Details for Car " << i + 1 << ":\n";
		std::cout << "Make: ";
		std::cin.getline(carArray[i].Make, 32);

		std::cout << "Model: ";
		std::cin.getline(carArray[i].Model, 32);

		std::cout << "Year: ";
		std::cin >> carArray[i].Year;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

		std::cout << "Mileage: ";
		std::cin >> carArray[i].Mileage;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

		int colorInput;
		std::cout << "Color (0: Red, 1: Blue, 2: Green, 3: Yellow): ";
		std::cin >> colorInput;
		carArray[i].Color = (EnumColorDefinition)colorInput;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}
	// <<<<<<<<<<<< PROGRAM 3: PART 1, UPDATED WITH PART 3 >>>>>>>>>>>>>>>>>>>>>>>>>
	std::cout << "\nPrinting cars:\n";
	for (int i = 0; i < 3; ++i) {
		std::cout << "Car " << i + 1 << " - ";
		printCar(carArray[i]);
	}
	std::cout << "\nPrinting cars with pointers:\n";
	for (int i = 0; i < 3; ++i) {
		std::cout << "Car " << i + 1 << " - ";
		printCarPointer(&carArray[i]);
	}
	// <<<<<<<<<<<< PROGRAM 3: PART 2 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	// ask if user wants to repaint a car, then update the carArray with the new color. Print array after with PrintCarArray method
	std::cout << "\nWould you like to repaint a car? (y/n) ";
	char response;
	std::cin >> response;
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
	if (response == 'y') {
		std::cout << "\nWhich car from the list above would you like to repaint? (1-3) ";
		int CarToPaint;
		std::cin >> CarToPaint;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "\nWhat Color do you want to paint it? (0: Red, 1: Blue, 2: Green, 3: Yellow) ";
		int ColorToPaint;
		std::cin >> ColorToPaint;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		repaintCar(&carArray[CarToPaint - 1], (EnumColorDefinition)ColorToPaint);
		std::cout << "\nUpdated Car list: \n";
		PrintCarArray(carArray);
	}
	// <<<<<<<<<<<< PROGRAM 3: PART 4 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	// ask if user wants to add mileage to any of the cars, then update the car with the new mileage. Print array after with PrintCarArray method
	std::cout << "\nWould you like to add mileage to a car? (y/n) ";
	char response2;
	std::cin >> response2;
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
	if (response2 == 'y') {
		std::cout << "\nWhich car from the list above would you like to add mileage to? (1-3) ";
		int CarToAddMiles;
		std::cin >> CarToAddMiles;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "\nHow many miles do you want to add? ";
		int MilesToAdd;
		std::cin >> MilesToAdd;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		addMileage(&carArray[CarToAddMiles - 1], MilesToAdd);
		std::cout << "\nUpdated Car list: \n";
		PrintCarArray(carArray);
	}
	return 0;
}


void PrintIntPointers(int value, int* ptr) {
	std::cout << "(Value: " << value << ")   (Address: " << ptr << ")\n";
}

void repaintCar(Car* ptrCar, EnumColorDefinition newColor) {
	(*ptrCar).Color = newColor;
}

void printCar(Car c) {
	std::cout << c.Year << " ";
	switch (c.Color) {
	case Red:
		std::cout << "Red ";
		break;
	case Blue:
		std::cout << "Blue ";
		break;
	case Green:
		std::cout << "Green ";
		break;
	case Yellow:
		std::cout << "Yellow ";
		break;
	}
	std::cout << c.Make << " " << c.Model << " with " << c.Mileage << " miles\n";
}

void printCarPointer(Car* ptrCar) {
	printCar(*ptrCar);
}

void addMileage(Car* ptrCar, int milesToAdd) {
	(*ptrCar).Mileage += milesToAdd;
}

void PrintCarArray(Car cArray[]) {
	std::cout << "\n";
	for (int i = 0; i < 3; ++i) {
		std::cout << "Car " << i + 1 << " - " << cArray[i].Year << " ";
		switch (cArray[i].Color) {
		case Red:
			std::cout << "Red ";
			break;
		case Blue:
			std::cout << "Blue ";
			break;
		case Green:
			std::cout << "Green ";
			break;
		case Yellow:
			std::cout << "Yellow ";
			break;
		}
		std::cout << cArray[i].Make << " " << cArray[i].Model << " with " << cArray[i].Mileage << " miles\n";
	}
}