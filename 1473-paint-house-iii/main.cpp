#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> houses;
    vector<vector<int>> cost;
    int totalHouses;
    int totalColors;
    int target;

    int memo[101][101][101] = {0};

    int dp(int currentHouse, int currentNumberOfNeighborHoods, int colorPreviousHouse) {
        //Base cases
        if(currentHouse == totalHouses) {
            return (currentNumberOfNeighborHoods == target) ? 0 : -1;
        }
        if(currentNumberOfNeighborHoods > target) return -1;
        if(memo[currentHouse][currentNumberOfNeighborHoods][colorPreviousHouse] != 0) return memo[currentHouse][currentNumberOfNeighborHoods][colorPreviousHouse];

        //House is already painted so we have no choice. Just a small check if number of neighborhoods needs to be increased
        if(houses[currentHouse] != 0) {
            if(houses[currentHouse] == colorPreviousHouse) {
                memo[currentHouse][currentNumberOfNeighborHoods][colorPreviousHouse] = dp(currentHouse+1, currentNumberOfNeighborHoods, colorPreviousHouse);
            } else {
                memo[currentHouse][currentNumberOfNeighborHoods][colorPreviousHouse] = dp(currentHouse+1, currentNumberOfNeighborHoods+1, houses[currentHouse]);
            }

            return memo[currentHouse][currentNumberOfNeighborHoods][colorPreviousHouse];
        }

        //Try every color
        int minVal = INT_MAX;
        for(int x = 0; x < totalColors; x++) {
            int res;
            if(x+1 == colorPreviousHouse) {
                res = dp(currentHouse+1, currentNumberOfNeighborHoods, x+1);
            } else {
                res = dp(currentHouse+1, currentNumberOfNeighborHoods+1, x+1);
            }

            if(res != -1) minVal = min(minVal, cost[currentHouse][x] + res);
        }

        //Remember minimum value
        memo[currentHouse][currentNumberOfNeighborHoods][colorPreviousHouse] = (minVal != INT_MAX) ? minVal : -1;
        return memo[currentHouse][currentNumberOfNeighborHoods][colorPreviousHouse];
    }


    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target) {
        this->houses = houses;
        this->cost = cost;
        this->totalHouses = m;
        this->totalColors = n;
        this->target = target;

        int minVal = INT_MAX;

        //Check if first house is painted. If so, we only have 1 option. Otherwise, paint the first house in every possible color.
        if(houses[0] == 0) {
            for(int x = 0; x < totalColors; x++) {
                int res = dp(1, 1, x+1);

                //Add cost of current color later because if it is -1, it needs to be ignored.
                if(res != -1) minVal = min(minVal, cost[0][x] + res);
            }
        } else {
            minVal = dp(1, 1, houses[0]);
        }

        //Check if minVal hasn't been updated. If not, it is not possible therefore return -1. Otherwise, return minVal
        return (minVal != INT_MAX) ? minVal : -1;
    }
};


int main() {
    Solution sol;

    vector<int> houses = {0,0,0,0,0};
    vector<vector<int>> cost = {{1,10},{10,1},{10,1},{1,10},{5,1}};

    std::cout << sol.minCost(houses, cost, houses.size(), cost[0].size(), 3) << std::endl;
    return 0;
}
