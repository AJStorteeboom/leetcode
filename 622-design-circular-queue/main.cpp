#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue {
private:
    vector<int> queue;
    int queueSize;
    int freeSlots;
    int currentHead = 0;
    int currentTail = 0;


public:
    MyCircularQueue(int k) {
        queue = vector<int>(k, -1);
        queueSize = k;
        freeSlots = k;
    }

    bool enQueue(int value) {
        if(isFull()) return false;
        queue[currentHead] = value;
        currentHead = (currentHead+1 == queueSize) ? 0 : currentHead+1;

        freeSlots--;
        return true;
    }

    bool deQueue() {
        if(isEmpty()) return false;

        queue[currentTail] = -1;
        currentTail = (currentTail+1 == queueSize) ? 0 : currentTail+1;
        freeSlots++;
        return true;
    }

    int Front() {
        return queue[currentTail];
    }

    int Rear() {
        return (currentHead == 0) ? queue[queueSize-1] : queue[currentHead-1];
    }

    bool isEmpty() {
        return freeSlots == queueSize;
    }

    bool isFull() {
        return freeSlots == 0;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main() {
    MyCircularQueue myCircularQueue(3);


    cout << "dequeue: " << myCircularQueue.deQueue() << endl;
    cout << "enQueue: " <<  myCircularQueue.enQueue(1) << endl;
    cout << "enQueue: " <<  myCircularQueue.enQueue(2) << endl;
    cout << "deQueue: " <<  myCircularQueue.deQueue() << endl;
    cout << "enQueue: " <<  myCircularQueue.enQueue(3) << endl;
    cout << "Front: " <<  myCircularQueue.Front() << endl;
    cout << "Rear: " <<  myCircularQueue.Rear() << endl;
    cout << "isEmpty: " <<  myCircularQueue.isEmpty() << endl;
    cout << "isFull: " <<  myCircularQueue.isFull() << endl;
    cout << "deQueue: " <<  myCircularQueue.deQueue() << endl;
    cout << "enQueue: " <<  myCircularQueue.enQueue(4) << endl;
    cout << "enQueue: " <<  myCircularQueue.enQueue(5) << endl;
    cout << "enQueue: " <<  myCircularQueue.enQueue(6) << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
