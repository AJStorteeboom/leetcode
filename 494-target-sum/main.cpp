#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;


class Solution_stack_dfs {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int countTargetReached = 0;
        stack<pair<int,int>> stack;

        int counter = 0;

        stack.push(pair<int,int>(0, 0));

        while (!empty(stack)) {
            counter++;
            pair<int,int> node = stack.top();
            stack.pop();

            if(node.first == nums.size() && node.second == target) countTargetReached++;
            if(node.first < nums.size()) {
                stack.push(pair<int, int>(node.first + 1, node.second + nums[node.first]));
                stack.push(pair<int, int>(node.first + 1, node.second - nums[node.first]));
            }
        }

        cout << "counter " << counter << endl;
        return countTargetReached;
    }
};

class Solution_dynamic_programming {
public:
    unordered_map<int, unordered_map<int,int>> memo;
    int target;
    vector<int> nums;
    int counter = 0;

    int dp(int index, int currentSum) {
        if(index == nums.size()) {
            return (currentSum == target) ? 1 : 0;
        }
        if(memo.find(index) != memo.end() && memo[index].find(currentSum) != memo[index].end()) return memo[index][currentSum];
        counter++;
        cout << counter << endl;

        int sum = 0;
        sum += dp(index+1, currentSum-nums[index]);
        sum += dp(index+1, currentSum+nums[index]);
        memo[index].insert(pair<int,int>(currentSum, sum));

        return sum;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        this->nums = nums;
        this->target = target;

        return dp(0, 0);
    }
};


int main() {
    vector<int> nums = {1,1,1,1,1};

    Solution_stack_dfs sol1;
    Solution_dynamic_programming sol2;

    std::cout << sol1.findTargetSumWays(nums, 3) << std::endl;
    std::cout << sol2.findTargetSumWays(nums, 3) << std::endl;
    return 0;
}
