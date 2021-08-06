#include<iostream>
#include<string>
#include <math.h>
using namespace std;
class Shape
{
public:
 Shape(string="Shape");
 ~Shape();
 string getId();
private:
 string id;
};
class Circle:public Shape
{
public:
 Circle(string="Circle",double=0.0,double=0.0,double=0.0);
 ~Circle();
 double area();
 void print();
private:
 double centerX;
 double centerY;
 double radius;
};
class Rectangle:public Shape
{
public:
 Rectangle(string="Rectangle",double=0.0,double=0.0,double=0.0,double=0.0);
 ~Rectangle();
 double getcentreX();
 double getcentreY();
 double getwidth();
 double getlength();
 double area();
 void print();
private:
 double centreX,centreY;
 double width;
 double length;
};
class Square:public Rectangle
{
public:
 Square(string="Square",double=0.0,double=0.0,double=0.0);
 ~Square();
 Circle incircle();
 void print();
private:
 double centreX,centreY;
 double size;
};
class Triangle:public Shape
{
public:
 Triangle(string="Triangle",double=0.0,double=0.0,double=0.0,
  double=0.0,double=0.0,double=0.0);
 ~Triangle();
 double area();
 void print();
private:
 double point1X,point1Y;
 double point2X,point2Y;
 double point3X,point3Y;
};
Shape::Shape(string name)
{
 id=name;
}
Shape::~Shape()
{
}
string Shape::getId()
{
 return id;
}


Circle::Circle(string id,double r,double cx,double cy):
Shape(id)
{
 radius=r;
 centerX=cx;
 centerY=cy;
}
Circle::~Circle()
{
}
double Circle::area()
{
 return 3.14*radius*radius;
}
void Circle::print()
{
 cout<<getId()<<":\nRadius: "<<radius
  <<"\ncentreofcircle: ("<<centerX<<","<<centerY<<")"
  <<"\nLefttop: ("<<centerX-sqrt(2.0)*radius/2<<","<<centerY+sqrt(2.0)*radius/2<<")"
  <<"\nRightbottom: ("<<centerX+sqrt(2.0)*radius/2<<","<<centerY-sqrt(2.0)*radius/2<<")"
  <<"\nArea: "<<area()<<"\n\n";
}
Rectangle::Rectangle(string id,double l,double w,double X,double Y):
Shape(id)
{
 length=l;
 width=w;
 centreX=X;
 centreY=Y;
}
Rectangle::~Rectangle()
{
}
double Rectangle::area()
{
 return width*length;
}
double Rectangle::getcentreX()
{
 return centreX;
}
double Rectangle::getcentreY()
{
 return centreY;
}
double Rectangle::getwidth()
{
 return width;
}
double Rectangle::getlength()
{
 return length;
}
void Rectangle::print()
{
 cout<<getId()<<":\nCentreofrectangle: ("<<centreX<<","<<centreY<<")"
  <<"\nLenth: "<<length<<"\nWidth: "<<width
  <<"\nArea: "<<area()<<"\n\n";
}
Square::Square(string id,double s,double x,double y):Rectangle(id,s,s,x,y)
{
}
Square::~Square()
{
}
Circle Square::incircle()
{
 Circle inc("The inscribed circle",getwidth()/2,getcentreX(),getcentreY());
 return inc;
}
void Square::print()
{
 cout<<getId()<<":\nCentreofrectangle: ("<<getcentreX()<<","<<getcentreY()<<")"
  <<"\nSize: "<<getlength()
  <<"\nArea: "<<area()<<"\n";
 incircle().print();
}
Triangle::Triangle(string id,double p1X,double p1Y,double p2X,
 double p2Y,double p3X,double p3Y):
Shape(id)
{
 point1X=p1X;
 point1Y=p1Y;
 point2X=p2X;
 point2Y=p2Y;
 point3X=p3X;
 point3Y=p3Y;
}
Triangle::~Triangle()
{
}
double Triangle::area()
{
 double size1=sqrt(pow(point1X-point2X,2.0)+pow(point1Y-point2Y,2.0));
 double size2=sqrt(pow(point1X-point3X,2.0)+pow(point1Y-point3Y,2.0));
 double size3=sqrt(pow(point3X-point2X,2.0)+pow(point3Y-point2Y,2.0));
 double p=(size1+size2+size3)/2;
 return sqrt(p*(p-size1)*(p-size2)*(p-size3));
}
void Triangle::print()
{
 cout<<getId()<<":\nPoint1: ("<<point1X<<","<<point1Y<<")"
  <<"\nPoint2: ("<<point2X<<","<<point2Y<<")"
  <<"\nPoint3: ("<<point3X<<","<<point3Y<<")"
  <<"\nArea: "<<area()<<"\n\n";
}

int main()
{
 Circle shape1("Shape1(circle)",1.0,1.0,1.0);
 Triangle shape2("Shape2(triangle)",2.0,0.0,3.0,2.0,4.0,0.0);
 Rectangle shape3("Shape3(rectangle)",6.0,2.0,2.0,4.0);
 Square shape4("Shape4(square)",2.0,1.0,5.0);
 shape1.print();
 shape2.print();
 shape3.print();
 shape4.print();
 return 0;
}

