#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;



class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> heap;

        for(int z = 0; z < points.size(); z++) {
            int x = -points[z][0];
            int y = -points[z][1];
            int sum = x*x+y*y;
            double distance = sqrt(sum);
            heap.push(pair<double,int>(distance, z));
        }

        vector<vector<int>> result;

        for(int x = 0; x < k; x++) {
            cout << heap.top().first << " - " << heap.top().second << endl;
            result.push_back(points[heap.top().second]);
            heap.pop();
        }

        return result;
    }
};

int main() {
    vector<vector<int>> points = {
            {-5,4},
            {-6,-5},
            {4,6}
    };

    Solution sol;

    sol.kClosest(points, 3);
    return 0;
}
