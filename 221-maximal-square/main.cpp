#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int memo[301][301] = {0};

	int maximalSquare(vector<vector<char>>& matrix) {
		int rows = matrix.size();
		int cols = matrix[0].size();
		int maxVal = 0;

		for(int i = 1; i <= rows; i++) {
			for(int j = 1; j <= cols; j++) {
				if(matrix[i-1][j-1] == '1') {
					memo[i][j] = min({memo[i-1][j], memo[i-1][j-1], memo[i][j-1]}) + 1;
					maxVal = max(maxVal, memo[i][j]);
				}
			}
		}

		return maxVal*maxVal;
	}
};


int main() {

	return 0;
}
