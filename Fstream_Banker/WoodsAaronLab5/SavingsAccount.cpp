#include "SavingsAccount.h"
#include <iostream>

// overridden Withdraw function for savings account
void SavingsAccount::Withdraw(float amount)
{
	// actual withdraw is locked behind an if check to prevent more than 3 withdrawals
	if (numWithdrawals >= 3) {
		std::cout << "\nI'm sorry, you have reached the maximum number of withdrawals (3). Withdrawal failed." << std::endl;
		std::cin.get();
	}
	else {
		BaseAccount::Withdraw(amount);          // if less than 3 withdrawals have been made, performs overridden withdraw
		DisplayTransaction("withdrawn from", "savings", amount);             // method defined in BaseAccount
		std::cout << "You have made " << numWithdrawals << " withdrawals from savings so far (Max 3 allowed).";
	}
}
