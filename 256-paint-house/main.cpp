#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int memo[101][101];

    vector<vector<int>> costs;

    int dp(int currentHouse, int prev) {
        if (currentHouse == costs.size()) return 0;
        if (memo[currentHouse][prev] != 0) return memo[currentHouse][prev];

        int minValue = INT_MAX;

        for (int x = 0; x < 3; x++) {
            if (prev == x) continue;
            minValue = min(minValue, costs[currentHouse][x] + dp(currentHouse + 1, x));
        }

        memo[currentHouse][prev] = minValue;
        return minValue;
    }

    int minCost(vector<vector<int>> &costs) {
        int minValue = INT_MAX;
        this->costs = costs;

        for (int x = 0; x < 3; x++) {
            minValue = min(minValue, costs[0][x] + dp(1, x));
        }

        return minValue;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> costs = {
            {{3, 5, 3}, {6, 17, 6}, {7, 13, 18}, {9, 10, 18}}
    };
    //3[0]+6[2]+7[0]+9[0]

    std::cout << sol.minCost(costs) << std::endl;
    return 0;
}
