#include <iostream>


using namespace std;

class Solution {
public:
	int memo[100] = {0};
	string s;

	int dp(int index) {
		if(s[index] == '0') return 0; //Invalid option. Can't start with a zero;
		if(index == s.size()) return 1; //Base case
		if(memo[index] != 0) return memo[index]; //memoization;

		if(s[index] == '1') {
			if(index < s.size()-1) {
				//If the next number is not a 0, there are two ways to walk. Otherwise 1 way.
				memo[index] = (s[index+1] != 0) ? dp(index+1) + dp(index+2) : dp(index+2);
			} else {
				memo[index] = dp(index+1);
			}
		} else if(s[index] == '2') {
			if(index < s.size()-1) {
				if(s[index+1] != '0') {
					//If next number is lower than 6, there are two ways to walk. Otherwise 1 way.
					memo[index] = ((int) s[index+1] <= 54) ? dp(index+1) + dp(index+2) : dp(index+1);
				} else {
					//Must include the 0 in the number so there's only one way.
					memo[index] = dp(index+2);
				}
			} else {
				memo[index] = dp(index+1);
			}
		} else {
			memo[index] = dp(index+1);
		}

		return memo[index];
	}

	int numDecodings(string s) {
		if(s.size() == 1) return (s[0] == '0') ? 0 : 1;
		this->s = s;

		return dp(0);
	}
};


int main() {
	Solution sol;
	std::cout << sol.numDecodings("2101") << std::endl;
	return 0;
}
