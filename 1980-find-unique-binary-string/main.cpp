#include <iostream>
#include <vector>

using namespace std;

string recursive(vector<string>& nums, string& currentString, int currentIndex) {
	if(find(nums.begin(), nums.end(),  currentString) == nums.end()) return currentString;
	if(currentIndex > currentString.size()) return "";

	currentString[currentIndex] = '1';
	string result = recursive(nums, currentString, currentIndex+1);
	currentString[currentIndex] = '0';
	return result;
}

string findDifferentBinaryString(vector<string>& nums) {
	std::string startString (nums.at(0).size(), '0');
	if(find(nums.begin(), nums.end(),  startString) == nums.end()) return startString;
	return recursive(nums, startString, 0);
}

int main() {
	vector<string> stringx = {"01", "10", "00"};
	std::cout << findDifferentBinaryString(stringx) << std::endl;
	return 0;
}
