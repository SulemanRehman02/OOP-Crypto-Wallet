#ifndef CURRENCY_H
#define CURRENCY_H


class Currency {
protected:
	double amount;
public:
	Currency();

	Currency(double a);

	virtual void DeductTransaction();

	//Deducts transaction fee from amount
	//if amount is less than transaction fee it still deducts and leave the user in debt e.g negative amount


	void operator+=(double c);

	void operator-=(double c);

	virtual double getAmount();
	void Deductcoins(double);
	void Addcoins(double);
};

Currency::Currency()
{
	amount = 0;
}
Currency::Currency(double a)
	:amount{ a }
{

}
void Currency::DeductTransaction()
{
	//Deducts transaction fee from amount
	//if amount is less than transaction fee it still deducts and leave the user in debt e.g negative amount

}
void Currency :: operator+=(double c)
{
	amount = amount + c;

}
void Currency :: operator-=(double c)
{
	amount = amount - c;
}
double Currency::getAmount()
{
	return this->amount;
}

void Currency::Addcoins(double a)
{
	amount = amount + a;

}
void Currency::Deductcoins(double d)
{
	amount = amount - d;

}


#endif // CURRENCY_H
