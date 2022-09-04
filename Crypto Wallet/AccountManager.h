#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H
#include "Account.h"
#include "BitcoinAccount.h"
#include "EtherAccount.h"
#include "Transaction.h"
#include <cstring>
#include <time.h>
#include <vector>
#include <windows.h>
#include <bits/stdc++.h>
#include <fstream>
#include <iterator>
#define MAX 100
using namespace std;
enum ACC_TYPE {BITCOIN, ETHER};

class AccountManager
{
protected:
	Account **arr;
	int NumAccounts;
	vector<Transaction> TransactionLog;

public:
	AccountManager();
	bool AddAccount(Account &a);
	string convertToString(char* a, int size);
	string GenerateRandomKey();
	Account* operator[](int i);
	string  CreateAccount(ACC_TYPE e);
    bool MakeTransaction(string sender_public_key, string sender_private_key, string reciever_public_key, double amount);
	virtual string ToStringAccounts();
	virtual string ToStringTransactionLog();
	void WriteToFile(string filename);
	void Display_All_Accounts();
	void LoadFromFile(string filename);
	~AccountManager();
};


AccountManager::AccountManager() // In the constructor arr is pointing to an array of 50 Accounts*
{
	this->NumAccounts = 0;
	arr = new Account *[50];
}

string AccountManager::GenerateRandomKey() // This function just generates Alpha numeric keys for public and private keys
{
	int n = 3;
	char random[62] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n','o', 'p', 'q', 'r', 's', 't', 'u','v', 'w', 'x', 'y', 'z',
                            '0','1','2','3','4','5','6','7','8','9' ,'A', 'B', 'C', 'D', 'E', 'F', 'G','H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

	string result = "";
	for (int i = 0; i < n; i++)
		result = result + random[rand() % 62];

	return result;
}

Account* AccountManager :: operator[](int i) //Here [ ] is being overloaded so that arr[i] returns ith index of arr
{
	if (i>NumAccounts || i<0) // checking if i is greater than number of accounts or less than zero
	{
		return nullptr;
	}
	else
    {
		return arr[i];
	}
}

bool AccountManager::AddAccount(Account &a) // Here newly created accounts are added to the list of arrays and the NumAccounts is incremented by 1
{
	for (int i = 0; i < NumAccounts; i++)
    {
		if(a.getPublicKey() == arr[i]->getPublicKey()) // checking if account with the same public key already exists
		{
		    cout << "Account already exists with this user-name: " << a.getPublicKey() << " and thus could not be added.\n\n";
		    return false; // if it exists then it can't be added and we return false
		}
	}
	arr[NumAccounts] = &a; // Now if public doesn't already exist then account is added to array on index = NumAccounts and NumAccount is increased by 1
	NumAccounts++;
	return true;
}

