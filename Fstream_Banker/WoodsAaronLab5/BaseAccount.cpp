#include "BaseAccount.h"
#include <iostream>

// base constructor - sets attributes to 0
BaseAccount::BaseAccount() : accountBal(0.0f), numWithdrawals(0)
{
}

// virtual Withdraw function 
void BaseAccount::Withdraw(float amount)
{
	accountBal = accountBal - amount;
	numWithdrawals = numWithdrawals + 1;
}

// virtual Deposit function
void BaseAccount::Deposit(float amount)
{
	accountBal = accountBal + amount;
}

// Getter for account balance
float BaseAccount::GetBalance() const
{
	return accountBal;
}

// method to display operations performed within each transaction, and the new balance afterwards
void BaseAccount::DisplayTransaction(const std::string& transactionType, const std::string& account, float amount)
{
	std::cout << "\n$" << amount << " " << transactionType << " " << account << "\n";
	std::cout << "\nYour new balance in " << account << " is $" << accountBal << "\n\n";
	std::cin.get();
}
