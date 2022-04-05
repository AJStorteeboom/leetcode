#include <iostream>

using namespace std;



class Solution {
public:
	int numWays(int n, int k) {
		if (n == 1) return k;
		if (n == 2) return k * k;

		int memo[51];
		memo[0] = k;
		memo[1] = k*k;

		for(int x = 2; x < n; x++) {
			memo[x] = (k-1) * (memo[x-1] + memo[x-2]);
		}

		return memo[n-1];
	}
};

int main() {
	Solution sol;
	std::cout << sol.numWays(7,2) << std::endl;
	return 0;
}
