#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size(); i++) {
            if(i > 0 && numbers[i] == numbers[i-1]) continue; //Skip if same number as last one

            for(int j = 0; j < numbers.size(); j++) {
                if(j == i) continue;

                if(numbers[i]+numbers[j] == target) {
                    return vector<int> {i+1, j+1};
                }
                if(numbers[i]+numbers[j] > target) {
                    //Only gets bigger so break the first loop
                    break;
                }
            }
        }

        return {0,0};
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
