#pragma once
#include <string>

class BaseAccount
{
public:
	BaseAccount();
	
	virtual void Withdraw(float amount);
	virtual void Deposit(float amount);
	float GetBalance() const;

	virtual void DisplayTransaction(const std::string& transactionType, const std::string& account, float amount);

protected:
	float accountBal;
	int numWithdrawals;
};

