#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap(nums.begin(), nums.end());

        for(int x = 0; x < k; x++) maxHeap.pop();

        return maxHeap.top();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
