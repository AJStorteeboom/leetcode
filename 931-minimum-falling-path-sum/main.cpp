#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> matrix;
	int memo[101][101];

	int dp(int m, int n) {
		if(m == matrix.size()-1) return matrix[m][n];
		if(memo[m][n] != INT_MAX) return memo[m][n];

		vector<int> possiblePaths;

		if(n > 0) possiblePaths.push_back(dp(m+1, n-1));
		if(n < matrix.size()-1) possiblePaths.push_back(dp(m+1, n+1));

		possiblePaths.push_back(dp(m+1, n));

		memo[m][n] = matrix[m][n] + *min_element(possiblePaths.begin(), possiblePaths.end());

		return memo[m][n];
	}

	int minFallingPathSum(vector<vector<int>>& matrix) {
		this->matrix = matrix;

		int minVal = INT_MAX;

		for (int i = 0; i < 101; i++) {
			for(int j = 0; j < 101; j++) memo[i][j] = INT_MAX;
		}

		for(int x = 0; x < matrix.size(); x++) minVal = min(minVal, dp(0, x));

		return minVal;
	}
};


int main() {
	Solution sol;

	vector<vector<int>> matrix = {
			{{2,1,3},{6,5,4},{7,8,9}}
	};


	std::cout << sol.minFallingPathSum(matrix) << std::endl;
	return 0;
}
