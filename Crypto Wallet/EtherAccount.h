#ifndef ETHERACCOUNT_H
#define ETHERACCOUNT_H
#include <iostream>
#include"Account.h"
#include "Ether.h"
#include "Currency.h"
#include <string>
using namespace std;

class EtherAccount : public Account
{
public:
	EtherAccount(string, string);
	string getPublicKey();
	bool VerfiyAccount(string private_key) ;
	string getHash(string);
	bool SendCoins(string private_key, double amount);
	void DeductAmount(double amount);
	void AddAmount(double amount);

	~EtherAccount();
};

string EtherAccount::getHash(string str)
{
	int len = str.length();
	int convert;
	const int size = len + 1;
	char* char_array = new char[size];
	strcpy(char_array, str.c_str());
	vector<string> vec;
	for (int i = 0; i < len; i++)
	{
		convert = char_array[i];
		string tempp = to_string(convert);
		vec.push_back(tempp);
	}

	string s;
	for (const auto &piece : vec) s += piece;
	return s;
}

EtherAccount::EtherAccount(string publickey, string privkey) : Account(publickey, getHash(privkey))
 {
	coins = new Ether(120);
}
bool EtherAccount::VerfiyAccount(string private_key)
{
	string After_Hashing_String_byUser = getHash(private_key);
	if (After_Hashing_String_byUser == private_key_hash)
	{
		return true;
	}
	else
		return false;

}


bool EtherAccount::SendCoins(string private_key, double amount)
{
	bool verify = VerfiyAccount(private_key);
	if (verify)
	{
		coins->Deductcoins(amount);
		coins->Deductcoins(5);
		cout << "Coins have been successfully deducted from sender's account. Remaining debt:  " << coins->getAmount() << endl << "NOTE: 2 BitCoins have been deducted as transaction fee\n";
		return true;
	}
	else
	return false;
}
string EtherAccount::getPublicKey()
{
	return public_key;
}
void EtherAccount::DeductAmount(double amount)
{
	coins->Deductcoins(amount);
}
void EtherAccount::AddAmount(double amount)
{
	coins->Addcoins(amount);
}

EtherAccount::~EtherAccount()
{
	delete coins;
}


#endif // ETHERACCOUNT_H
