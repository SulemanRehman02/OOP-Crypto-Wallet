#ifndef BITCOINACCOUNT_H
#define BITCOINACCOUNT_H
#include"Account.h"
#include "Ether.h"
#include "Currency.h"
#include <iostream>
#include <cstring>
#include<vector>
#include"Currency.h"
#include"Account.h"
#include "BitCoin.h"

class BitCoinAccount : public Account
{
public:
	BitCoinAccount(string, string);
	string getPublicKey();
	bool VerfiyAccount(string private_key);
	string getHash(string);
	bool SendCoins(string private_key, double amount);
	void DeductAmount(double amount);
	void AddAmount(double amount);
	~BitCoinAccount();
};

string BitCoinAccount::getHash(string str)
{
	const int len = str.length();
	char* ar = new char[len + 1];
	strcpy(ar, str.c_str());
	int for_hash;
	if (len == 3)
	{
		for_hash = len * 4;
	}
	if (len == 4)
	{
		for_hash = len * 5;
	}
	if (len == 5)
	{
		for_hash = len * 6;
	}
	if (len == 6)
	{
		for_hash = len * 7;
	}
	char* hashed = new char[for_hash];
	vector <char> vecc(for_hash);		// what the actual fuck?
	for (int i = 0, j = 0; i<for_hash, j<len; i = i + len + 1, j++)
	{
		vecc.at(i) = ar[j];
		int n = i;
		for (int k = 1, l = n + 1; k <= len || l <= len; k++, l++)
		{
			vecc.at(l) = (char(ar[j] + k));
		}
	}

	string s;
	for (const auto &piece : vecc) s += piece;
	return s;
}
BitCoinAccount::BitCoinAccount(string publickey, string privkey) : Account(publickey, getHash(privkey))
	{
	coins = new BitCoin(10);
}

bool BitCoinAccount::VerfiyAccount(string private_key)
{
	string After_Hashing_String_byUser = getHash(private_key);
	if (After_Hashing_String_byUser == private_key_hash)
	{
		return true;
	}
	else
		return false;
}

bool BitCoinAccount::SendCoins(string private_key, double amount)
{
	bool verify = VerfiyAccount(private_key);
	if (verify)
	{
		coins->Deductcoins(amount);
		coins->Deductcoins(2);
		cout << "Coins have been successfully deducted from sender's account. Remaining debt:  " << coins->getAmount() << endl << "NOTE: 2 BitCoins have been deducted as transaction fee\n";
		return true;
	}
	else
	return false;
}
string BitCoinAccount::getPublicKey()
{
	return public_key;
}
void BitCoinAccount::DeductAmount(double amount)
{
	coins->Deductcoins(amount);
	cout << "Coins after deduction: " << coins->getAmount() << endl;
}
void BitCoinAccount::AddAmount(double amount)
{
	coins->Addcoins(amount);
	cout << "Coins received! New balance: " << coins->getAmount() << endl;
}

BitCoinAccount::~BitCoinAccount()
{
	delete coins;
}

#endif // BITCOINACCOUNT_H
