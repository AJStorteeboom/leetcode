#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {

public:
	vector<int> coins;
	int totalCoins;
	unordered_map<int,int> memo;

	int dp(int amount) {
		if(amount == 0) return 0;
		if(memo.find(amount) != memo.end()) return memo[amount];

		memo[amount] = INT_MAX;

		for(int x = 0; x < totalCoins; x++) {
			if(coins[x] > amount) continue;
			int res = dp(amount-coins[x]);
			if(res != -1) memo[amount] = min(memo[amount],1+res);
		}

		if(memo[amount] == INT_MAX) memo[amount] = -1;
		return memo[amount];
	}

	int coinChange(vector<int>& coins, int amount) {
		this->coins = coins;
		this->totalCoins = coins.size();
		return dp(amount);
	}
};

int main() {
	Solution sol;

	vector<int> coins = {2};

	std::cout << sol.coinChange(coins, 12) << std::endl;
	return 0;
}
