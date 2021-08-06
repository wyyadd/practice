#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
class Account
{
public:
	Account(double x=0)
	{
		setbalance(x);
	}
	void setbalance(double x=0)
	{
		if(x>=0) balance=x;
		else 
		{ 
			throw invalid_argument("Invalid balance!");
			balance=0;
		}
	}
	double getbalance()
	{
		return balance;
	}
	virtual void credit(double x=0)
	{
		balance+=x;
	}
	virtual bool debit(double x=0)
	{
		if(x<=balance) 
		{
			balance-=x;
			return true;
		}
		else 
		{
			throw invalid_argument("Debit amount exceeded account balance.");
			return false;
		}
	}
	virtual void change(double x=0)
	{
		cout<<getbalance();
	}
private:
	double balance;
};
class SavingAccount: public Account
{
public:
	SavingAccount(double x=0, double r=0)
		:Account(x)
	{
		setrate(r);
	}
	void setrate(double r=0)
	{
		if(r>0 && r<=1) rate=r;
		else 
		{
			throw invalid_argument("Invalid rate!");
			rate=0;
		}
	}
	double calculateInterest()
	{
		return rate*Account::getbalance();
	}
	virtual void change(double x=0)
	{
		if(x==0)
		{
			cout<<endl<<"This is an account--SavingAccount: "
			<<endl<<"newly balance: ";
			Account::change(x);
			cout<<endl<<"rate: "<<rate<<endl;
		}
		else
		{
			credit(calculateInterest()+x);
			cout<<endl<<"This is an account--SavingAccount: "
			<<endl<<"newly balance: ";
			Account::change(x);
			cout<<endl;
		}
	}
private:
	double rate;
};
class CheckingAccount: public Account
{
public:
	CheckingAccount(double x=0, double f=0)
		:Account(x)
	{
		setfee(f);
	}
	void setfee(double f=0)
	{
		if(f>=0) fee=f;
		else 
		{
			throw invalid_argument("Invalid fee!");
			fee=0;
		}
	}
	virtual void credit(double x=0)
	{
		Account::credit(x-fee);
	}
	virtual bool debit(double x=0)
	{
		if(Account::debit(x+fee)) return true;
		else return false;
	}
	virtual void change(double x=0)
	{
		if(x==0) 
		{
			cout<<endl<<"This is an account--CheckingAccount: "
			<<endl<<"newly balance: ";
			Account::change(x);
			cout<<endl<<"Fee: "<<fee<<endl;
		}
		else 
		{
			if(debit(x))
			{
			cout<<endl<<"This is an account--CheckingAccount: "
			<<endl<<"newly balance: ";
			Account::change(x);
			cout<<endl;
			}
		}
	}
private:
	double fee;
};
int main()
{
	vector <Account*> ptr(2);
	ptr[0]=new SavingAccount(1000, 0.5);
	ptr[1]=new CheckingAccount(1000, 1);

	cout<<"Here are two accounts: "<<endl;
	for(int i=0; i<=1; i++)
	ptr[i]->change(0);

	double num[2];
	cout<<"Please input two numbers,first for crediting and second for debiting: ";
	cin>>num[0]>>num[1];
	cout<<endl;

	for(int i=0; i<=1; i++)
	ptr[i]->change(num[i]);
}

