//Integer to Roman
class Solution {
	vector<pair<string, int>> roman;
public:
	void init(){
		roman.push_back(make_pair("I",1));
		roman.push_back(make_pair("IV",4));
		roman.push_back(make_pair("V",5));
		roman.push_back(make_pair("IX",9));
		roman.push_back(make_pair("X",10));
		roman.push_back(make_pair("XL",40));
		roman.push_back(make_pair("L",50));
		roman.push_back(make_pair("XC",90));
		roman.push_back(make_pair("C",100));
		roman.push_back(make_pair("CD",400));
		roman.push_back(make_pair("D",500));
		roman.push_back(make_pair("CM",900));
		roman.push_back(make_pair("M",1000));
	}
    string intToRoman(int num) {
			init();
			string ans;
			for(auto i = roman.end(); i >= roman.begin() && ans; --i){ 
				while(num / (*i).second){
					ans += (*i).first;
					num -= (*i).second;
				}
			}
			return ans;
    }
};
