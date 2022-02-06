#include <iostream>

#include <vector>
using namespace std;

void recursive(vector<string> &allPossibilities, string& s, int currentChar) {
	if(find(allPossibilities.begin(), allPossibilities.end(), s) == allPossibilities.end()) allPossibilities.push_back(s);
	if(currentChar >= s.length()) return;

	recursive(allPossibilities, s, currentChar+1);

	if(islower(s[currentChar])) {
		s[currentChar] = ::toupper(s[currentChar]);
		recursive(allPossibilities, s, currentChar+1);
		s[currentChar] = ::tolower(s[currentChar]);
	} else {
		s[currentChar] = ::tolower(s[currentChar]);
		recursive(allPossibilities, s, currentChar+1);
		s[currentChar] = ::toupper(s[currentChar]);
	}
}


vector<string> letterCasePermutation(string s) {
	vector<string> allPossibilities = {s};
	recursive(allPossibilities, s, 0);
	return allPossibilities;
}

int main() {
	for(string x : letterCasePermutation("FKqeaCFIESzo")) {
		cout << x << endl;
	}

	return 0;
}
