#include <iostream>
#include <vector>

using namespace std;




class Solution {
public:
	int memo[10][300];
	int totalJobs;
	int totalDays;
	vector<int> jobs;

	int dp(int day, int job) {
		//When the lastday is reached. Sum the rest of the jobs.
		if(day == totalDays) {
			int sum = 0;
			for (int x = job; x < totalJobs; x++) sum += jobs[x];
			return sum;
		}

		if(memo[day][job] != -1) return memo[day][job];

		memo[day][job] = INT_MAX;
		int jobDiffMax = 0;

		//Try for every possibility of jobs per day.
		for(int x = job; x <= job+(totalJobs-job-(totalDays-day)); x++) {
			jobDiffMax = max(jobDiffMax, jobs[x]);
			memo[day][job] = min(memo[day][job],jobDiffMax+dp(day+1, x+1));
		}

		return memo[day][job];
	}

	int minDifficulty(vector<int>& jobDifficulty, int d) {
		if(jobDifficulty.size() < d) return -1;

		//Fill with -1 because of the testcase with only zero's
		for(int i = 0; i < 10; i++)
			for(int j = 0; j < 300; j++)
				memo[i][j] = -1;


		totalDays = d;
		jobs = jobDifficulty;
		totalJobs = jobDifficulty.size();

		return dp(0, 0);
	}
};


int main() {
	Solution sol;

	vector<int> jobs = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	std::cout << "res: " << sol.minDifficulty(jobs, 10) << std::endl;

	return 0;
}
