#include <iostream>

using namespace std;
class Complex;
istream &operator>>(istream &input, Complex &a);
ostream &operator<<(ostream &output, Complex &a);

class Complex
{
	friend istream &operator>>(istream &input, Complex &a);
	friend ostream &operator<<(ostream &output, Complex &a);
public:
	Complex(double a=0, double b=0)
	{
		setr(a);
		seti(b);
	}
	void setr(double a=0)
	{
		r=a;
	}
	void seti(double a=0)
	{
		i=a;
	}
	void display()
	{
		cout<<"("<<r<<", "<<i<<")";
	}
	Complex operator+(Complex &a)
	{
		r=r+a.r;
		i=i+a.i;
		return *this;
	}
	Complex operator-(Complex &a)
	{
		r=r-a.r;
		i=i-a.i;
		return *this;
	}
	Complex operator*(Complex &a)
	{
		double t1=0, t2=0;
		t1=r*a.r;
		t2=i*a.r+r*a.i-i*a.i;
		Complex temp(t1, t2);
		return temp;
	}
	bool operator==(const Complex &a)
	{
		if(r!=a.r) return false;
		else if(i!=a.i) return false;
		else return true;
	}
	bool operator!=(Complex &a)
	{
		if(*this==a) return false;
		else return true;
	}
private:
	double r;
	double i;
};
istream &operator>>(istream &input, Complex &a)
{
	double t1=0, t2=0;
	input>>t1>>t2;
	a.r=t1;
	a.i=t2;
	return input;
}
ostream &operator<<(ostream &output, Complex &a)
{
	a.display();
	return output;
}
int main()
{
   Complex x, y( 4.3, 8.2 ), z( 3.3, 1.1 ), k;

   cout << "Enter a complex number in the form: (a, b)\n? ";
   cin >> k; // demonstrating overloaded >>
   cout << "x: " << x << "\ny: " << y << "\nz: " << z << "\nk: "
      << k << '\n'; // demonstrating overloaded <<
   x = y + z; // demonstrating overloaded + and =
   cout << "\nx = y + z:\n" << x << " = " << y << " + " << z << '\n';
   x = y - z; // demonstrating overloaded - and =
   cout << "\nx = y - z:\n" << x << " = " << y << " - " << z << '\n';
   x = y * z; // demonstrating overloaded * and =
   cout << "\nx = y * z:\n" << x << " = " << y << " * " << z << "\n\n";
   if ( x != k ) // demonstrating overloaded !=
      cout << x << " != " << k << '\n';
   cout << '\n';
   x = k;
   if ( x == k ) // demonstrating overloaded ==
      cout << x << " == " << k << '\n';

}

