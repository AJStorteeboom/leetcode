#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int n) {
	if(n == 0) return vector<int> {0};

	vector<int> ans = {0, 1};

	int offset = 2;
	for(int x = 2; x <= n; x++) {
		if(x == offset * 2) offset = offset * 2;
		ans.push_back(1+ans[x-offset]);
	}

	return ans;
}

int main() {
	countBits(213);
	return 0;
}
