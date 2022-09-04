#ifndef TRANSACTION_H
#define TRANSACTION_H
#include<string>
using namespace std;
class Transaction {
protected:
	string sender_public_key;
	string receiver_public_key;
	double amount;
public:
    Transaction(string,string,double);
	string getsender_public_key()const;
	string getreceiver_public_key()const;
	~Transaction();


	virtual string ToString()/* Do not modify this function*/
	{
		return this->sender_public_key + "-" + this->receiver_public_key + "-" + to_string(amount);
	}
};
Transaction::Transaction(string sender, string receiver, double a)
	:sender_public_key{ sender }, receiver_public_key{ receiver }, amount{ a } {}


string Transaction::getsender_public_key()const
{
	return sender_public_key;
}


string Transaction::getreceiver_public_key()const
{
	return receiver_public_key;
}

Transaction::~Transaction()
{

}

#endif // TRANSACTION_H
