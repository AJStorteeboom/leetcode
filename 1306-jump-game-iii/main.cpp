#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> jumpQueue;
        jumpQueue.push(start);
        unordered_set<int> visited;

        while (!jumpQueue.empty()) {
            int index = jumpQueue.front();
            jumpQueue.pop();

            if(arr[index] == 0) return true;

            if(index-arr[index] > 0 && visited.find(index-arr[index]) == visited.end()) {
                jumpQueue.push(index-arr[index]);
                visited.insert(index-arr[index]);
            }
            if(index+arr[index] < arr.size() && visited.find(index+arr[index]) == visited.end()) {
                jumpQueue.push(index+arr[index]);
                visited.insert(index+arr[index]);
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {0,1};

    std::cout << sol.canReach(nums, 1) << std::endl;
    return 0;
}
