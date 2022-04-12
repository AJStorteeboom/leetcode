#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int memo[101][25] = {0};
    vector<vector<int>> costs;
    int totalColors;

    int dp(int currentHouse, int prev) {
        if (currentHouse == costs.size()) return 0;
        if (memo[currentHouse][prev] != 0) return memo[currentHouse][prev];

        int minValue = INT_MAX;

        for (int x = 0; x < totalColors; x++) {
            if (prev == x) continue;
            minValue = min(minValue, costs[currentHouse][x] + dp(currentHouse + 1, x));
        }

        memo[currentHouse][prev] = minValue;
        return minValue;
    }

    int minCostII(vector<vector<int>>& costs) {
        int minValue = INT_MAX;
        this->costs = costs;
        this->totalColors = costs[0].size();

        for (int x = 0; x < totalColors; x++) {
            minValue = min(minValue, costs[0][x] + dp(1, x));
        }

        return minValue;
    }
};



int main() {
    Solution sol;

    vector<vector<int>> costs = {
            {{1,5,3},{2,9,4}}
    };
    //3[0]+6[2]+7[0]+9[0]

    std::cout << sol.minCostII(costs) << std::endl;
    return 0;
}
