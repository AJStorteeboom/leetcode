#include <iostream>

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> houses;

    int rob(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() < 4) return *std::max_element(nums.begin(), nums.end());
        this->houses = nums;

        return max(robSimple(0, nums.size() - 1), robSimple(1, nums.size()));
    }

    int robSimple(int start, int stop) {
        //Calculate max profit for first two nums
        int profitTwoHousesAgo = houses[start];
        int profitLastHouse = max(houses[start], houses[start + 1]);

        //For every num; Start at 2 because we manually calculated the max profit of the first two values;
        for (int x = start + 2; x < stop; x++) {
            int newProfit = max(houses[x] + profitTwoHousesAgo, profitLastHouse);
            profitTwoHousesAgo = profitLastHouse;
            profitLastHouse = newProfit;
        }

        //Return the max of the last two entries
        return max(profitLastHouse, profitTwoHousesAgo);
    }
};


int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 1};

    std::cout << sol.rob(nums) << std::endl;
    return 0;
}
