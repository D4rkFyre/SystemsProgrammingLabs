#include <iostream>
#include <vector>
#include "Base.h"
#include "Employee.h"
#include "Student.h"
#include "Helper.h"

// Function to add a record (employee or student)
void AddRecord(std::vector<Base*>& records);

// Function to display all records
void DisplayRecords(std::vector<Base*>& records);

// Function to duplicate a record
void DuplicateRecord(std::vector<Base*>& records);



int main()
{
    // include memory leak detection ( needs to be at top of main )
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtSetBreakAlloc(-1); // set block of memory to find memory leak
    _CrtDumpMemoryLeaks();

    // Vector of base ptrs to store records
    std::vector<Base*> records;
    
    // String array for DisplayMenu
    std::string MenuOptions[] = { "Add a record", "Display all records", "Duplicate a record", "Exit" };
    
    // Get user input for type of manipulation to perform
    bool keepGoing = true;
    while (keepGoing) {
        system("CLS");
        int userChoice = Helper::DisplayMenu(MenuOptions, 4);
        system("CLS");
        switch (userChoice) {
        case 1:
            AddRecord(records);
            break;
        case 2:
            DisplayRecords(records);
            break;
        case 3:
            DuplicateRecord(records);
            break;
        case 4:
            keepGoing = false;
            break;
        }
    }
    // Clean up: delete all records
    for (Base* record : records) {
        delete record;
    }

    return 0;
}




// Function to add a record (employee or student)
void AddRecord(std::vector<Base*>& records) {
    // String array for DisplayMenu
    std::string MenuOptions[] = { "Add an Employee", "Add a Student", "Back to main" };
    
    // Ask user: Employee or student?
    bool keepGoing = true;
    while (keepGoing) {
        system("CLS");
        std::cout << "What type of record would you like to add?" << std::endl;
        int choice = Helper::DisplayMenu(MenuOptions, 3);
        switch (choice) {
        case 1:
        {
            // Create a new record pointer based on user choice
            Employee* newEmployee = new Employee;

            // Prompt user to fill out record's members
            std::cout << "\nEnter employee name: ";
            std::string empName;
            std::getline(std::cin, empName);
            std::cout << "\nEnter employee salary: ";
            int salary;
            std::cin >> salary;
            Helper::ClearInputBuffer();
            
            newEmployee->SetName(empName.c_str());
            newEmployee->SetSalary(salary);

            // Add the new record pointer to the vector
            records.push_back(newEmployee);
            std::cout << "\nEmployee added." << std::endl;
            
            std::cin.get();
            break;
        }
        case 2:
        {
            // Create a new record pointer based on user choice
            Student* newStudent = new Student;
            
            // Prompt user to fill out record's members
            std::cout << "\nEnter student name: ";
            std::string stuName;
            std::getline(std::cin, stuName);
            std::cout << "\nEnter student GPA: ";
            float gpa;
            std::cin >> gpa;
            Helper::ClearInputBuffer();
            
            newStudent->SetName(stuName.c_str());
            newStudent->SetGPA(gpa);
            
            // Add the new record pointer to the vector
            records.push_back(newStudent);
            std::cout << "\nStudent added." << std::endl;
            
            std::cin.get();
            break;
        }
        case 3:
            // Exit loop/method
            keepGoing = false;
            break;
        }
    }
}

// Function to display all records
void DisplayRecords(std::vector<Base*>& records) {
    std::cout << "Displaying all records:\n" << std::endl;
    if (records.size() == 0)
        std::cout << "No records to display!!" << std::endl;
    
    for (Base* record : records) {
        record->DisplayRecord();
        std::cout << "-----------------------------------------\n";
    }
    std::cin.get();
}

// Function to duplicate a record
void DuplicateRecord(std::vector<Base*>& records) {
    
    // Print out a list of names in vector for reference
    std::cout << "Index of current names in records:\n" << std::endl;
    for (int i = 0; i < records.size(); ++i) {
        std::cout << i << ": " << records[i]->GetName() << std::endl;
    }

    // Ask user for an index of the record to duplicate
    std::cout << "\nEnter the index of the record to duplicate: ";
    int index;
    std::cin >> index;
    
    // If index position exists
    if (index >= 0 && index < records.size()) {
        
        // Set Base ptr chosenRecord = record at user's index choice
        Base* chosenRecord = records[index];
        
        // Use dynamic_cast to determine record type (Employee or Student)
        Employee* emp = dynamic_cast<Employee*>(chosenRecord);
        Student* stu = dynamic_cast<Student*>(chosenRecord);
        
        // Create a new record for duplication based on type at user selected index
        // If emp is valid (not nullptr)
        if (emp) {
            
            // Make a newed Employee using copy constructor
            Employee* empCopy = new Employee(*emp);
            
            // Add the new record pointer to the vector
            records.push_back(empCopy);
            std::cout << "\nEmployee record at index " << index << " duplicated.\n";
            Helper::ClearInputBuffer();
            std::cin.get();
        }
        // Otherwise, if stu is valid (not nullptr)
        else if (stu) {
            
            // Make a newed Student using copy constructor
            Student* stuCopy = new Student(*stu);
            
            // Add the new record pointer to the vector
            records.push_back(stuCopy);
            std::cout << "\nStudent record at index " << index << " duplicated.\n";
            Helper::ClearInputBuffer();
            std::cin.get();
        }
    }
    // If given index position is out of range, give error message
    else {
        std::cout << "Invalid index. Please enter a valid index to duplicate.\n";
    }
}