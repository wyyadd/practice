#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

namespace{
using std::string;
using std::vector;
using std::fstream;

class Person{
public:
	Person(const string name, const string phone_number){
		name_ = name;
		phone_number_ = phone_number;
	}
	void SetName(string name){
		name_ = name;
	}
	void SetPhoneNumber(string phone_number){
		phone_number_ = phone_number;
	}
	string GetName(){
		return name_;
	}	
	string GetPhoneNumber(){
		return phone_number_;
	}
	void Show_Info(){
		std::cout<<"Name:"<<name_<<", Tel:"<<phone_number_<<std::endl;
	}

	bool operator< (const Person &temp){
		return name_ < temp.name_;
	}
private:
	string name_;
	string phone_number_;
};

class Contact{
public:
	void Read(){
		std::ifstream infile("contact.txt", std::ios::in);
		string temp1;
		string temp2;
		while(!EOF){
			getline(std::cin,temp1);
			getline(std::cin,temp2);
			Person *temp = new Person(temp1,temp2);
			persons_.push_back(*temp);
		}
		infile.close();
	}
	void Write(){
		std::ofstream outfile("contact.txt", std::ios::out);
		for(auto i : persons_)
			outfile<<i.GetName()<<std::endl<<i.GetPhoneNumber()<<std::endl;
		outfile.close();
	}
	void UI(){
		Read();
		bool exit_flag = false;
		int choice;
		while(!exit_flag){
			std::cout<<"1.Display all person information sorted by name"<<std::endl;
			std::cout<<"2.Input a new person's information"<<std::endl;
			std::cout<<"3.Delete a person's information specified by name"<<std::endl;
			std::cout<<"4.Modify a person's mobile phone number specified by name"<<std::endl;
			std::cout<<"5.Exit the system"<<std::endl;
			std::cout<<"Your choice: ";
			std::cin>>choice;
			switch (choice){
				case 1: Display(); break;
				case 2: Input(); break;
				case 3: Delete(); break;
				case 4: Modify(); break;
				case 5: exit_flag = true; break;
				default: std::cout<<"Wrong Number! Please Input again"<<std::endl;
			}
		}
		std::cout<<"Exit!"<<std::endl;
		Write();
	}
	
	void Display(){
		std::sort(persons_.begin(), persons_.end());
		for(auto i : persons_)
			i.Show_Info();
	}

	void Input(){
		string name,phone;
		std::cout<<"Name: ";
		std::cin>>name;
		std::cout<<"phone_number: ";
		std::cin>>phone;
		Person *temp = new Person(name,phone);
		persons_.push_back(*temp);
	}

	void Delete(){
		string name;
		std::cout<<"Please input name: ";
		std::cin>>name;
		for(auto i = persons_.begin(); i != persons_.end(); ++i){
			if((*i).GetName() == name){
				persons_.erase(i);
				std::cout<<"Succesfully deleted"<<std::endl;
				return;
			}
		}
		std::cout<<"Failed to delete"<<std::endl;
	}

	void Modify(){
		string name;
		string phone_number;
		std::cout<<"Please input name: ";
		std::cin>>name;
		for(auto i : persons_){
			if(i.GetName() == name){
				std::cout<<"Succesfully Find, Please input new phone_number:"<<std::endl;
				std::cin>>phone_number;
				i.SetPhoneNumber(phone_number);	
				std::cout<<"Succesfully"<<std::endl;
				return;
			}
		}
		std::cout<<"Failed to Find"<<std::endl;
	}

		
private:
	vector<Person> persons_;
	
};
}//namespace

int main(){
	Contact foo;
	foo.UI();
}
