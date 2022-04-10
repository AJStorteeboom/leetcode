#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int memo[201][201];

	vector<vector<int>> grid;

	int dp(int m, int n) {
		if(m == grid.size()-1 && n == grid[0].size()-1) return grid[m][n];
		if(memo[m][n] != -1) return memo[m][n];

		int pos1 = INT_MAX;
		int pos2 = INT_MAX;

		if(m < grid.size()-1) pos1 = dp(m+1, n);
		if(n < grid[0].size()-1) pos2 = dp(m, n+1);

		memo[m][n] = grid[m][n] + min(pos1, pos2);
		return memo[m][n];
	}

	int minPathSum(vector<vector<int>>& grid) {
		this->grid = grid;

		for(int x = 0; x < 201; x++) {
			for(int y = 0; y < 201; y++) memo[x][y] = -1;
		}

		return dp(0,0);
	}
};

int main() {
	Solution sol;
	
	vector<vector<int>> grid = {
			{{1,2,3},{4,5,6}}
	};
	
	std::cout << sol.minPathSum(grid) << std::endl;
	return 0;
}
