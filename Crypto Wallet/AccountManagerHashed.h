#ifndef ACCOUNTMANAGERHASHED_H
#define ACCOUNTMANAGERHASHED_H
#include<iostream>
#include<cstring>
#include <vector>
#include "AccountManager.h"
#include "TransactionHashed.h"

class AccountManagerHashed : public AccountManager
{
    public:
        AccountManagerHashed();
        void MakeTransaction(string sender,string rec, double am, ACC_TYPE t); // This function will be called when we want to store a Hashed Transaction
        string ToStringTransactionLogHashed();

    protected:
        vector<Transaction*>vec;
};

AccountManagerHashed :: AccountManagerHashed()
:AccountManager()
{

}
void AccountManagerHashed :: MakeTransaction(string sender,string rec, double am, ACC_TYPE t)
{
    vec.push_back(new TransactionHashed(sender, rec, am, t));
}
string AccountManagerHashed::ToStringTransactionLogHashed()
{
	string res = "";
	for (int i = 0; i<vec.size(); ++i)
	{
		res += vec[i]->ToString() + "\n";
	}
	return res;
}


#endif // ACCOUNTMANAGERHASHED_H
