#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string s1;
    string s2;
    string target;

    int memo[101][101][201] = {0};

    bool dp(int i, int j, int currentIndexTarget) {
        if(i == s1.size() && j == s2.size() && currentIndexTarget == target.size()) return true;
        if(currentIndexTarget > target.size() || memo[i][j][currentIndexTarget] != 0) return false;

        if(i < s1.size() && s1[i] == target[currentIndexTarget] && dp(i+1, j, currentIndexTarget+1)) return true;
        if(j < s2.size() && s2[j] == target[currentIndexTarget] && dp(i, j+1, currentIndexTarget+1)) return true;

        memo[i][j][currentIndexTarget] = 1;
        return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.empty() && s2.empty() && s3.empty()) return true;
        if(s3.empty() && (!s1.empty() || !s2.empty())) return false;

        this->s1 = s1;
        this->s2 = s2;
        this->target = s3;

        return dp(0,0,0);
    }
};

int main() {
    Solution sol;

    std::cout << sol.isInterleave("aaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << std::endl;
    return 0;
}
