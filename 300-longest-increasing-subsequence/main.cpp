#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int memo[2500] = {0};

	int lengthOfLIS(vector<int>& nums) {
		int maxVal = 0;

		for(int i = 1; i < nums.size(); i++) {
			for(int j = 0; j < i; j++) {
				if(nums[i] > nums[j]) {
					memo[i] = max(memo[i], memo[j]+1);
					maxVal = max(maxVal, memo[i]);
				}
			}
		}

		return maxVal+1;
	}
};

int main() {
	Solution sol;
	vector<int> nums = {7,7,7,7,7,7,7};
	std::cout << sol.lengthOfLIS(nums) << std::endl;
	return 0;
}
