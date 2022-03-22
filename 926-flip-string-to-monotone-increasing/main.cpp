#include <iostream>

using namespace std;




class Solution {
public:
	int memo[100000];


	//I don't know why it works, but it works ;)
	int dp(string& s, int currentIndex, bool oneSeries) {
		if(currentIndex == s.length()) return 0;
		//cout << currentIndex << " - " << s[currentIndex] << " - " << oneSeries << endl;
		if(memo[currentIndex] != -1) {
			return memo[currentIndex+1];
		}

		if(s[currentIndex] == '0') {
			if(oneSeries) {
				memo[currentIndex+1] = dp(s, currentIndex+1, true)+1;
				cout << "1 - " << currentIndex << " - " << memo[currentIndex] << endl;
			} else {
				memo[currentIndex+1] = min(dp(s, currentIndex+1, false), dp(s, currentIndex+1, true)+1);
				cout << "2 - " << currentIndex << " - " << memo[currentIndex] << endl;
			}
		} else {
			if(oneSeries) {
				memo[currentIndex+1] = dp(s, currentIndex+1, true);
				cout << "3 - " << currentIndex << " - " << memo[currentIndex] << endl;
			} else {
				memo[currentIndex+1] = min(dp(s, currentIndex+1, false)+1,dp(s, currentIndex+1, true));
				cout << "4 - " << currentIndex << " - " << memo[currentIndex] << endl;
			}
		}

		return memo[currentIndex+1];
	}

	int minFlipsMonoIncr(string s) {
		fill_n(this->memo, 100000, -1);
		return dp(s, 0, false);
	}
};



int main() {
	Solution sol;
	std::cout << sol.minFlipsMonoIncr("010110") << std::endl;
	return 0;
}
