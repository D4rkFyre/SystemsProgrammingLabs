#pragma once
#include "BaseAccount.h"

class CreditAccount : public BaseAccount
{
public:
	// base credit account constructor to set amountspent to 0 for credit account
	CreditAccount() : amountSpent(0.0f) {}
	
	void Withdraw(float amount) override;

private:
	float amountSpent;
};

