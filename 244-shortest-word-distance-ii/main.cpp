#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class WordDistance {
private:
    unordered_map<string, vector<int>> indexDict;
public:
    WordDistance(vector<string>& wordsDict) {
        for(int x = 0; x < wordsDict.size(); x++) {
            if(indexDict.find(wordsDict[x]) != indexDict.end()) {
                indexDict[wordsDict[x]].push_back(x);
            } else {
                indexDict[wordsDict[x]] = vector<int> {x};
            }
        }
    }

    int shortest(string word1, string word2) {
        int shortestPath = INT_MAX;

        for(int x = 0; x < indexDict[word1].size(); x++) {
            for(int y = 0; y < indexDict[word2].size(); y++) {
                shortestPath = min(shortestPath, abs(indexDict[word1][x]-indexDict[word2][y]));
            }
        }

        return shortestPath;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */



int main() {
    vector<string> words = {
            "practice", "makes", "perfect", "coding", "makes"
    };

    WordDistance wordDistance(words);

    cout << wordDistance.shortest("practice", "coding") << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
