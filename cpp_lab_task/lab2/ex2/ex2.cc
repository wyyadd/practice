#include <iostream>
#include <cmath>
using namespace std;
class HugeInt;
ostream& operator<<(ostream& output, HugeInt& a);

class HugeInt
{
	friend ostream& operator<<(ostream& output, HugeInt& a);
public:
	HugeInt(int a = 0)
	{
		for (int t = 0; t <= 29; t++) integer[t] = 0;
		integer[0] = a;
	}
	HugeInt(const char* a)
	{
		for (int t = 0; t <= 29; t++) integer[t] = 0;
		int i = 0;
		for (; a[i] != 0; i++);
		i--;
		for (int j = 0; i >= 0; i--, j++) integer[j] = a[i] - '0';
	}
	int getvalue()
	{
		int sum = 0;
		for (int i = 0; i <= 29; i++) sum += integer[i] * pow(10, i);
		return sum;
	}
	HugeInt operator+(const HugeInt& a)
	{
		HugeInt temp;
		int i = 0;
		for (; i <= 29; i++) temp.integer[i] = integer[i] + a.integer[i];
		for (i = 0; i <= 29; i++)
			for (int j = 0; j <= 29; j++) if (temp.integer[j] > 9) { temp.integer[j] -= 9; temp.integer[j + 1]++; }
		return temp;
	}
	HugeInt operator-(const HugeInt& a)
	{
		HugeInt temp;
		int i = 0;
		for (; i <= 29; i++) temp.integer[i] = integer[i] - a.integer[i];
		for (i = 0; i <= 29; i++)
			for (int j = 0; j <= 29; j++)
			{
				if (temp.integer[j] < 0)
				{
					temp.integer[j] += 10;
					temp.integer[j + 1]--;
				}
				if (temp.integer[29] < 0) break;
			}
		return temp;
	}
	bool operator!=(const HugeInt& a)
	{
		for (int i = 0; i <= 30; i++) if (integer[i] != a.integer[i]) return true;
		return false;
	}
	bool operator==(const HugeInt& a)
	{
		if (*this != a) return true;
		else return false;
	}
	bool operator>(const HugeInt& a)
	{
		HugeInt temp = *this - a;
		for (int i = 0; i <= 29; i++) if (temp.integer[i] < 0) return false;
		return true;
	}
	HugeInt operator*(HugeInt& a)
	{
		HugeInt temp;
		for (int i = 0; i < a.getvalue(); i++) temp = temp + *this;
		return temp;
	}
	HugeInt operator/(HugeInt& a)
	{
		HugeInt temp = *this;
		int i = 0;
		for (; temp - a > 0; i++) temp = temp - a;
		return i;
	}

private:
	int integer[30];
};
ostream& operator<<(ostream& output, HugeInt& a)
{
	int i = 0;
	for (; i <= 29; i++)
	{
		int cnt = 0;
		for (int j = i; j <= 29; j++) if (a.integer[j] == 0) cnt++;
		if (cnt + i == 30) break;
	}
	i--;
	for (; i >= 0; i--) cout << a.integer[i];
	return output;
}
int main()
{
	char* str1 = (char*)"1001", * str2 =(char*) "2";
	HugeInt a(str1), b(str2), c, d, f, g, h;
	c = a + b;
	d = a + b;
	f = c - b;
	g = a * b;
	h = a / b;
	cout << "a=" << a << endl << "b=" << b << endl << "c=a+b=" << c << endl << "d=a+b=" << d << endl
		<< "f=c-b=" << f << endl << "g=a*b=" << g << endl << "h=a/b=" << h << endl << endl;

	if (c == d) cout << "c==d" << endl;
	if (a != c) cout << "a!=c" << endl;
	if (a > b)  cout << "a>b" << endl;

	cout << endl;
}

