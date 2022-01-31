#include <iostream>

using namespace std;

#include <unordered_map>

int romanToInt(string s) {
	unordered_map<char, int> symbolToValue = {
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500},
			{'M', 1000},
	};

	int currentSum = 0;

	for (int x = 0; x < s.length(); x++) {
		if(x < s.length()-1 && symbolToValue.at(s[x]) < symbolToValue.at(s[x+1])) {
			currentSum += symbolToValue.at(s[x+1])-symbolToValue.at(s[x]);
			x++;
		} else {
			currentSum += symbolToValue.at(s[x]);
		}
	}

	return currentSum;
}


int main() {
	std::cout << romanToInt("III") << std::endl;
	return 0;
}
