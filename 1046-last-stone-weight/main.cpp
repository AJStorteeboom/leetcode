#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap(stones.begin(), stones.end());

        while (maxHeap.size() > 1) {
            int biggestStone = maxHeap.top();
            maxHeap.pop();
            int smallerStone = maxHeap.top();
            maxHeap.pop();

            int newStoneWeight = biggestStone - smallerStone;
            if(newStoneWeight > 0) maxHeap.push(newStoneWeight);
        }

        return (maxHeap.size() == 1) ? maxHeap.top() : 0;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
