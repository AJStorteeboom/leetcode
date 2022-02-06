#include <iostream>

#include <unordered_set>

using namespace std;

bool isValid(int n, int place) {
	return n % place == 0 || place % n == 0;
}

int recursive(unordered_set<int>& currentPermutation, int currentIndex, int n) {
	if(currentPermutation.size() == n) return 1;

	int arrangements = 0;

	for(int x = 1; x <= n; x++) {
		if(currentPermutation.find(x) != currentPermutation.end()) continue;

		if(isValid(x, currentIndex)) {
			currentPermutation.insert(x);
			arrangements += recursive(currentPermutation, currentIndex+1, n);
			currentPermutation.erase(x);
		}
	}

	return arrangements;
}



int countArrangement(int n) {
	unordered_set<int> currentPermutation;

	int arrangements = 0;

	for(int x = 1; x <= n; x++) {
		currentPermutation.insert(x);
		arrangements += recursive(currentPermutation, 2, n);
		currentPermutation.erase(x);
	}

	return arrangements;
}

int main() {
	cout << countArrangement(4) << endl;
	return 0;
}
