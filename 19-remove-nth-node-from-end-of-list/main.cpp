#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head->next == nullptr) return nullptr;
        unordered_map<int, ListNode*> nodeMap;

        int nodeCounter = 0;
        ListNode* startNode = head;

        while(head != nullptr) {
            nodeMap[nodeCounter] = head;
            nodeCounter++;
            head = head->next;
        }

        if(nodeCounter-n-1 < 0) {
            startNode = nodeMap[0]->next;
        }  else if(nodeMap[nodeCounter-n-1]->next != nullptr) {
            nodeMap[nodeCounter-n-1]->next = nodeMap[nodeCounter-n-1]->next->next;
        }

        return startNode;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
