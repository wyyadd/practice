#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int myAtoi(string s) {
		long ans = 1;
		int po = 0;
		bool negtive = false;
		while(!(s[po] <= '9' && s[po] > '0')){
			if(s[po] == '-'){
				negtive = true;
				++po;
				break;
			} else if(s[po] == '+'){
				negtive = false;
				++po;
				break;
			} else if(s[po] != '0' && s[po] != ' ')
				return 0;
			++po;
		}
		if(s[po] <= '9' && s[po] > '0')
			ans *= s[po++] - '0';
		else 
			return 0;
		for(; po < s.size(); ++po){
			if(s[po] <= '9' && s[po] >= '0'){
				ans = ans*10 + s[po]-'0';
				if(negtive && -ans < INT32_MIN)
					return INT32_MIN;
				if(!negtive && ans > INT32_MAX)
					return INT32_MAX;
			}
			else
				break;
		}
		return negtive ? -ans : ans;
	}
};

int main(){
	auto s = new Solution;
	cout << s->myAtoi("words and 987");
}