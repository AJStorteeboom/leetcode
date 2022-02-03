#include <iostream>

#include <vector>
#include <unordered_set>

using namespace std;


void recursive(unordered_set<string>& allPossibilities, string charsAvailable, string currentString) {
	allPossibilities.insert(currentString);

	//Base case
	if(charsAvailable.empty()) return;

	for(int x = 0; x < charsAvailable.size(); x++) {
		//Save current char
		char currentChar = charsAvailable[x];

		//copy strings
		string newCharsAvailable = charsAvailable;
		string newCurrentString = currentString;

		//remove char from chars available
		newCharsAvailable.erase(newCharsAvailable.begin()+x);

		//Recurse with char not added
		recursive(allPossibilities, newCharsAvailable, newCurrentString);

		//Recurse with char added
		newCurrentString.append(1, currentChar);
		recursive(allPossibilities, newCharsAvailable, newCurrentString);
	}
}

int numTilePossibilities(string tiles) {
	unordered_set<string> memory;

	for(int x = 0; x < tiles.size(); x++) {
		//Create new string for every start
		string currentString = "";

		//Append current char
		currentString.append(1, tiles[x]);

		//Copy tiles and removed used char
		string charsAvailable = tiles;
		charsAvailable.erase(charsAvailable.begin()+x);

		//Recurse with chars available
		recursive(memory, charsAvailable, currentString);
	}

	return memory.size();
}



int main() {
	cout << numTilePossibilities("") << endl;
	return 0;
}
