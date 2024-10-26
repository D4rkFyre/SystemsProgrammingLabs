#include <iostream>
#include "DList.h"
#include "Helper.h"

void DisplayList(DList<int>& list) {
    if (list.GetCount() == 0) {
        std::cout << "No nodes to display!" << std::endl;
    }
    else {
        for (int i = 0; i < list.GetCount(); ++i) {
            std::cout << "Element at index " << i << ": " << list[i] << std::endl;
        }
    }
    std::cin.get();
}

int main()
{
    // include memory leak detection ( needs to be at top of main )
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtSetBreakAlloc(-1); // set block of memory to find memory leak
    _CrtDumpMemoryLeaks();


    DList<int> *Tester = new DList<int>;
    std::cout << "Let's test Doubly-linked list manipulation with integer values.\n";
    std::cout << "Exit this menu to see basic DLL push front/back manipulation with other variable types.\n";
    int numOfNodes = Helper::GetValidatedInt("How many nodes do you want to create? ");
    std::cout << "\nPlease add initial integer values to the nodes on this list.\n" << std::endl;
    for (int i = 0; i < numOfNodes; ++i) {
        std::cout << "Node at index " << i << " = ";
        int node = Helper::GetValidatedInt("");
        Tester->push_back(node);
    }
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << "Your new list:\n" << std::endl;
    DisplayList(*Tester);
    //std::cin.get();
    
    std::string MenuOptions[] = { "Show list", "Push_Back", "Push_Front", "Get Count", "Erase specific node", "Clear", "Exit"};
    bool Continue = true;
    while (Continue) {
        system("CLS");
        
        int userChoice = Helper::DisplayMenu(MenuOptions, 7);
        //system("CLS");           // This will clear the main menu after user's choice, while asking the user for input during the switch cases
        switch (userChoice) {
        // Show List
        case 1:  
            std::cout << "Your current list:\n" << std::endl;
            DisplayList(*Tester);
            break;
        // push_back
        case 2:   
            std::cout << "Current list:\n" << std::endl;
            DisplayList(*Tester);
            int backInt;
            backInt = Helper::GetValidatedInt("What value would you like to push_back?  ");
            Tester->push_back(backInt);
            //Helper::ClearInputBuffer();
            std::cout << "\nList after push_back:\n" << std::endl;
            DisplayList(*Tester);
            break;
        // push_front
        case 3:   
            std::cout << "Current list:\n" << std::endl;
            DisplayList(*Tester);
            int frontInt;
            frontInt = Helper::GetValidatedInt("What value would you like to push_front?  ");
            Tester->push_front(frontInt);
            //Helper::ClearInputBuffer();
            std::cout << "\nList after push_front:\n" << std::endl;
            DisplayList(*Tester);
            break;
        // GetCount
        case 4:    
            std::cout << "Current list:\n" << std::endl;
            DisplayList(*Tester);
            std::cout << "Count: " << Tester->GetCount() << std::endl;
            std::cin.get();
            break;
        // Erase Specific Node
        case 5:    
            std::cout << "Current list:\n" << std::endl;
            DisplayList(*Tester);
            int eraseIndex;
            eraseIndex = Helper::GetValidatedInt("\nWhat is the index # of the node you would like to erase? ");
            Tester->Erase(eraseIndex);
            //std::cin.get();
            std::cout << "\nThe list now looks like:\n" << std::endl;
            DisplayList(*Tester);
            break;
        // Clear all nodes
        case 6:    
            std::cout << "List before clear:\n" << std::endl;
            DisplayList(*Tester);
            Tester->Clear();
            std::cout << "\nList cleared." << std::endl;
            std::cout << "\nCount after clearing: " << Tester->GetCount() << std::endl;
            std::cin.get();
            break;
        // Exit program
        case 7:   
            Continue = false;
            break;
        }
    }
    delete Tester;

    DList<char>* Tester1 = new DList<char>;
    Tester1->push_back('c');
    Tester1->push_front('b');
    Tester1->push_back('d');
    Tester1->push_front('a');
    std::cout << "Char DLL\n";
    for (int i = 0; i < Tester1->GetCount(); ++i) {
        std::cout << "Element at index " << i << ": " << (*Tester1)[i] << std::endl;
    }
    std::cout << "Count: " << Tester1->GetCount() << std::endl;
    delete Tester1;

    std::cout << "-----------------------------------------------\n";

    DList<bool>* Tester2 = new DList<bool>;
    Tester2->push_back(true);
    Tester2->push_front(false);
    Tester2->push_back(false);
    Tester2->push_front(true);
    Tester2->push_back(true);
    std::cout << "Bool DLL\n";
    for (int i = 0; i < Tester2->GetCount(); ++i) {
        std::cout << "Element at index " << i << ": " << (*Tester2)[i] << std::endl;
    }
    std::cout << "Count: " << Tester2->GetCount() << std::endl;
    delete Tester2;

    std::cout << "-----------------------------------------------\n";

    DList<float>* Tester3 = new DList<float>;
    Tester3->push_back(333.333f);
    Tester3->push_front(222.222f);
    Tester3->push_back(444.444f);
    Tester3->push_front(111.111f);
    std::cout << "Float DLL\n";
    for (int i = 0; i < Tester3->GetCount(); ++i) {
        std::cout << "Element at index " << i << ": " << (*Tester3)[i] << std::endl;
    }
    std::cout << "Count: " << Tester3->GetCount() << std::endl;
    delete Tester3;

}
