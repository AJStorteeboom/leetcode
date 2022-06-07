#include <iostream>
#include <vector>

using namespace std;

struct vectorComparator {
    bool operator()(const vector<int> &a, const vector<int> &b) const {
        return (a[0] == b[0]) ? a[1] > b[1] : a[0] < b[0];
    }
};

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), vectorComparator());

        for(int x = 1; x < intervals.size(); x++) {
            if(intervals[x][0] < intervals[x-1][1]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    vector<vector<int>> intervals = {
            {11,20},{4,19},{13,17},{6,13}
    };

    Solution sol;

    std::cout << sol.canAttendMeetings(intervals) << std::endl;
    return 0;
}
