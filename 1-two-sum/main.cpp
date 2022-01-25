#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> prevMap;

	for(int x = 0; x < nums.size(); x++) {
		auto findResult = prevMap.find(target-nums[x]);

		if(findResult != prevMap.end()) {
			return vector<int> {x, findResult->second};
		} else {
			prevMap.insert(pair<int,int>(nums[x], x));
		}
	}

	return vector<int>();
}

int main() {
	vector<int> nums = {3,2,4};
	vector<int> indices = twoSum(nums, 6);

	if(indices[0] + indices[1] == 6) {
		cout << "Correct answer!" << endl;
	} else {
		cout << "Wrong answer!" << endl;
	}

	return 0;
}
