//Letter Combinations of a Phone Number
class Solution {
		vector<string> arr[10];
public:
		void initialize(){
			arr[2] = vector<string>{"a","b","c"};
			arr[3] = vector<string>{"d","e","f"};
			arr[4] = vector<string>{"g","h","i"};
			arr[5] = vector<string>{"j","k","l"};
			arr[6] = vector<string>{"m","n","o"};
			arr[7] = vector<string>{"p","q","r","s"};
			arr[8] = vector<string>{"t","u","v"};
			arr[9] = vector<string>{"w","x","y","z"};
		}
    vector<string> letterCombinations(string digits) {
			vector<string> ans;
			if(digits.length() == 0)
				return ans;
			initialize();
			ans = arr[digits[0] - '0'];
			//loop
			for(int i = 1; i < digits.length(); ++i){
				vector<string> temp;
				//loop
				for(auto &x : ans){
					//loop
					for(auto &y : arr[digits[i] - '0'])
						temp.push_back(x+y);
				}
				ans = temp;
			}
			return ans;
    }
};
