#ifndef TRANSACTIONHASHED_H
#define TRANSACTIONHASHED_H
#include<iostream>
#include<string>
#include "Account.h"
#include "AccountManager.h"
#include "Transaction.h"
#include<vector>

class TransactionHashed : public Transaction
{
protected:
	string hashed_sender_public_key; // To store hash of sender's public key
	string hashed_receiver_public_key; // to store hash of receiver's public key
	double amount;
public:
	TransactionHashed(string, string ,double, ACC_TYPE);

	string getHashB(string);
	string getHashE(string);
    string ToString()/* Do not modify this function*/
	{
		return this->hashed_sender_public_key + "-" + this->hashed_receiver_public_key + "-" + to_string(amount);
	}

};
string TransactionHashed::getHashB(string str) // returns hash according to BITCOINACCOUNT Hashing
{
	const int len = str.length();
	char ar[len];
	strcpy(ar, str.c_str());
	int for_hash;
	if (len == 2)
    {
        for_hash = len * 3;
    }
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
    if (len == 7)
    {
        for_hash = len * 8;
    }
    if (len == 8)
    {
        for_hash = len * 9;
    }
	char hashed[for_hash];
	vector <char> vecc(for_hash);
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

string TransactionHashed::getHashE(string str)
{
	int len = str.length();
	int convert;
	char char_array[len + 1];
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

TransactionHashed::TransactionHashed(string sender,string rec, double am, ACC_TYPE t)
:Transaction(sender,rec,am)
{
    if(t==ETHER)
    {
    string E_Hashed_Sender_pub = getHashE(sender);
    string E_Hashed_Rec_pub = getHashE(rec);
    hashed_sender_public_key = E_Hashed_Sender_pub;
    hashed_receiver_public_key = E_Hashed_Rec_pub;
    amount = am;
    }
    else if(t==BITCOIN)
    {
    string B_Hashed_Sender_pub = getHashB(sender);
    string B_Hashed_Rec_pub = getHashB(rec);
    hashed_sender_public_key = B_Hashed_Sender_pub;
    hashed_receiver_public_key = B_Hashed_Rec_pub;
    amount = am;
    }
}


#endif // TRANSACTIONHASHED_H
