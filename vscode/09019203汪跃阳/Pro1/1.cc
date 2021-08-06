#include <iostream>

namespace{
using std::string;

class Browser{
 public:
	 virtual void open(string site) = 0;
	 virtual ~Browser(){};
 private:
	 char* nameofWebBrowser;
};

class IE :public Browser{
 public:
	 IE(){
	 }
	 void open(string site){
			std::cout<<site<<std::endl;	
			std::cout<<"opened by "<<nameofWebBrowser<<std::endl;
	 }
	 ~IE(){
		 std::cout<<"~"<<nameofWebBrowser<<std::endl;
	 }
 private:
	 string nameofWebBrowser = "IE";
};

class firefox :public Browser{
 public:
	 firefox(){
	 }
	 void open(string site){
			std::cout<<site<<std::endl;	
			std::cout<<"opened by "<<nameofWebBrowser<<std::endl;
	 }
	 ~firefox(){
		 std::cout<<"~"<<nameofWebBrowser<<std::endl;
	 }
 private:
	 string nameofWebBrowser = "firefox";
};
}//namespace

int main(){
	Browser* pb = new IE();
	pb->open("www.microsoft.com");
	delete pb;
	pb = NULL;
	pb = new firefox();
	pb->open("www.firefox.com");
	delete pb;
	pb = NULL;
}