string AccountManager::CreateAccount(ACC_TYPE e)
{
	if (e == BITCOIN) // Checking if account type is ETHER or BITCOIN
        {
		string pubKey;
		string privKey;
        pubKey = GenerateRandomKey(); // Generating random public key for automatic account creation
        privKey = GenerateRandomKey(); // Generating random private key for automatic account creation
        BitCoinAccount *bitcoin_Account = new BitCoinAccount(pubKey,privKey); // Here a pointer of BitCoinAccount type allocates memory for BitCoinAccount on the heap
        bool flag = AddAccount(*bitcoin_Account); // Then the pointer is dereferenced by * operator and sent to AddAccount function so that It could be added to arr[] and receives true if added otherwise false
        if(flag == 1) // if true
        {
            cout << "Account Created with Public Key: "<< pubKey << "  Private Key: " << privKey << endl;
        }
        else // if false
        {
            cout << "Sorry, Account couldn't be added." << endl;
        }
		return privKey;
	}

	else if (e == ETHER)
        {
        string pubKey;
		string privKey;
        pubKey = GenerateRandomKey(); // Generating random public key for automatic account creation
        privKey = GenerateRandomKey(); // Generating random private key for automatic account creation
        EtherAccount *Ether_Account = new EtherAccount(pubKey,privKey); // Here a pointer of EtherAccount type allocates memory for BitCoinAccount on the heap dynamically
        bool flag = AddAccount(*Ether_Account); // Then the pointer is dereferenced by * operator and sent to AddAccount function so that It could be added to arr[] and receives true if added otherwise false
        if(flag == 1)// if true
        {
            cout << "Account Created with Public Key: "<< pubKey << "  Private Key: " << privKey << endl;
        }
        else // if false
        {
            cout << "Sorry, Account couldn't be added." << endl;
        }
		return privKey;
        }
}
void AccountManager :: Display_All_Accounts() // This function just prints all the accounts present in arr[]
{

	for (int i = 0; i < NumAccounts; i++)
    {
		cout << "Public Key: " << arr[i]->getPublicKey() << endl;
	}
}
bool AccountManager::MakeTransaction(string sender_public_key, string sender_private_key, string reciever_public_key, double amount) // This function is called for making transaction
{
	bool sent = false;
	int counter=0;
        while (counter < NumAccounts) // Loop to check every account one by one
        {
            if(sender_public_key == arr[counter]->getPublicKey()) // checking if sender public key is equal to current index i.e counter of arr[] or not
                {
                sent = arr[counter]->SendCoins(sender_private_key, amount); // if its equal then we call the method SendCoins for the arr[counter]
                if (sent == 0) // If we provide the private key wrong then sent will be set to 0
                {
                    cout << "Sorry! your private key is incorrect." << endl;
                    return false;
                }
                for (int j = 0; j < NumAccounts; j++) // Else we will start searching for the receiver's public key in the arr[]
                {
                    if (reciever_public_key == arr[j]->getPublicKey()) // If receiver's account is found
                    {
                        arr[j]->AddAmount(amount); // Adding the amount in receiver's account which is at index j of the arr[]
                        cout << "\nTransaction has been made from " << arr[counter]->getPublicKey() << " to " << reciever_public_key << " successfully!" << endl << endl;
                        sent = true; // Sent is set to true if Amount is transferred
                    }
                }
                if (!sent) // if amount is not transferred then it means coins have been sent but couldn't find receivers account and the coins are lost
                cout << "Sorry! Couldn't find the receiver's account. Coins Lost!" << endl;
                Transaction* log = new Transaction(sender_public_key, reciever_public_key, amount); // Here the values are passed to the Transaction class constructor and log is pointing to this newly created Transaction
                TransactionLog.push_back(*log); // Then this transaction is added to the Transaction log vector
                return true;
                }
                counter++;
        }
        cout << "Sorry! Couldn't find the sender's public key in the account." << endl;
        return false; //returns false if there is no account found in arr[] with sender's public key
}

 void AccountManager :: WriteToFile(string filename)
{
     ofstream file_obj; // Creating an object of ofstream class
     file_obj.open(filename, ios::binary); // opening the file in binary open mode
     file_obj.write((char*)this, sizeof(this)); // Writing current state (this) of AccountManager to the file
     file_obj.close(); // closing the file

}

void AccountManager :: LoadFromFile(string filename)
{
        ifstream L_file(filename); // creating an object of ifstream class
        if(!L_file) // if file with filename is not found
        {
            cout << "Sorry! Couldn't find the file. Error reading file." << endl;
        }
        L_file.read((char*)this, sizeof(this)); // Reading current state of AccountManager form the file.
    }

string AccountManager::ToStringAccounts()
{
	/** DO NOT MODIFY THIS FUNCTION**/
	string res = "";
	for (int i = 0; i<this->NumAccounts; ++i)
	{
		res += this->arr[i]->ToString() + "\n";
	}
	return res;
}

string AccountManager::ToStringTransactionLog()
{
	string res = "";
	for (int i = 0; i<TransactionLog.size(); ++i)
	{
		res += TransactionLog[i].ToString() + "\n";
	}
	return res;
}

AccountManager :: ~AccountManager()
{
	delete[]arr;
}
#endif // ACCOUNTMANAGER_H
