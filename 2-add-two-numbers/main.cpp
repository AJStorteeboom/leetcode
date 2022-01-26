#include <iostream>
#include <charconv>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	ListNode() : val(0), next(nullptr) {}

	ListNode(int x) : val(x), next(nullptr) {}

	ListNode(int x, ListNode *next) : val(x), next(next) {}
};




ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* dummyHead = new ListNode(0);
	ListNode* l3 = dummyHead;

	int carry = 0;

	while (l1 != nullptr || l2 != nullptr) {
		int l1Val = (l1 != nullptr) ? l1->val : 0;
		int l2Val = (l2 != nullptr) ? l2->val : 0;

		int sum = l1Val+l2Val+carry;
		carry = sum/10;
		int lastDigit = sum % 10;

		ListNode* newNode = new ListNode(lastDigit);
		l3->next = newNode;

		if (l1 != nullptr) l1 = l1->next;
		if (l2 != nullptr) l2 = l2->next;

		l3 = l3->next;
	}

	if(carry == 1) {
		ListNode* newNode = new ListNode(1);
		l3->next = newNode;
		l3 = l3->next;
	}

	return dummyHead->next;
}


int main() {

	ListNode listNode1;
	ListNode listNode2;
	ListNode listNode3;
	listNode1.val = 5;
	listNode2.val = 0;
	listNode3.val = 3;

	listNode1.next = &listNode2;
	listNode2.next = &listNode3;

	ListNode* result = addTwoNumbers(&listNode1, &listNode1);

	while (result != nullptr) {
		cout << result->val << " - ";
		result = result->next;
	}

	return 0;
}
