#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	vector<int> prices;
	int memo[5001][2];

	int dp(int currentDay, int holding) {
		//Base cases
		if(currentDay >= prices.size()) return 0;
		if(memo[currentDay][holding] != 0) return memo[currentDay][holding];

		if(holding == 0) {
			memo[currentDay][holding] = max(
					dp(currentDay+1, holding), //do nothing
					-prices[currentDay]+dp(currentDay+1, 1) //Buy
			);
		} else {
			memo[currentDay][holding] = max(
					dp(currentDay+1, holding), //do nothing
					prices[currentDay]+dp(currentDay+2, 0) //Sell and take cool off day
			);
		}

		//Memoize optimal solution
		return memo[currentDay][holding];
	}

	int maxProfit(vector<int>& prices) {
		for(int x = 0; x < 5001; x++) {
			memo[x][0] = 0;
			memo[x][1] = 0;
		}

		this->prices = prices;
		return dp(0, 0);
	}
};

int main() {
	Solution sol;

	vector<int> prices = {1};

	std::cout << sol.maxProfit(prices) << std::endl;
	return 0;
}
