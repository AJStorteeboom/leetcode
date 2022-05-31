#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct pairComparator {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
        return (a.first == b.first) ? a.second > b.second : a.first < b.first;
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, pairComparator> maxHeap;

        for (int x = 0; x < mat.size(); x++) {
            int soldiers = 0;

            for (int y = 0; y < mat[0].size(); y++) {
                if (mat[x][y] == 1) {
                    soldiers++;
                } else {
                    break;
                }
            }

            maxHeap.push(pair<int, int>(soldiers * -1, x));
        }

        vector<int> result;

        for (int x = 0; x < k; x++) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix = {{1, 1, 0, 0, 0},
                                  {1, 1, 1, 1, 0},
                                  {1, 0, 0, 0, 0},
                                  {1, 1, 0, 0, 0},
                                  {1, 1, 1, 1, 1}};

    sol.kWeakestRows(matrix, 3);
    return 0;
}
