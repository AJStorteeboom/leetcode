#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> valueFrequency;

        for(int value : nums) valueFrequency[value]++;

        priority_queue<pair<int,int>> maxHeap;

        for (auto const& x : valueFrequency) maxHeap.push(pair<int,int>(x.second, x.first));

        vector<int> result;

        for(int x = 0; x < k; x++) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};

int main() {




    std::cout << "Hello, World!" << std::endl;
    return 0;
}
