class Solution {
public:
    int maxProfit(vector<int>& prices) {
			
			// generate max_prices array, max_prices[i] -> from i to end, the max val
			vector<int> max_prices(prices.size() - 1);       
			int temp_max = prices.back();
			for(auto i = prices.size() - 1; i > 0; --i){
					temp_max  = max(prices[i], temp_max); 	
					max_prices[i-1] = temp_max;
			}
			// walk
			int result = 0;
			for(auto i = 0; i < max_prices.size(); ++i){
				result = max(max_prices[i] - prices[i], result);
			}
			return result;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;
        int minprice = inf, maxprofit = 0;
        for (int price: prices) {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(price, minprice);
        }
        return maxprofit;
    }
};
