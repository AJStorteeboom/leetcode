#include <iostream>


class Solution {
public:
	int memo[102][102];

	int uniquePaths(int m, int n) {
		return findTotalPaths(m, n, 1, 1);
	}

	int findTotalPaths(int m, int n, int currentM, int currentN) {
		if(currentM == m && currentN == n) return 1;
		if(memo[currentM][currentN] != 0) return memo[currentM][currentN];

		int total = 0;

		if(currentM <= m) total += findTotalPaths(m, n, currentM+1, currentN);
		if(currentN <= n) total += findTotalPaths(m, n, currentM, currentN+1);

		memo[currentM][currentN] = total;

		return memo[currentM][currentN];
	}
};


int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
