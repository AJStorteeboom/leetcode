#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct vectorComparator {
    bool operator()(const vector<int> &a, const vector<int> &b) const {
        return (a[0] == b[0]) ? a[1] > b[1] : a[0] < b[0];
    }
};


class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), vectorComparator());

        priority_queue<int, vector<int>, greater<>> heap;

        int concurrentMeetings = 0;

        for(int x = 0; x < intervals.size(); x++) {
            if(heap.empty()) {
                heap.push(intervals[x][1]);
            } else {
                if(intervals[x][0] >= heap.top()) {
                    heap.pop();
                }

                heap.push(intervals[x][1]);
            }

            concurrentMeetings = max(concurrentMeetings, (int) heap.size());
        }

        return concurrentMeetings;
    }
};


int main() {
    vector<vector<int>> intervals = {
            {9,10},{4,9},{4,17}
    };

    Solution sol;

    std::cout << sol.minMeetingRooms(intervals) << std::endl;
    return 0;
}
