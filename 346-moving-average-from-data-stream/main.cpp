#include <iostream>
#include <queue>

using namespace std;

class MovingAverage {
private:
    queue<int> data;
    int queueMaxSize;
    int currentSize = 0;
    int currentSum = 0;

public:
    MovingAverage(int size) {
        queueMaxSize = size;
    }

    double next(int val) {
        int discardedValue = 0;

        if(currentSize == queueMaxSize) {
            discardedValue = data.front();
            data.pop();
            currentSize--;
        }

        currentSum = currentSum-discardedValue+val;
        data.push(val);
        currentSize++;
        return (float) currentSum/ (float) currentSize;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */


int main() {
    MovingAverage movingAverage(3);


    std::cout << movingAverage.next(1) << std::endl;
    std::cout << movingAverage.next(2) << std::endl;
    std::cout << movingAverage.next(3) << std::endl;
    std::cout << movingAverage.next(4) << std::endl;
    return 0;
}
