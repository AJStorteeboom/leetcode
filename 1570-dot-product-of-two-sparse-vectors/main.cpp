#include <iostream>
#include <map>
#include <vector>

using namespace std;

class SparseVector {
public:
    map<int,int> nonZeroValues;

    SparseVector(vector<int> &nums) {
        for(int x = 0; x < nums.size(); x++) {
            if(nums[x] == 0) continue;

            nonZeroValues.insert(pair<int,int>(x, nums[x]));
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int sum = 0;

        for (auto const& [key, val] : nonZeroValues) {
            if(vec.nonZeroValues.find(key) != vec.nonZeroValues.end()) {
                sum += val*vec.nonZeroValues[key];
            }
        }

        return sum;
    }
};




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
