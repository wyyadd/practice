#include <iostream>
#include <cmath>
using namespace std;
class RationalNumber
{
public:
	RationalNumber(int x = 1, int y = 1)
	{
		set(x, y);
	}
	void set(int x = 1, int y = 1)
	{
		if (y == 0) { cout << "Error: denominator=0"; abort(); }
		else if (y < 0) { x *= -1; y *= -1; }
		numberator = x;
		denominator = y;
		reduction();
	}
	RationalNumber operator+(const RationalNumber& a)
	{
		int deno = lcm(denominator, a.denominator);
		int m = deno / denominator, n = deno / a.denominator;
		RationalNumber temp(m * numberator + n * a.numberator, deno);
		return temp;
	}
	RationalNumber operator-(const RationalNumber& a)
	{
		int deno = lcm(denominator, a.denominator);
		int m = deno / denominator, n = deno / a.denominator;
		RationalNumber temp(m * numberator - n * a.numberator, deno);
		return temp;
	}
	RationalNumber operator*(const RationalNumber& a)
	{
		int numb = numberator * a.numberator,
			deno = denominator * a.denominator;
		RationalNumber temp(numb, deno);
		return temp;
	}
	RationalNumber operator/(const RationalNumber& a)
	{
		int numb = numberator * a.denominator,
			deno = denominator * a.numberator;
		RationalNumber temp(numb, deno);
		return temp;
	}
	bool operator==(const RationalNumber& a)
	{
		if (numberator == a.numberator) if (denominator == a.denominator) return true;
		return false;
	}
	bool operator!=(const RationalNumber& a)
	{
		if (*this == a) return false;
		else return true;
	}
	bool operator>(const RationalNumber& a)
	{
		RationalNumber temp = *this / a;
		if (temp.numberator / temp.denominator) return true;
		else return false;
	}
	void printRational() const
	{
		if (denominator != 1) cout << numberator << "/" << denominator;
		else cout << numberator;
	}
private:
	int numberator;
	int denominator;
	void reduction()
	{
		for (int i = numberator; i >= 2; i--)
			if (numberator % i == 0)
				if (denominator % i == 0)
				{
					numberator /= i;
					denominator /= i;
				}
	}  // for reduction
	int lcm(int x, int y)
	{
		if (x < y) swap(x, y);
		int i = x;
		for (; ; i++) if (i % x == 0) if (i % y == 0) break;
		return i;
	}
};
int main()
{
	RationalNumber c(7, 3), d(3, 9), x;
	c.printRational();
	cout << " + ";
	d.printRational();
	cout << " = ";
	x = c + d; // test overloaded operators + and =
	x.printRational();
	cout << '\n';
	c.printRational();
	cout << " - ";
	d.printRational();
	cout << " = ";
	x = c - d; // test overloaded operators - and =
	x.printRational();

	cout << '\n';
	c.printRational();
	cout << " * ";
	d.printRational();
	cout << " = ";
	x = c * d; // test overloaded operators * and =
	x.printRational();

	cout << '\n';
	c.printRational();
	cout << " / ";
	d.printRational();
	cout << " = ";
	x = c / d; // test overloaded operators / and =
	x.printRational();

	if (c > d)
	{
		cout << endl << endl << endl;
		c.printRational();
		cout << " > ";
		d.printRational();
	}

	if (c != d)
	{
		cout << endl;
		c.printRational();
		cout << " != ";
		d.printRational();
		cout << endl;
	}
}

