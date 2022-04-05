#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> coins;
	int memo[5001];

	int change(int amount, vector<int>& coins) {
		memo[0] = 1;

		for(int coin : coins) {
			for(int x = 1; x <= amount; x++) {
				if(x - coin >= 0) memo[x] = memo[x]+memo[x-coin];
			}
		}

		return memo[amount];
	}
};

int main() {
	Solution sol;

	vector<int> coins = {1,2,5};

	std::cout << sol.change(5, coins) << std::endl;
	return 0;
}
