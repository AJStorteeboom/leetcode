#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> prices;

	//3 dimensional array because 3 state variables;
	//1 current day
	//2 current amount of transactions left;
	//3 holding a stock (true/false)
	int memo[1001][101][2] = {0};

	int dp(int currentDay, int k, int holding) {
		//base cases
		if(currentDay == prices.size() || k == 0) return 0;
		if(memo[currentDay][k][holding] != 0) return memo[currentDay][k][holding];

		//recurrence relation depended on if holding or not
		if(holding == 0) {
			memo[currentDay][k][holding] = max(
					dp(currentDay+1, k, 0), //Do nothing
					-prices[currentDay]+dp(currentDay+1, k, 1) //Buy stock
			);
		} else {
			memo[currentDay][k][holding] = max(
					dp(currentDay+1, k, 1), //Do nothing
					prices[currentDay]+dp(currentDay+1, k-1, 0) //Sell stock
			);
		}

		//Memoize optimal solution
		return memo[currentDay][k][holding];
	}

	int maxProfit(int k, vector<int>& prices) {
		//Fill array with 0 because cpp default doesnt do this ;(
		for(int x = 0; x < 1001; x++) {
			for(int y = 0; y < 101; y++) {
				memo[x][y][0] = 0;
				memo[x][y][1] = 0;
			}
		}

		this->prices = prices;
		return dp(0, k, 0);
	}
};

int main() {
	Solution sol;
	vector<int> prices = {1,2,4};
	std::cout << sol.maxProfit(2, prices) << std::endl;
	return 0;
}
