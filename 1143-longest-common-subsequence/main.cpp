#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int memo[1001][1001] = {0};
	int text1Length;
	int text2Length;
	string text1;
	string text2;

	int dp(int i, int j) {
		//base cases
		if(memo[i][j] != 0) return memo[i][j];
		if(i == text1Length || j == text2Length) return 0;

		//recurrence relation
		int val = (text1[i] == text2[j]) ? 1+dp(i+1, j+1) : max(dp(i, j+1), dp(i+1, j));


		memo[i][j] = val;
		return memo[i][j];
	}

	int longestCommonSubsequence(string text1, string text2) {
		this->text1 = text1;
		this->text2 = text2;
		this->text1Length = text1.size();
		this->text2Length = text2.size();
		return dp(0, 0);
	}
};

int main() {
	Solution sol;
	std::cout << sol.longestCommonSubsequence("abcde", "ace") << std::endl;
	return 0;
}
