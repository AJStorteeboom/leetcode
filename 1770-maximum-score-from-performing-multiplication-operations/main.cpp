#include <iostream>
#include <vector>

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

	int maximumScoreBottomUp(vector<int>& nums, vector<int>& multipliers) {
		int n = nums.size();
		int m = multipliers.size();

			int** dp = new int[m + 1][m + 1];

		for (int i = m - 1; i >= 0; i--) {
			for (int left = i; left >= 0; left--) {
				int mult = multipliers[i];
				int right = n - 1 - (i - left);
				dp[i][left] = Math.max(mult * nums[left] + dp[i + 1][left + 1],
									   mult * nums[right] + dp[i + 1][left]);
			}
		}

		return dp[0][0];
	}
};


int main() {
	vector<int> nums = {-5,-3,-3,-2,7,1};
	vector<int> multipliers = {-10,-5,3,4,6};

	Solution solution;
	cout << solution.maximumScore(nums, multipliers) << endl;
	//std::cout << maximumScore(nums, multipliers) << std::endl;
	return 0;
}
