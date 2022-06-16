#include <iostream>

using namespace std;


class Solution {
    int memo[501][501] = {0};
    string word1;
    string word2;

public:
    int longestCommonSubSequence(int i, int j) {
        if(i == word1.size() || j == word2.size()) return 0;
        if(memo[i][j] != 0) return memo[i][j];

        memo[i][j] = (word1[i] == word2[j]) ? 1+longestCommonSubSequence(i+1, j+1) : max(longestCommonSubSequence(i+1, j), longestCommonSubSequence(i, j+1));

        return memo[i][j];
    }

    int minDistance(string word1, string word2) {
        this->word1 = word1;
        this->word2 = word2;

        int lcs = longestCommonSubSequence(0,0);

        return word1.size()+word2.size() - lcs*2;
    }
};


int main() {
    Solution sol;

    cout << sol.minDistance("aac", "bacb") << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
