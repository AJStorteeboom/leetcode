#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int currentMaxProfit = 0;
		int currentLowestBuy = -1;
		int currentHighestSell = -1;

		for(int x = 0; x < prices.size(); x++) {
			if(currentLowestBuy == -1 || currentLowestBuy > prices[x]) {
				currentLowestBuy = prices[x];
				currentHighestSell = 0;
			} else if(currentHighestSell == -1 || currentHighestSell < prices[x]) {
				currentHighestSell = prices[x];
				currentMaxProfit = max(currentMaxProfit, currentHighestSell-currentLowestBuy);
			}
		}

		return currentMaxProfit;
	}
};


int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
