#include<iostream>
#include<stack>
using namespace std;
class Solution {
public:
	string decodeString(string s) {
		stack<string> string_stack;
		stack<int> number_stack;
		for(auto i = 0 ; i < s.size(); ++i){
			if(s[i]	>= '0' && s[i] <= '9'){
				number_stack.push(getNumber(s,i));
				continue;
			}
			if(s[i] >= 'a' && s[i] <= 'z'){
				string_stack.push(getString(s,i));
				continue;
			}
			if(s[i] == '['){
				string_stack.push("[");
				continue;
			}
			if(s[i] == ']'){
				int num = number_stack.top();
				number_stack.pop();
				string str;
				while(string_stack.top() != "["){
					str.insert(0,string_stack.top());
					string_stack.pop();
				}
				string decode;
				for(int j = 0; j < num; ++j){
					decode+=str;
				}
				string_stack.pop();
				string_stack.push(decode);
			}
		}
		string ans;
		while (!string_stack.empty())
		{
			ans.insert(0,string_stack.top());
			string_stack.pop();
		}
		return ans;
	}

	int getNumber(string& s, int& po){
		string number;
		number += s[po++];
		while(po != s.size()){
			if(s[po] < '0' || s[po] > '9')
				break;
			number+=s[po++];
		}
		--po;
		return stoi(number);

	}

	string getString(string& s, int& po){
		string str;
		str += s[po++];
		while(po != s.size()){
			if(s[po] < 'a' || s[po] > 'z')
				break;
			str+=s[po++];
		}
		--po;
		return str;
	}
};

int main(){
	auto s = new Solution;
	cout << s->decodeString("abc2[abc]3[cd]ef");
}
