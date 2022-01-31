#include <iostream>

using namespace std;

#include <unordered_set>

int lengthOfLongestSubstring(string s) {
	int aPointer = 0;
	int bPointer = 0;
	int currentMaxlength = 0;

	unordered_set<char> memory;

	while (bPointer < s.length()) {
		if(memory.find(s[bPointer]) == memory.end()) {
			memory.insert(s[bPointer]);
			bPointer++;
			currentMaxlength = max((int) memory.size(), currentMaxlength);
		} else {
			memory.erase(s[aPointer]);
			aPointer++;
		}
	}

	return currentMaxlength;
}


int main() {
	cout << lengthOfLongestSubstring("ynyo") << endl;

	return 0;
}
