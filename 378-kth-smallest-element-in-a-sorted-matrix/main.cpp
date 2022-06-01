#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> minHeap;

        for(int x = 0; x < matrix.size(); x++) {
            for(int y = 0; y < matrix[0].size(); y++) {
                minHeap.push(matrix[x][y]*-1);
            }
        }

        for(int x = 0; x < k-1; x++) minHeap.pop();

        return minHeap.top()*-1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
