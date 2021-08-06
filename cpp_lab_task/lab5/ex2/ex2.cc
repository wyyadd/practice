#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class Stu
{
public:
	Stu(char* ID="21319xxxx", char* Fn="Lily", char* Ln="Judy", int gra=0)
	{
		strcpy(id, ID);
		strcpy(firstName, Fn);
		strcpy(lastName, Ln);
		if(gra>=0 && gra<=100) grade=gra;
	}
	int getgrade()
	{
		return grade;
	}
	void changeid(char* ID="21319xxxx")
	{
		strcpy(id, ID);
	}
	void changefirstName(char* Fn="Lily")
	{
		strcpy(firstName, Fn);
	}
	void changelasName(char* Ln="Judy")
	{
		strcpy(lastName, Ln);
	}
	void changegrade(int gra=0)
	{
		if(gra>=0 && gra<=100) grade=gra;		
	}
	void display()
	{
		cout<<"id: "<<id<<",  firstName: "<<firstName<<",  lastName: "<<lastName<<",  grade: "<<grade<<endl;
	}
private:
	char id[30];
	char firstName[30];
	char lastName[30];
	int grade;
};

int main()
{
	int amount=4;
	Stu temp[5]={Stu("213193896", "Lisa", "Lily", 93), Stu("213193333", "Janny", "Dan", 95),
				 Stu("213192222", "James", "Brown", 97), Stu("213191111", "Jane", "Van", 99)};


	fstream file("file.dat", ios::out | ios::binary);
	if(!file) 
	{
		cerr<<"open error! "<<endl;
		exit(0);
	}

	file.write((char*)&amount, sizeof(amount));
	file.write((char*)temp, amount*sizeof(temp[0]));  // " output Students' amount "

	file.close();  // " output Students' data "

	cout<<"After reading: "<<endl;
	fstream readFile("file.dat", ios::in | ios::binary);
	if(!readFile) 
	{
		cerr<<"open error! "<<endl;
		exit(0);
	}
	
	readFile.read((char*)&amount, sizeof(amount));
	for(int i=0; i<=amount-1; i++)
	{
		readFile.read((char*)&temp[i], sizeof(temp[i]));
		temp[i].display();
	}  // " input Students' data "

	char ID[30], f[30], l[30]; 
	int g=0;
	cout<<"\nplease input id, firstName, lastName, grade to add an students"<<endl;
	cin>>ID>>f>>l>>g;
	temp[4]=Stu(ID, f, l, g);
	amount++;

	readFile.write((char*)&amount, sizeof(amount));
	readFile.write((char*)temp, amount*sizeof(temp[0]));  // " reoutput Students' amount "

	cout<<"\nAfter adding: "<<endl;
	readFile.read((char*)&amount, sizeof(amount));
	for(int i=0; i<=amount-1; i++)
	{
		readFile.read((char*)&temp[i], sizeof(temp[i]));
		temp[i].display();
	}  // " reinput Students' data "

	cout<<"\ninput a number to change Lisa's grade: "<<endl;
	cin>>g;
	temp[0].changegrade(g);

	readFile.write((char*)&amount, sizeof(amount));
	readFile.write((char*)temp, amount*sizeof(temp[0]));

	cout<<"\nAfter changing Lisa's grade: "<<endl;
	readFile.read((char*)&amount, sizeof(amount));
	int total=0;
	for(int i=0; i<=amount-1; i++)
	{
		readFile.read((char*)&temp[i], sizeof(temp[i]));
		temp[i].display();
		total+=temp[i].getgrade();
	}
	cout<<"\nAnd the average grade is: "<<total/amount<<endl;

}

