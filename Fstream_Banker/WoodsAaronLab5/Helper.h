#pragma once

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<bitset>

namespace Helper {
	
	// method to clear/ignore cin input buffer
	void ClearInputBuffer() {
		std::cin.clear();                   // Clears error flags
		std::cin.ignore(INT_MAX, '\n');     // clears input buffer up to INT_MAX spaces, ending at the '\n' delimiter
	}

	// method for validating user input
	int GetValidatedInt(const char* strMessage, int nMinimumRange = 0, int nMaximumRange = 0) {
		int userInput;
		bool validInput = false;
		// while validInput bool is false (default value)
		while (!validInput) {
			// print the message contained in strMessage, and get a user's input
			std::cout << strMessage;
			std::cin >> userInput;
			// Check if userInput using cin.fail(). 
			if (std::cin.fail()) {
				// If cin.fail() returns true (badbit or failbit flags), clear flags and input buffer, give warning message, and start while loop again
				ClearInputBuffer();
				std::cout << "Invalid input. Please enter a valid number." << std::endl;
			}
			else {
				// once the cin passes, check IF userInput is within the specified range, OR if there is no range set. 
				// If either condition is true, clear the buffer and set validInput to true(ending the loop). 
				// If neither condition is true, display error message and start while loop again
				if ((nMinimumRange == 0 && nMaximumRange == 0) || (userInput >= nMinimumRange && userInput <= nMaximumRange)) {
					ClearInputBuffer();
					validInput = true;
				}
				else {
					std::cout << "Input out of range. Please try again." << std::endl;
					ClearInputBuffer();
				}
			}
		}
		// returns the user's input once validated
		return userInput;
	}

	// method that prints a menu (array of strings) and returns the user's selection
	int DisplayMenu(const std::string menuOptions[], int numOfOptions) {
		// takes in a menu (array of strings), and the number of options (i.e. 1-6 / numOptions = 6)
		// loops through menuOptions array and prints each option
		std::cout << "Please select one of the following options:\n";
		for (int i = 0; i < numOfOptions; ++i) {
			std::cout << i + 1 << ": " << menuOptions[i] << "\n";
		}
		// get user's choice (validate with GetValidatedInt method)
		int choice = GetValidatedInt("Enter your selection: ", 1, numOfOptions);
		//returns user's choice
		return choice;
	}

	// method to print out an int in different formats by changing the output type of the stream (cout)
	void PrintNumberTypes(int number) {
		std::cout << "Decimal: " << number << std::endl;                           // displays number normally (decimal)
		std::bitset<sizeof(int) * 8> binary(number);                               // use bitset to convert number to a binary string
		std::cout << "Binary: " << binary << std::endl;
		std::cout << "Hexadecimal: " << std::hex << number << std::endl;           // set output stream to display hexadecimal
		std::cout << "Octal: " << std::oct << number << std::endl;                 // set output stream to display octal
		//reverts the cout type back to decimal
		std::cout << std::dec;
	}

	// method to copy a string reference from a source to a destination
	void CopyString(std::string& destination, const std::string& source) {
		destination = source;
	}

	// method that returns a random number(int) within a range(min-max)
	int RandomInt(int min, int max) {
		std::srand(static_cast<unsigned int>(time(nullptr)));
		return min + (std::rand() % (max - min + 1));
	}
}