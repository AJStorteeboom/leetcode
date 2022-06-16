#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> prices;
    int memo[30001][2] = {0};

    int dp(int day, int holding) {
        if(day == prices.size()) return 0;
        if(memo[day][holding] != -1) return memo[day][holding];

        if(holding == 1) {
            memo[day][holding] = max(dp(day+1, 0)+prices[day], dp(day+1, holding));
        } else {
            memo[day][holding] = max(dp(day+1, 1)-prices[day], dp(day+1, holding));
        }

        return memo[day][holding];
    }

    int maxProfit(vector<int>& prices) {
        this->prices = prices;

        for(auto x = 0; x < 30001; x++) {
            memo[x][0] = -1;
            memo[x][1] = -1;
        }

        return dp(0, 0);
    }



    int maxProfit_2_lc_solution(vector<int>& prices) {
        int maxprofit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1];
        }

        return maxprofit;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
