#include <iostream>
#include <vector>
#include <set>

using namespace std;

class RandomizedSet {
private:
    set<int> values;
    int size = 0;

public:
    RandomizedSet() {

    }

    bool insert(int val) {
        if(values.find(val) != values.end()) return false;
        size++;
        values.insert(val);
        return true;
    }

    bool remove(int val) {
        if(values.find(val) == values.end()) return false;
        size--;
        values.erase(val);
        return true;
    }

    int getRandom() {
        auto setIt = values.begin();
        advance(setIt, rand() % size);
        return *setIt;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
