#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<vector<int>> jobs;
    int totalJobs;
    vector<int> memo;
    unordered_map<int, vector<int>> jobMap;

    int dp(int index) {
        if (index >= totalJobs) return 0;
        if(memo[index] != -1) return memo[index];

        //Don't take this job
        int maxValue = dp(index + 1);

        //Take this job
        int endTime = jobs[index][1];
        int jobProfit = jobs[index][2];

        int x = 1;
        while (index + x < totalJobs && jobs[index + x][0] < endTime) x++;

        maxValue = max(maxValue, jobProfit + dp(index + x));

        memo[index] = maxValue;

        return memo[index];
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        for(int x = 0; x < startTime.size(); x++) {
            jobs.push_back({startTime[x], endTime[x], profit[x]});
        }

        sort(jobs.begin(), jobs.end());


        this->totalJobs = startTime.size();
        this->memo = vector(totalJobs, -1);

        return dp(0);
    }
};

int main() {
    Solution sol;

    vector<int> start = {6,15,7,11,1,3,16,2};
    vector<int> endTime = {19,18,19,16,10,8,19,8};
    vector<int> profit = {2,9,1,19,5,7,3,19};

    std::cout << sol.jobScheduling(start, endTime, profit) << std::endl;
    return 0;
}
