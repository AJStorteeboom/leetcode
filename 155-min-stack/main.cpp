#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<pair<int,int>> minStack;

public:
    MinStack() {

    }

    void push(int val) {
        int currentMinValue = (minStack.empty()) ? val : min(getMin(), val);
        minStack.push(pair<int,int>(val, currentMinValue));
    }

    void pop() {
        minStack.pop();
    }

    int top() {
        return minStack.top().first;
    }

    int getMin() {
        return minStack.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
