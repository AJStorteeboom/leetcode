#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int counter = 0;
	//TLE
	int dp(int index, vector<int> nums) {
		if(nums.empty()) return 0;
		counter++;

		int startAtNextIndex = 0;
		if(index < nums.size()-1) startAtNextIndex = dp(index+1, nums);

		int currentBalloonValue = nums[index];
		nums.erase(nums.begin()+index);

		int leftBalloon = (index > 0) ? nums[index-1] : 1;
		int rightBalloon = (index < nums.size()) ? nums[index] : 1;

		return max(leftBalloon*currentBalloonValue*rightBalloon + dp(0, nums), startAtNextIndex);
	}

	int maxCoins(vector<int>& nums) {
		return dp(0, nums);
	}
};

int main() {
	//vector<int> balloons = {1,5,7,5,4,2,4,5,6,7,8,90,87,6,5,4,3,2,1,3,4,5,6,7,8,5,4,3,2,2,4,4,5,67,7,8,6,5,4,3,2,2,4,4,5,6,7,7,8,6,55,4,3,2,2,4,4,5,5,6,77,8,9,9,88,7,6,55,44,33,3,3,5,5,6,6,6,44,3,2,1,2,3,4,5,6,6,7,7,8,9,1,9,8,7,6,5,4,4,3,3,3};
	vector<int> balloons = {9,1,1,1,9};

	Solution sol;

	std::cout << sol.maxCoins(balloons) << std::endl;
	cout << sol.counter << endl;
	return 0;
}
