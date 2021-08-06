#include <iostream>
#include <string.h>
using namespace std;
class String;
ostream& operator<<(ostream& output, const String& s);
class String
{
	friend ostream& operator<<(ostream& output, const String& s);
public:
	String(char* str = (char*)"")
	{
		length = strlen(str) + 1;
		sPtr = new char[length];
		for (int i = 0; i <= length - 1; i++) sPtr[i] = str[i];
	}
	String(const String& str)
	{
		length = str.length;
		sPtr = new char[length];
		for (int i = 0; i <= length - 1; i++) sPtr[i] = str.sPtr[i];
	}
	~String()
	{
		delete[] sPtr;
		sPtr = NULL;
		length = 0;
	}
	const String operator=(const String& str)
	{
		length = strlen(str.sPtr) + 1;

		delete[] sPtr;
		sPtr = new char[length];

		for (int i = 0; i <= length - 1; i++) sPtr[i] = str.sPtr[i];
		return *this;
	}
	String operator+(const String& str)
	{
		int len = length + str.length;
		char* s = new char[len];
		strcpy(s, sPtr);
		s[length - 1] = ' ';
		s[length] = 0;
		strcat(s, str.sPtr);
		String temp(s);
		delete[] s;
		s = NULL;
		return temp;
	}
private:
	char* sPtr;
	int length;
};
ostream& operator<<(ostream& output, const String& s)
{
	cout << s.sPtr;
	return output;
}
int main()
{
	String string1, string2((char*)"The date is");
	String string3((char*)"August 1, 1993");

	cout << "string1 = string2 + string3\n";
	string1 = string2 + string3;
	cout << string1 << " = "
		<< string2 << " + " << string3 << endl;
}

