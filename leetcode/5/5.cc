//ZigZag Conversion
class Solution {
public:
    string convert(string s, int numRows) {
			if(numRows == 1)
				return s;
			//answer: string
			string ans;
			//规律: numRows = 5, stripes:	7,5,3,1,7 
			//规律: numRows = 4, stripes: 5,3,1,5
			//规律: numRows = 3, stripes: 3,1,3
			int stripes[numRows];
			int stripe = 2*numRows - 3;
			for(int i = 0; i < numRows - 1; ++i){
				stripes[i] = stripe;
				stripe -= 2;
			}
			stripes[numRows - 1] = stripes[0];
			for(int row = 0; row < numRows; ++row) {
				int po = row;	
				bool flag = true;
				while(po < s.length()){
					ans += s[po];
					//beacuse Zig-zag, 有时候会拐弯， 布长会变
					if(flag)
						po += stripes[row] + 1;
					else
						po += stripes[numRows - 1 - row] + 1;
					flag = !flag;
				}
			}
			return ans;
    }
};
