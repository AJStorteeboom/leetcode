#include <iostream>
#include <vector>
#include <list>


using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if(changed.size() % 2 != 0) return {}; //if not even it means it can not be divided by 2 which means it is not doubled.

        sort(changed.begin(), changed.end());
        vector<int> result;
        list<int> list;

        for(int x = 0; x < changed.size(); x++) {
            if(list.empty()) {
                list.push_front(changed[x]);
                result.push_back(changed[x]);
            } else {
                if(list.front()*2 == changed[x]) {
                    list.pop_front(); //Valid match - continue
                } else if(list.front()*2 < changed[x]) {
                    return {}; //if current number is greater than the smallest double, it means the double is not available so invalid match
                } else {
                    result.push_back(changed[x]);
                    list.push_back(changed[x]); //if smaller just add it to the list
                }
            }
        }

        if(!list.empty()) return {};

        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
