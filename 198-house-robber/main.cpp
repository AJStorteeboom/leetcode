#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int rob(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums.at(0);

        //Calculate max profit for first two nums
        int profitTwoHousesAgo = nums[0];
        int profitLastHouse = max(nums[0], nums[1]);

        //For every num; Start at 2 because we manually calculated the max profit of the first two values;
        for (int x = 2; x < nums.size(); x++) {
            int newProfit = max(nums[x] + profitTwoHousesAgo, profitLastHouse);
            profitTwoHousesAgo = profitLastHouse;
            profitLastHouse = newProfit;
        }

        //Return the max of the last two entries
        return max(profitLastHouse, profitTwoHousesAgo);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
