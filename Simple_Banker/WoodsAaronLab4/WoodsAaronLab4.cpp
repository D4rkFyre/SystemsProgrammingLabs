#include <iostream>
#include "BaseAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include "Helper.h"

// method to perform deposits or withdrawals using a BaseAccount pointer (on a newed object)
void TransactionToPerform(BaseAccount* account, float amount, const std::string& transactionType) {
    if (transactionType == "deposit") {
        account->Deposit(amount);
        account->DisplayTransaction("deposited to", "this account", amount);
    }
    else if (transactionType == "withdraw") {
        account->Withdraw(amount);
    }
}

// method to use transactions (TransactionToPerform method) within a switch case (for cleaner/easier to debug code)
void AccountManipulator(BaseAccount* account, const std::string& transaction) {
    float amount;
    std::cout << "\nHow much would you like to " << transaction << "? ";
    std::cin >> amount;
    TransactionToPerform(account, amount, transaction);
    Helper::ClearInputBuffer();
}

int main()
{
    // include memory leak detection ( needs to be at top of main )
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtSetBreakAlloc(-1); // set block of memory to find memory leak
    _CrtDumpMemoryLeaks();
    
    // BaseAccount* to newed accounts of the various types
    BaseAccount* checking = new CheckingAccount;
    BaseAccount* savings = new SavingsAccount;
    BaseAccount* credit = new CreditAccount;

    // strings for menu selections
    std::string MainMenu[4] = { "Savings","Checking","Credit","End" };
    std::string AccountMenu[3] = { "Deposit", "Withdrawal", "End" };
    
    // variables for use in switch case for account choices/transaction choices
    bool Continue = true;
    int savingsChoice;
    int checkingChoice;
    int creditChoice;

    // While loop for user choices/input Main menu and sub-menus included (loops until user exits from main menu)
    while (Continue) {
        system("CLS");           // clears console for cleaner output between menus
        
        // Main menu /////////////////////////////////////
        std::cout << "-----------------------------------------------\n";
        std::cout << "Welcome to Full Sail Banking! \nYour account balances are:" << std::endl;
        std::cout << "\nSAVINGS: " << savings->GetBalance() << "\nCHECKING: " << checking->GetBalance() << "\nCREDIT: " << credit->GetBalance() << std::endl;
        std::cout << "\nWhich account would you like to access?" << std::endl;
        int MenuChoice = Helper::DisplayMenu(MainMenu, 4);
        system("CLS");           // clears console for cleaner output between menus
        switch (MenuChoice) {
        
        // Savings sub-menu /////////////////////////////
        case 1:
            std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++\n";
            std::cout << "What would you like to do with your SAVINGS account?\n\n";
            std::cout << "Current balance: $" << savings->GetBalance() << "\n\n";
            savingsChoice = Helper::DisplayMenu(AccountMenu, 3);
            if (savingsChoice == 1) {
                AccountManipulator(savings, "deposit");            // method defined above main
                break;
            }
            else if (savingsChoice == 2) {
                std::cout << "\n***Maximum 3 total withdrawals allowed per month***\n";
                AccountManipulator(savings, "withdraw");           // method defined above main
                break;
            }
            else {
                break;
            }
        // Checking sub-menu////////////////////////////
        case 2:
            std::cout << "ooooooooooooooooooooooooooooooooooooooooooooooo\n";
            std::cout << "What would you like to do with your CHECKING account?\n\n";
            std::cout << "Current balance: $" << checking->GetBalance() << "\n\n";
            checkingChoice = Helper::DisplayMenu(AccountMenu, 3);
            if (checkingChoice == 1) {
                AccountManipulator(checking, "deposit");          // method defined above main
                break;
            }
            else if (checkingChoice == 2) {
                std::cout << "\n***After 10 total withdrawals, $5 will be charged PER withdrawal***\n";
                AccountManipulator(checking, "withdraw");         // method defined above main
                break;
            }
            else {
                break;
            }
        // Credit sub-menu ////////////////////////////////
        case 3:
            std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
            std::cout << "What would you like to do with your CREDIT account?\n\n";
            std::cout << "Current balance: $" << credit->GetBalance() << "\n\n";
            creditChoice = Helper::DisplayMenu(AccountMenu, 3);
            if (creditChoice == 1) {
                AccountManipulator(credit, "deposit");              // method defined above main
                break;
            }
            else if (creditChoice == 2) {
                std::cout << "\n***$40/monthly withdrawal limit. Additional charges will incur a $5000 penalty***\n";
                AccountManipulator(credit, "withdraw");             // method defined above main
                break;
            }
            else {
                break;
            }
        // Exit statement once user selects 'Exit'
        case 4:
            std::cout << "\nThis concludes your banking session. Have a nice day!\n";
            std::cin.get();
            Continue = false;
            break;
        }
    }

    // delete newed objects to prevent memory leaks
    delete checking;
    delete savings;
    delete credit;

    return 0;
}