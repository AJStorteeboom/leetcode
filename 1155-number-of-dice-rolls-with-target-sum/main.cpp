#include <iostream>

class Solution {
public:
    long memo[32][1002] = {0};
    int totalDices;
    int maxDiceValue;
    int target;
    int MOD = 1e9 + 7;

    long dp(int currentDice, int currentValue) {
        if(currentDice == totalDices) {
            return (currentValue == target) ? 1 : 0;
        }

        if(currentDice > totalDices || currentValue > target) return 0;
        if(memo[currentDice][currentValue] != -1) return memo[currentDice][currentValue];

        long sum = 0;
        for(int x = 1; x <= maxDiceValue; x++) {
            sum += (dp(currentDice+1, currentValue+x) % MOD);
        }

        memo[currentDice][currentValue] = (sum % MOD);
        return memo[currentDice][currentValue];
    }

    int numRollsToTarget(int n, int k, int target) {
        this->totalDices = n;
        this->maxDiceValue = k;
        this->target = target;

        for(int x = 0; x < 31; x++) {
            for(int y = 0; y < 1001; y++) {
                memo[x][y] = -1;
            }
        }

        return (dp(0, 0) % MOD);
    }
};


int main() {
    Solution sol;

    std::cout << sol.numRollsToTarget(30,30,500) << std::endl;
    return 0;
}
