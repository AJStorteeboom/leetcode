#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
	int memo[1000][1000] = {};

	int recurse(vector<int>& nums, vector<int>& multipliers, int k, int i) {
		if(k == multipliers.size()) return 0;
		if(memo[k][i] != 0) return memo[k][i];

		cout << "calc k " << k << " - i " << i << endl;

		int maxValue = max(
				nums[i]*multipliers[k]+recurse(nums, multipliers, k+1, i+1),
				nums[nums.size()-1-(k-i)]*multipliers[k]+recurse(nums, multipliers, k+1, i)
		);

		memo[k][i] = maxValue;
		return maxValue;
	}

	int maximumScore(vector<int>& nums, vector<int>& multipliers) {
		if(nums.size() == 1) return nums[0] * multipliers[0];
		return recurse(nums, multipliers, 0, 0);
	}
};


int dp(vector<int>& nums, vector<int>& multipliers, int k, int i, int j) {
	if(i > j || k == multipliers.size()) return 0;
	if(nums[i]*multipliers[k]>nums[j]*multipliers[k]) {
		cout << "k " << k << " - front " << endl;
		return nums[i]*multipliers[k] + dp(nums, multipliers, k+1, i+1, j);
	} else {
		cout << "k " << k << " - end= " << endl;
		return nums[j]*multipliers[k] + dp(nums, multipliers, k+1, i, j-1);
	}
}

int maximumScore(vector<int>& nums, vector<int>& multipliers) {
	if(nums.size() == 1) return nums[0] * multipliers[0];
	return dp(nums, multipliers, 0, 0, nums.size()-1);
}


int main() {
	vector<int> nums = {-5,-3,-3,-2,7,1};
	vector<int> multipliers = {-10,-5,3,4,6};

	Solution solution;
	cout << solution.maximumScore(nums, multipliers) << endl;
	//std::cout << maximumScore(nums, multipliers) << std::endl;
	return 0;
}
