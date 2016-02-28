#include <iostream>

using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;

public:
	Fraction();
	~Fraction();
	void getNumDenom();
	void setNumDenom(int num, int denom);
	Fraction add(Fraction x);
	Fraction subtract(Fraction x);
	Fraction multiply(Fraction x);
	Fraction divide(Fraction x);
	void print();
};

Fraction::Fraction(){
	numerator = 0;
	denominator = 1;
}

Fraction::~Fraction(){
	numerator = NULL;
	denominator = NULL;
}

void Fraction::getNumDenom(){
	cout << numerator << " / " << denominator << endl;
}

void Fraction::setNumDenom(int num, int denom){
	numerator = num;
	denominator = denom;
}

Fraction Fraction:: add(Fraction x){
	Fraction b = Fraction();
	b.numerator = (numerator*x.denominator) + (denominator*x.numerator);
	b.denominator = denominator*x.denominator;
	return b;
}

Fraction Fraction::subtract(Fraction x){
	x.numerator = -x.numerator;
	return add(x);
}

Fraction Fraction::multiply(Fraction x){
	Fraction b = Fraction();
	b.numerator = numerator*x.numerator;
	b.denominator = denominator*x.denominator;
	return b;
}

Fraction Fraction::divide(Fraction x){
	int temp = x.numerator;
	x.numerator = x.denominator;
	x.denominator = temp;
	return multiply(x);
}

void Fraction::print(){
	int whole = (int)numerator / denominator;
	int remainder = numerator%denominator;

	cout << whole << " + (" << remainder << "/" << denominator << ")" << endl;
}

int main()
{
	Fraction a = Fraction();
	Fraction b = Fraction();
	Fraction result = Fraction();
	a.setNumDenom(5, 4);
	b.setNumDenom(2, 3);
	result = a.add(b);
	result.getNumDenom();
	result = a.subtract(b);
	result.getNumDenom();
	result = a.multiply(b);
	result.getNumDenom();
	result = a.divide(b);
	result.getNumDenom();
	result.print();
}