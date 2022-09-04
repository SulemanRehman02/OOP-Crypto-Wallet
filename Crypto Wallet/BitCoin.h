#ifndef BITCOIN_H
#define BITCOIN_H
#include "Currency.h"
#include <iostream>
#include <string>
using namespace std;
class BitCoin : public Currency
{
public:
	BitCoin(double a);

	virtual void DeductTransaction() override;

	double getAmount() override;

};
BitCoin::BitCoin(double a)
	:Currency(a)
{
}

void BitCoin::DeductTransaction()
{
	cout << "Amount after transaction: " << getAmount() - 2 << endl;
}
double BitCoin::getAmount()
{
	return this->amount;
}


#endif // BITCOIN_H
