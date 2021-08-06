#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;
const double pi=3.14;
class shape
{
public:
	shape(int x=2)
		:dimension(x)
	{
	}
	virtual double getarea()=0;
	virtual void display()=0;
	int dimension;
};
class twodimension: public shape
{
public:
	twodimension(int d=2)
		:shape(d)
	{
	}
	virtual void display()
	{
		cout<<"This is a two-dimensional shape-> ";
	}
};
class circle: public twodimension
{
public:
	circle(double x=0)
	{
		setr(x);
	}
	void setr(double x=0)
	{
		if(x>0) r=x;
		else throw invalid_argument("r<=0");
	}
	double getarea()
	{
		return pi*r*r;
	}
	void display()
	{
		twodimension::display();
		cout<<"circle: "
			<<"r= "<<r
			<<", area= "<<getarea()<<endl;
	}
private:
	double r;
};
class rectangle: public twodimension
{
public:
	rectangle(double x=1, double y=1)
	{
		seta(x);
		setb(y);
	}
	double geta()
	{
		return a;
	}
	void seta(double x=1)
	{
		if(x>0) a=x;
		else throw invalid_argument("Rectangle sides input error!");
	}
	void setb(double x=1)
	{
		if(x>0) b=x;
		else throw invalid_argument("Rectangle sides input error!");
	}
	double getarea()
	{
		return a*b;
	}
	void display()
	{
		twodimension::display();
		cout<<"rectangle: "
			<<"side1= "<<a
			<<", side2= "<<b
			<<", area= "<<getarea()<<endl;
	}
private:
	double a;
	double b;
};
class square: public rectangle
{
public:
	square(double x=1)
		:rectangle(x, x)
	{	
	}
	void display()
	{
		double a=rectangle::geta();
		cout<<"This is a two-dimensional shape-> "
			<<"square: "
			<<"side= "<<a
			<<", area= "<<a*a<<endl;
	}
private:
	double side;
};
class threedimension: public shape
{
public:
	threedimension(int d=3)
		:shape(d)
	{
	}
	virtual double getarea()=0;
	virtual double getvolume()=0;
	virtual void display()
	{
		cout<<"This is a three-dimensional shape-> ";
	}
};
class cube: public threedimension
{
public:
	cube(double a=1)
	{
		seta(a);
	}
	void seta(double a=1)
	{
		side=a;
	}
	virtual double getarea()
	{
		return 6*side*side;
	}
	virtual double getvolume()
	{
		return side*side*side;
	}
	virtual void display()
	{
		threedimension::display();
		cout<<"cube: "
			<<"side= "<<side
			<<", area= "<<getarea()
			<<", volume= "<<getvolume()<<endl;
	}
private:
	double side;
};
class spherome: public threedimension
{
public:
	spherome(double a=1)
	{
		setr(a);
	}
	void setr(double a=1)
	{
		r=a;
	}
	virtual double getarea()
	{
		return 4*pi*r*r;
	}
	virtual double getvolume()
	{
		return 4/3*pi*r*r*r;
	}
	virtual void display()
	{
		threedimension::display();
		cout<<"spherome: "
			<<"r= "<<r
			<<", area= "<<getarea()
			<<", volume= "<<getvolume()<<endl;
	}
private:
	double r;
};
int main()
{
	vector <shape*> Shapes(5);
	Shapes[0]=new circle(1);
	Shapes[1]=new rectangle(1, 2);
	Shapes[2]=new square(1);
	Shapes[3]=new cube(1);
	Shapes[4]=new spherome(1);

	for(int i=0; i<=4; i++)
		Shapes[i]->display();
}

