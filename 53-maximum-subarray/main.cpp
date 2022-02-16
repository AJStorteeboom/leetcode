#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
	if(nums.size() == 1) return nums[0];

	int maxValue = nums[0];
	int currentValue = nums[0];

	for(int x = 1; x < nums.size(); x++) {
		currentValue = ((nums[x] + currentValue) > nums[x]) ? nums[x]+currentValue : nums[x];
		maxValue = max(maxValue, currentValue);
	}

	return maxValue;
}

int main() {
	vector<int> arr = {
			-1,1,-3,4,-1,2,1,-5,4
	};

	std::cout << maxSubArray(arr) << std::endl;
	return 0;
}
