#include <iostream>
#include <cstring>

namespace{
using std::ostream;

class MyString{
public:
	MyString(){};

	MyString(const char* str){
		s = new char[strlen(str) + 1];
		strcpy(s, str);
	}

	explicit MyString(const MyString& temp){
		s = new char[strlen(temp.s) + 1];
		strcpy(s, temp.s);
	}

	MyString &operator += (const MyString& temp){
		std::strcat(s,temp.s);
		return *this;
	}

	MyString &operator = (const MyString& temp){
		s = new char[strlen(temp.s) + 1];
		strcpy(s, temp.s);
		return *this;
	}

	friend ostream &operator << (ostream &os, MyString &temp);

	void test(){
		std::cout << s << std::endl;
	}

	~MyString(){
		delete[] s;
	}
private:
	char* s;
};

ostream& operator<<(ostream &os, MyString &temp){
	return os<<temp.s;
}

}//namespace

int main(){
	MyString s1("Hello, ");
	MyString s2(s1);
	MyString s3("SEU!");
	MyString s4;
	s4 = s3;
	s2 += s3;
	std::cout<<s1<<std::endl<<s2<<std::endl<<s3<<std::endl<<s4<<std::endl;
}
