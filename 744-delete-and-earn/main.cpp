#include <iostream>
#include <vector>

using namespace std;


int deleteAndEarn(vector<int>& nums) {
	int count[10001] = {0};
	for(int x : nums) count[x]++;

	int avoid = 0;
	int use = 0;
	int prev = -1;

	for(int x = 0; x <= 10000; x++) if (count[x] > 0) {
		int m = max(avoid, use);
		cout << "x " << x << " - avoid " << avoid << " - use " << use << " - prev " << prev << endl;
		use = (x-1 != prev) ? x * count[x] + m : x * count[x] + avoid;
		avoid = m;
		prev = x;
	}

	return max(avoid, use);
}

int main() {
	vector<int> x = {3,4,2};

	std::cout << deleteAndEarn(x) << std::endl;

	return 0;
}
