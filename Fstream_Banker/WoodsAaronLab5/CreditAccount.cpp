#include "CreditAccount.h"
#include <iostream>

void CreditAccount::Withdraw(float amount)
{
	// overrides base withdraw method increases amountSpent attribute
	BaseAccount::Withdraw(amount);
	DisplayTransaction("withdrawn from", "credit", amount);       // method defined in BaseAccount
	amountSpent = amountSpent + amount;

	// if check to charge the user a fee after $40 spent
	if (amountSpent > 40.0f) {
		std::cout << "You have exceeded the $40/montly spending limit."
			<< " a $5000 fee has been charged to your account!" << std::endl;
		accountBal = accountBal - 5000.0f;
		std::cout << "\nYour credit balance after the fee is: $" << accountBal;
	}
}
