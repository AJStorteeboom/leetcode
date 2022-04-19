#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> days;
    vector<int> costs;

    int memo[365] = {0};

    int dp(int currentDay) {
        if(currentDay >= days.size()) return 0;
        if(memo[currentDay] != 0) return memo[currentDay];

        int minVal = INT_MAX;
        minVal = min(minVal, costs[0]+dp(currentDay+1));

        int sevenDayTicketExpireDay = currentDay;
        while (sevenDayTicketExpireDay < days.size() && days[sevenDayTicketExpireDay] < days[currentDay]+7) sevenDayTicketExpireDay++;
        minVal = min(minVal, costs[1]+dp(sevenDayTicketExpireDay));

        int thirtyDayTicketExpireDay = currentDay;
        while (thirtyDayTicketExpireDay < days.size() && days[thirtyDayTicketExpireDay] < days[currentDay]+30) thirtyDayTicketExpireDay++;
        minVal = min(minVal, costs[2]+dp(thirtyDayTicketExpireDay));

        memo[currentDay] = minVal;
        return minVal;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        this->days = days;
        this->costs = costs;

        return dp(0);
    }
};

int main() {
    Solution sol;

    vector<int> days = {
            1,2,3,4,5,6,7,8,9,10,30,31
    };

    vector<int> costs = {
            2,9,31
    };

    std::cout << sol.mincostTickets(days, costs) << std::endl;
    return 0;
}
