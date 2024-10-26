#include <iostream>
#include <vector>
#include "TriangleStack.h"
#include "TriangleHeap.h"
#include "Helper.h"


int AddNumbersReturnInt(int* a, int* b) {
    // Set result equal to sum of values pointed to by a and b
    int result = *a + *b;
    // Return result
    return result;
}

void AddNumbersReturnVoid(int a, int b, int* sum) {
    // Set value pointed to by int pointer 'sum' equal to sum of a + b
    *sum = a + b;
}

void SwapValues(int* a, int* b) {
    // Swap the data pointed at by passed in pointers
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Modified GetValidatedInt method from Helper.h, modified to take in floats instead of ints (for use in Triangles)
static float GetValidatedFloat(const char* strMessage, float nMinimumRange = 0.0f, float nMaximumRange = 0.0f) {
    float userInput;
    bool validInput = false;
    // while validInput bool is false (default value)
    while (!validInput) {
        // print the message contained in strMessage, and get a user's input
        std::cout << strMessage;
        std::cin >> userInput;
        // Check if userInput using cin.fail(). 
        if (std::cin.fail()) {
            // If cin.fail() returns true (badbit or failbit flags), clear flags and input buffer, give warning message, and start while loop again
            Helper::ClearInputBuffer();
            std::cout << "Invalid input. Please enter a valid float." << std::endl;
        }
        else {
            // once the cin passes, check IF userInput is within the specified range, OR if there is no range set. 
            // If either condition is true, clear the buffer and set validInput to true(ending the loop). 
            // If neither condition is true, display error message and start while loop again
            if ((nMinimumRange == 0.0f && nMaximumRange == 0.0f) || (userInput >= nMinimumRange && userInput <= nMaximumRange)) {
                Helper::ClearInputBuffer();
                validInput = true;
            }
            else {
                std::cout << "Input out of range. Please try again." << std::endl;
                Helper::ClearInputBuffer();
            }
        }
    }
    // returns the user's input once validated
    return userInput;
}

int main()
{
    // include memory leak detection ( needs to be at top of main )
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtSetBreakAlloc(-1); // set block of memory to find memory leak
    _CrtDumpMemoryLeaks();


    // Menu for user choice regarding methods/values to use
    std::string MenuOptions[] = { "Number Manipulation", "Dynamic Triangles", "Exit" };
    bool Continue = true;
    while (Continue) {
        
        system("CLS");

        int userChoice = Helper::DisplayMenu(MenuOptions, 3);
        switch (userChoice) 
        {
        case 1:
           {
            system("CLS");
            std::cout << "Please enter 2 integers:" << std::endl;
            int num1 = Helper::GetValidatedInt("Integer #1: ");
            int num2 = Helper::GetValidatedInt("Integer #2: ");

            // AddNumbersReturnInt function call
            std::cout << "\nnum1 = " << num1 << ", num2 = " << num2 << std::endl;
            std::cout << "Calling AddNumbersReturnInt function." << std::endl;
            int result1 = AddNumbersReturnInt(&num1, &num2);
            std::cout << "Sum of numbers: " << result1 << std::endl;

            // AddNumbersReturnVoid function call
            int sum;
            std::cout << "\nCalling AddNUmbersReturnVoid function." << std::endl;
            AddNumbersReturnVoid(num1, num2, &sum);
            std::cout << "Value stored in 'sum' variable: " << sum << std::endl;

            // SwapValues function call
            std::cout << "\nBefore swapping: num1 = " << num1 << ", num2 = " << num2 << std::endl;
            std::cout << "Calling SwapValues function." << std::endl;
            SwapValues(&num1, &num2);
            std::cout << "After swapping: num1 = " << num1 << ", num2 = " << num2 << std::endl;
            Helper::ClearInputBuffer();
            break;
           }
        case 2:
           {
            system("CLS");

            // Get user input for TriangleStack creation
            std::cout << "----Triangle creation for the stack----\n";
            std::cout << "\nPlease enter 2 float values for the first triangle:" << std::endl;
            float num1 = GetValidatedFloat("Float value #1 (Base): ");
            float num2 = GetValidatedFloat("Float value #2 (Height): ");

            std::cout << "\nPlease enter 2 float values for the second triangle:" << std::endl;
            float num3 = GetValidatedFloat("Float value #1 (Base): ");
            float num4 = GetValidatedFloat("Float value #2 (Height): ");

            // TriangleStack triangle #1
            TriangleStack stack1;
            stack1.SetBase(num1);
            stack1.SetHeight(num2);

            // TriangleStack triangle #2
            TriangleStack stack2;
            stack2.SetBase(num3);
            stack2.SetHeight(num4);

            // TriangleStack vector 'stackVector' to push_back TriangleStack variables #1 & #2
            std::vector<TriangleStack> stackVector;
            stackVector.push_back(stack1);
            stackVector.push_back(stack2);

            // Print out areas of triangles in TriangleStack vector
            std::cout << "\nTriangleStack areas:" << std::endl;
            int S = 1;
            for (TriangleStack& triangle : stackVector) {
                int& iS = S;
                std::cout << "(Triangle #" << iS << ") Area: " << triangle.GetArea() << std::endl;
                ++iS;
            }
            std::cin.get();

            // Get user input for TriangleHeap creation
            std::cout << "\n----Triangle creation for the heap (Dynamic)----\n";
            std::cout << "\nPlease enter 2 float values for the first triangle:" << std::endl;
            float num5 = GetValidatedFloat("Float value #1 (Base): ");
            float num6 = GetValidatedFloat("Float value #2 (Height): ");

            std::cout << "\nPlease enter 2 float values for the second triangle:" << std::endl;
            float num7 = GetValidatedFloat("Float value #1 (Base): ");
            float num8 = GetValidatedFloat("Float value #2 (Height): ");

            // TriangleHeap triangle #1
            TriangleHeap heap1;
            heap1.SetBase(num5);
            heap1.SetHeight(num6);

            // TriangleHeap triangle #2
            TriangleHeap heap2;
            heap2.SetBase(num7);
            heap2.SetHeight(num8);

            // TriangleHeap vector 'heapVector' to push_back TriangleHeap variables #1 & #2
            std::vector<TriangleHeap> heapVector;
            heapVector.push_back(heap1);
            heapVector.push_back(heap2);

            // Print out areas of triangles in TriangleHeap vector
            std::cout << "\nTriangleHeap areas:" << std::endl;
            int H = 1;
            for (TriangleHeap& triangle : heapVector) {
                int& iH = H;
                std::cout << "(Triangle #" << iH << ") Area: " << triangle.GetArea() << std::endl;
                ++iH;
            }
            Helper::ClearInputBuffer();
            break;
           }
        case 3:
           {
            Continue = false;
            break;
           }
        } 
    }

    return 0;
}

