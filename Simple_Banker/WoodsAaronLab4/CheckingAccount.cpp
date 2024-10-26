#include "CheckingAccount.h"
#include <iostream>

// overridden withdraw method for checking account
void CheckingAccount::Withdraw(float amount)
{
	// if check to charge a $5 fee if user has made over 10 withdrawals
	if (numWithdrawals >= 10) {
		accountBal = accountBal - 5.0f;
		std::cout << "\nYou have made more than 10 withdrawals. A $5.00 withdrawal fee has been deducted from your account balance.\n";
	}
	
	// actual overridden withdraw AFTER numWithdrawals check (prevents a free 11th withdrawal)
	BaseAccount::Withdraw(amount);
	std::cout << "\nYou have made " << numWithdrawals << " withdrawals from checking so far.\n";        // output to display num of withdrawals made (for ease of use)
	DisplayTransaction("withdrawn from", "checking", amount);                                           // method defined in BaseAccount
}
