#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Currency.h"
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

class Account {
protected:
	string public_key;//to store public key
	string private_key_hash;//to store hash of private key
	Currency *coins;
public:
	Account();
	virtual string getHash(string);
	Account(string, string);
	//void AccountCreationBitCoin(string, string);
	//void AccountCreationEther(string, string);


	//take hash of parameters and store them accordingly

	//return the hash of string s as desribed in document;

	virtual string getPublicKey();
	virtual bool VerfiyAccount(string private_key);


	/*Take Hash of the parameter private_key and compare it with hash member variable
	return true if matches
	*/

	virtual bool SendCoins(string private_key, double amount);

	/*
	* Verify account using the private_key (use the function above)
	* if verfication successful deduct amount from account,deduct transaction fee and return true
	* if verifaction failed return false;
	* if verification successful but there is not enough amount in coins then make the user in debt (negative balance)return true

	*/
	void setPublicKey(string);
	void setPrivateKey(string);


	virtual void DeductAmount(double amount);

	//Deduct amount from coins


	virtual void AddAmount(double amount);

	//Add amount to coins
	//non negative check on the function


	string ToString();


	//DO NOT MODIFY THIS FUNCTION


};

Account::Account(string pub, string pri)
	:public_key{ pub }, private_key_hash{ pri } {}



//void Account::AccountCreationBitCoin(string pub, string priv)
//{
//	cout << "Account created with Public key: " << pub << "    Private Key: " << priv << "\n";
//}
//
//void Account::AccountCreationEther(string pub, string priv)
//{
//	cout << "Account created with Public key: " << pub << "    Private Key: " << priv << "\n";
//}
string Account::getHash(string)
{
	return 0;
}

bool Account::VerfiyAccount(string private_key)
{
	if (private_key_hash == private_key) // Verifying account
    {
		return true;
	}
	return false;
}
/*Take Hash of the parameter private_key and compare it with hash member variable
return true if matches
*/
string Account::getPublicKey(){
	return public_key;
}
void Account::setPublicKey(string p)
{
	public_key = p;
}

void Account::setPrivateKey(string pr)
{
	private_key_hash = pr;
}

bool Account::SendCoins(string private_key, double amoun)
{

	/*
	* Verify account using the private_key (use the function above)
	* if verfication successful deduct amount from account,deduct transaction fee and return true
	* if verifaction failed return false;
	* if verification successful but there is not enough amount in coins then make the user in debt (negative balance)return true

	*/
	return 0;
}

void Account::DeductAmount(double amount)
{
	//Deduct amount from coins

}
void Account::AddAmount(double amount)
{
	//Add amount to coins
	//non negative check on the function
}
string Account::ToString()
{
	//DO NOT MODIFY THIS FUNCTION
	return public_key + "-" + to_string(coins->getAmount());
}

#endif // ACCOUNT_H
