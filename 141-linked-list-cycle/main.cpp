#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        unordered_set<ListNode*> visited;

        while (head->next != nullptr) {
            if(visited.find(head) != visited.end()) return true;
            visited.insert(head);
            head = head->next;
        }

        return false;
    }

    //Cheated a bit
    bool hasCycle_optimized(ListNode *head) {
        if(head == nullptr) return false;
        int VISITED_VALUE = INT_MAX;

        while (head->next != nullptr) {
            if(head->val == VISITED_VALUE) return true;
            head->val = VISITED_VALUE;
            head = head->next;
        }

        return false;
    }

    //When two runners run one the same track, check if the faster runner passes the slower runner. If so, it has a cycle.
    bool hasCycle_floyd_cycle_finding(ListNode *head) {
        if(head == nullptr) return false;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (slow != fast) {
            if(fast == nullptr || fast->next == nullptr) return false;
            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
