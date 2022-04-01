#include <iostream>
#include <vector>
#include <map>

using namespace std;


//Solution 1:
//Using memoization
class Solution1 {
	std::map<int, int> memoization;

public:
	int minCost(std::vector<int> &cost, int n) {
		if (n < 0) return 0;
		if (n==0 || n==1) return cost.at(n);
		if (memoization.find(n) != memoization.end()) return memoization.at(n);
		memoization.insert(std::pair<int, int>(n, cost.at(n) + std::min(minCost(cost, n-1), minCost(cost, n-2))));
		return memoization.at(n);
	}

	int minCostClimbingStairs(std::vector<int> &cost) {
		int n = cost.size();
		return std::min(minCost(cost, n-1), minCost(cost, n-2));
	}
};


//Solution 2:
//Bottom up approach
class Solution2 {
public:
	int minCostClimbingStairs(std::vector<int> &cost) {
		int memo[1001] = {0,0};

		for(int x = 2; x <= cost.size(); x++) {
			memo[x] = min(memo[x-1]+cost[x-1], memo[x-2]+cost[x-2]);
		}

		return memo[cost.size()];
	}
};


//Solution 3:
//Bottom up approach with state reduction
class Solution3 {
public:
	int minCostClimbingStairs(std::vector<int> &cost) {
		int downOne = 0;
		int downTwo = 0;

		for(int x = 2; x <= cost.size(); x++) {
			int temp = downOne;
			downOne = min(downOne+cost[x-1], downTwo+cost[x-2]);
			downTwo = temp;
		}

		return downOne;
	}
};

int main() {
	Solution2 solution3;
	vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
	std::cout << solution3.minCostClimbingStairs(cost) << std::endl;
	return 0;
}
