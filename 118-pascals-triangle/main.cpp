#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp(int numRows, vector<vector<int>>& ans, int currentRow) {
	if(currentRow > numRows) return ans;

	vector<int> row = {1};

	for(int x = 1; x < currentRow-1; x++) {
		row.push_back(ans[currentRow-2][x-1]+ans[currentRow-2][x]);
	}

	row.push_back(1);
	ans.push_back(row);

	return dp(numRows, ans, currentRow+1);
}

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> ans = {{1}};
	if(numRows == 1) return ans;
	ans.push_back({1,1});
	dp(numRows, ans, 3);


	return ans;
}


int main() {
	vector<vector<int>> ans = generate(5);
	for(vector<int> row : ans) {
		for(int value : row) {
			cout << value << " - ";
		}
		cout << endl;
	}

	std::cout << "Hello, World!" << std::endl;
	return 0;
}
