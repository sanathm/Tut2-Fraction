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
	void getNumDenom(int &num,int &denom);
	void setNumDenom(int num, int denom);
	Fraction operator+(Fraction x);
	Fraction operator- (Fraction x);
	Fraction operator* (Fraction x);
	Fraction operator/ (Fraction x);
	friend ostream& operator<<(ostream &, const Fraction &);
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

void Fraction::getNumDenom(int &num,int &denom){
	num = numerator;
	denom = denominator;
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

std::ostream& operator<<(ostream & os, Fraction & f)
{
	int numerator, denominator;
	f.getNumDenom(numerator, denominator);
	if (numerator == 0) {
		os << "0" ;
	}
	else {
		for (int i = denominator; i >= 1; i--) {
			if ((denominator % i == 0) && (numerator % i == 0)) {
				denominator = denominator / i;
				numerator = numerator / i;
			}
		}

		int whole = (int)numerator / denominator;
		int remainder = numerator%denominator;
		if (remainder == 0) {
			os << whole ;
		}
		else {
			os << whole << " + (" << remainder << "/" << denominator << ")" ;
		}
	}
	return os;
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
	cout << result << endl << endl;

	//subtraction
	cout << "Subtraction:" << endl;
	result = a-b;
	cout << result << endl << endl;

	//multiplication
	cout << "Multiplication:" << endl;
	result = a*b;
	cout << result << endl << endl;

	//division
	cout << "Division:" << endl;
	result = a/b;
	cout << result << endl << endl;
}


