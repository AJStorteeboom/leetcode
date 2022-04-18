#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nums1;
    vector<int> nums2;

    int memo[1001][1001] = {0};
    int maxLength = 0;

    int dp(int i, int j) {
        if(i == nums1.size() || j == nums2.size()) return 0;
        if(memo[i][j] != -1) return memo[i][j];

        memo[i][j] = (nums1[i] == nums2[j]) ? 1+dp(i+1, j+1) : 0;
        maxLength = max(maxLength, memo[i][j]);

        return memo[i][j];
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;

        for(int x = 0; x < 1000; x++) {
            for(int y = 0; y < 1000; y++) memo[x][y] = -1;
        }

        for(int x = 0; x < nums1.size(); x++) {
            for(int y = 0; y < nums2.size(); y++) {
                if(memo[x][y] == -1) dp(x,y);
            }
        }

        return maxLength;
    }
};



int main() {
    Solution sol;

    /*
     *  [1,0,0,0,1,0,0,1,0,0]
     *
        [0,1,1,1,0,1,1,1,0,0]
     */

    vector<int> nums1 = {1,0,0,0,1,0,0,1,0,0};
    vector<int> nums2 = {0,1,1,1,0,1,1,1,0,0};
    //                   0 1 2 3 4 5 6 7 8 9
    std::cout << sol.findLength(nums1, nums2) << std::endl;
    return 0;
}
