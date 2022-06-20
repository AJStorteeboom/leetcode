#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        string number = to_string(x);
        string result;

        bool minus = number[0] == '-';
        int endpoint = (minus) ? 1 : 0;
        int nonNullOccurred = false;

        for(int x = number.size()-1; x > endpoint; x--) {
            if(!nonNullOccurred) {
                if(number[x] == 0) continue;
                nonNullOccurred = true;
            }
            result.push_back(number[x]);
        }

        if(endpoint) result = "-" + result;

        try {
            return stoi(result);
        } catch (exception &err) {
            return 0;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
