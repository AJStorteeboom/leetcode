#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> wordDict;
	int stringSize;
	string s;
	int memo[300] = {0};

	bool dp(int index) {
		if(index == stringSize) {
			return true;
		}
		if(memo[index] != 0) return memo[index] != 1;

		for(int x = 0; x < wordDict.size(); x++) {
			bool validWord = true;
			int tempIndex = index;

			for(char& c : wordDict[x]) {
				if(tempIndex == stringSize || s[tempIndex] != c) {
					validWord = false;
					break;
				}
				tempIndex++;
			}

			if(validWord) {
				memo[index] = (memo[index] == 2 || dp(tempIndex)) ? 2 : 1;
			} else if(memo[index] != 2) {
				memo[index] = 1;
			}
		}

		return memo[index] != 1;
	}

	bool wordBreak(string s, vector<string>& wordDict) {
		this->wordDict = wordDict;
		this->stringSize = s.size();
		this->s = s;
		return dp(0);
	}
};

int main() {
	Solution sol;
	vector<string> wordDict = {"apple", "pen"};

	std::cout << sol.wordBreak("applepenapple", wordDict) << std::endl;
	return 0;
}
