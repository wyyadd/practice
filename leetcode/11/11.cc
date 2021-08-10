/* dp algrithime
class Solution {
public:
    int maxArea(vector<int>& height) {
			int dp[height.size()]; 
			for(int i = 0; i < height.size(); ++i)
				dp[i] = 0;
			for(int	i = 1; i < height.size(); ++i)
				for(int j = 0; j < height.size() - i; ++j)
					dp[j] = max({dp[j],dp[j+1],i * min(height[j],height[j+i])});
			return dp[0];
    }
};
*/
//Container With Most Water
//We take two pointers, one at the beginning and one at the end of the array constituting the length of the lines. Futher, we maintain a variable \text{maxarea}maxarea to store the maximum area obtained till now. At every step, we find out the area formed between them, update \text{maxarea}maxarea and move the pointer pointing to the shorter line towards the other end by one step.
class Solution {
public:
    int maxArea(vector<int>& height) {
			int maxarea = 0, l = 0, r = height.size() - 1;
			while(l < r) {
				maxarea = max({maxarea, (r-l)*min(height[l], height[r])});
				//贪心？greedy
				if(height[l] < height[r])
					l++;
				else
					r--;
			}
			return maxarea;
    }
};

