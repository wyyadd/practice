//Valid Parentheses
//use stack
class Solution {
public:
    bool isValid(string s) {
			if(s.length() % 2)
				return false;
			stack<char> ans;
			for(auto i : s){
				if(i == '('){
					ans.push(')');
					continue;
				}
				else if(i == '['){
					ans.push(']');
					continue;
				}
				else if(i == '{'){
					ans.push('}');
					continue;
				}
				else if (ans.empty() || ans.top() != i){
					return false;
				}
				ans.pop();
			}
			return ans.empty();
    }
};
