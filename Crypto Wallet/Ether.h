#ifndef ETHER_H
#define ETHER_H
#include <iostream>
#include <string>
#include "Currency.h"
using namespace std;


class Ether : public Currency
{
public:
	Ether(double a);

	virtual void DeductTransaction() override; // overriding the deduct transaction method

	double getAmount() override;

};

Ether::Ether(double a)
	:Currency(a){

}

void Ether::DeductTransaction() // When a transaction is made, then the following amount will be deducted from EtherAccount
{
	int a = 5;
	getAmount() - a;
}
double Ether::getAmount() // Just returns the current amount
{
	return this->amount;
}


#endif // ETHER_H
