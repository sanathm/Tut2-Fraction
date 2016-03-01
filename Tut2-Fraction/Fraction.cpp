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
	Fraction operator+(Fraction x);
	Fraction operator- (Fraction x);
	Fraction operator* (Fraction x);
	Fraction operator/ (Fraction x);
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

Fraction Fraction::operator+ (Fraction x){
	Fraction b = Fraction();
	b.numerator = (numerator*x.denominator) + (denominator*x.numerator);
	b.denominator = denominator*x.denominator;
	return b;
}

Fraction Fraction::operator- (Fraction x){
	x.numerator = -x.numerator;
	return operator+ (x);
}

Fraction Fraction::operator* (Fraction x){
	Fraction b = Fraction();
	b.numerator = numerator*x.numerator;
	b.denominator = denominator*x.denominator;
	return b;
}

Fraction Fraction::operator/ (Fraction x){
	int temp = x.numerator;
	x.numerator = x.denominator;
	x.denominator = temp;
	return operator* (x);
}

void Fraction::print(){
	if (numerator == 0){
		cout << "0" << endl;
	}
	else{
		for (int i = denominator; i >= 1; i--) {
			if ((denominator % i == 0) && (numerator % i == 0)) {
				denominator = denominator / i;
				numerator = numerator / i;
			}
		}

		int whole = (int)numerator / denominator;
		int remainder = numerator%denominator;
		if (remainder == 0){
			cout << whole << endl;
		}
		else{
			cout << whole << " + (" << remainder << "/" << denominator << ")" << endl;
		}		
	}
}

int main()
{
	Fraction a = Fraction();
	Fraction b = Fraction();
	Fraction result = Fraction();

	//fraction input
	a.setNumDenom(7, 12);
	b.setNumDenom(7, 12);
	
	//add
	cout << "Addition:" << endl;
	result = a+b;
	result.getNumDenom();
	result.print();
	cout << endl;

	//operator- ion
	cout << "operator- ion:" << endl;
	result = a-b;
	result.getNumDenom();
	result.print();
	cout << endl;

	//multiplication
	cout << "Multiplication:" << endl;
	result = a*b;
	result.getNumDenom();
	result.print();
	cout << endl;

	//division
	cout << "Division:" << endl;
	result = a/b;
	result.getNumDenom();
	result.print();
	cout << endl;
}