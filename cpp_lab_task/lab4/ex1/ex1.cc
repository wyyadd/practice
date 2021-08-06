#include <iostream>
#include <string>
#include <vector>
#//include <windows.h>
using namespace std;
int Month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
class birthDate
{
public:
	birthDate(int y = 1, int m = 1, int d = 1)
	{
		setyear(y);
		setmonth(m);
		setday(d);
	}
	void setyear(int y = 1)
	{
		if (y >= 0) year = y;
		else
		{
			y = 1;
			cout << "Invalid year!" << endl;
		}
	}
	void setmonth(int m = 1)
	{
		if (m <= 12 && m >= 1) month = m;
		else
		{
			m = 1;
			cout << "Invalid month!" << endl;
		}
	}
	void setday(int d = 1)
	{
		if ((month == 2 && leapYear(year) && d >= 1 && d <= 29) || (month != 2 && d >= 1 && d <= Month[month])) day = d;
		else
		{
			d = 1;
			cout << "Invalid day!" << endl;
		}
	}
	int getmonth()
	{
		return month;
	}
	bool leapYear(int year = 2000)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
		else return false;
	}
	void showDate()
	{
		cout << "Birthday: " << year << '.' << month << '.' << day << '.' << endl;
	}
private:
	int year;
	int month;
	int day;
};
class Employee
{
public:
	Employee(string fn = "Zhang", string ln = "San", string id = "000", int y = 2000, int m = 1, int d = 1)
		:birthday(y, m, d), firstName(fn), lastName(ln), socialSecurityNumber(id)
	{
	}
	int getmonth()
	{
		return birthday.getmonth();
	}
	virtual double earnings(int mon = 0) = 0;
	virtual void print(int mon = 0)
	{

		cout << firstName << ' ' << lastName << endl;
		birthday.showDate();
		cout << "social security number: " << socialSecurityNumber << endl;
	}
private:
	string firstName;
	string lastName;
	string socialSecurityNumber;
	birthDate birthday;
};
class SalariedEmployee : public Employee
{
public:
	SalariedEmployee(string fn = "Zhang", string ln = "San", string id = "000", double weekSal = 1000, int y = 2000, int m = 1, int d = 1)
		:Employee(fn, ln, id, y, m, d)
	{
		setweeklySalary(weekSal);
	}
	void setweeklySalary(double weekSal = 1000)
	{
		if (weekSal > 0) weeklySalary = weekSal;
		else
		{
			cout << "Invalid weeklySalary" << endl;
			weeklySalary = 0;
		}
	}
	virtual double earnings(int mon = 0)
	{
		if (Employee::getmonth() == mon) return weeklySalary + 1000;
		else return weeklySalary;
	}
	virtual void print(int mon = 0)
	{
		Employee::print(mon);
		cout << "earnings: " << earnings(mon) << ", weeklySalary: " << weeklySalary << endl;
	}
private:
	double weeklySalary;
};
class CommissionEmployee : public Employee
{
public:
	CommissionEmployee(string fn = "Zhang", string ln = "San", string id = "000", double grossS = 1000, double commissionR = 0.2, int y = 2000, int m = 1, int d = 1)
		:Employee(fn, ln, id, y, m, d)
	{
		setgrossSales(grossS);
		setcommissionRate(commissionR);
	}
	void setgrossSales(double grossS = 1000)
	{
		if (grossS >= 0) grossSales = grossS;
		else
		{
			cout << "Invalid grossSales" << endl;
			grossSales = 0;
		}
	}
	void setcommissionRate(double commissionR = 0.2)
	{
		if (commissionR > 0 && commissionR <= 1) commissionRate = commissionR;
		else
		{
			cout << "Invalid commissionRate" << endl;
			commissionRate = 0.2;
		}
	}
	int getmonth()
	{
		return Employee::getmonth();
	}
	virtual double earnings(int mon = 0)
	{
		double temp = grossSales * commissionRate;
		if (Employee::getmonth() == mon) return temp + 1000;
		else return temp;
	}
	virtual void print(int mon = 0)
	{
		Employee::print(mon);
		cout << "earnings: " << earnings(mon) << ", grossSales: " << grossSales << ", commissionRate: " << commissionRate << endl;
	}
private:
	double grossSales;
	double commissionRate;
};
class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
	BasePlusCommissionEmployee(string fn = "Zhang", string ln = "San", string id = "000", double grossS = 1000, double commissionR = 0.2, double baseS = 1000, int y = 2000, int m = 1, int d = 1)
		:CommissionEmployee(fn, ln, id, grossS, commissionR, y, m, d)
	{
		setbaseSalary(baseS);
	}
	void setbaseSalary(double baseS = 1000)
	{
		if (baseS > 0) baseSalary = baseS;
		else
		{
			cout << "Invalid baseSalary" << endl;
			baseSalary = 1000;
		}
	}
	virtual double earnings(int mon = 0)
	{
		return CommissionEmployee::earnings(mon) + baseSalary;
	}
	virtual void print(int mon = 0)
	{
		CommissionEmployee::print();
		cout << "baseSalary: " << baseSalary << endl;
	}
private:
	double baseSalary;
};
int main()
{
	SYSTEMTIME system;
	GetLocalTime(&system);
	int mon = system.wMonth;
	cout << "Today: " << system.wYear << '.' << system.wMonth << '.' << system.wDay << endl;
	vector<Employee*> references(3);
	references[0] = new SalariedEmployee("Zhang", "San", "00000000", 10000, 2002, 3, 1);
	references[1] = new CommissionEmployee("Li", "Si", "11111111", 10000, 0.5, 2004, 4, 1);
	references[2] = new BasePlusCommissionEmployee("Wang", "Wu", "22222222", 30000, 0.2, 10000, 2004, 6, 20);

	for (int i = 0; i <= 2; i++)
	{
		cout << endl;
		references[i]->print(mon);
	}
}

