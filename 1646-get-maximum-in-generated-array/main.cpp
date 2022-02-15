#include <iostream>
#include <vector>

using namespace std;

int getMaximumGenerated(int n) {
	if(n == 0) return 0;
	if(n <= 2) return 1;

	vector<int> ans = vector<int>(n+1, 0);
	ans[1] = 1;

	int currentMaxValue = 1;

	for(int x = 1; x < n/2+1; x++) {
		ans[2*x] = ans[x];

		if(2*x+1 <= n) {
			ans[2*x+1] = ans[x] + ans[x+1];
			currentMaxValue = max(currentMaxValue, max(ans[x], ans[2*x+1]));
		} else {
			currentMaxValue = max(currentMaxValue, ans[x]);
		}
	}

	return currentMaxValue;
}

int main() {
	//cout << 7/2 << endl;
	std::cout << getMaximumGenerated(6) << std::endl;
	return 0;
}
