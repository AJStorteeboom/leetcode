#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<>> minHeap;

        for(int stick : sticks) {
            minHeap.push(stick);
        }

        int currentCost = 0;

        while (minHeap.size() > 1) {
            int sum = minHeap.top();
            minHeap.pop();
            sum += minHeap.top();
            minHeap.pop();

            minHeap.push(sum);
            currentCost += sum;
        }

        return currentCost;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
