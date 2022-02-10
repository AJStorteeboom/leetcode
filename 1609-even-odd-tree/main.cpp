#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode() : val(0), left(nullptr), right(nullptr) {}

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


bool isEvenOddTree(TreeNode *root) {
	if(root->val % 2 == 0) return false;

	queue<pair<TreeNode*, int>> nodeQueue;
	nodeQueue.push(pair<TreeNode*, int>(root, 0));

	int prevVal = -1;
	int prevLevel = -1;

	while (!nodeQueue.empty()) {
		pair<TreeNode*, int> nodeElement = nodeQueue.front();
		nodeQueue.pop();


		if(nodeElement.second % 2 == 0) {
			if(nodeElement.first->val % 2 == 0  || (prevLevel == nodeElement.second && prevVal >= nodeElement.first->val)) {
				return false;
			}
		} else {
			if(nodeElement.first->val % 2 > 0 || (prevLevel == nodeElement.second && prevVal <= nodeElement.first->val)) {
				return false;
			}
		}

		prevLevel = nodeElement.second;
		prevVal = nodeElement.first->val;

		if(nodeElement.first->left != nullptr) nodeQueue.push(pair<TreeNode*, int>(nodeElement.first->left, nodeElement.second+1));
		if(nodeElement.first->right != nullptr) nodeQueue.push(pair<TreeNode*, int>(nodeElement.first->right, nodeElement.second+1));
	}

	return true;
}

/*
 * 1 - 0
 * 10 - 1
 * 4 - 1
 * 3 - 2
 * 7 - 2
 * 9 - 2
 * 12 - 3
 * 8 - 3
 * 6 - 3
 * 2 - 3
 * 0
 */

int main() {
	TreeNode node1 = TreeNode(1);
	TreeNode node2 = TreeNode(10);
	TreeNode node3 = TreeNode(4);
	TreeNode node4 = TreeNode(3);
	TreeNode node5 = TreeNode(7);
	TreeNode node6 = TreeNode(9);
	TreeNode node7 = TreeNode(12);
	TreeNode node8 = TreeNode(8);
	TreeNode node9 = TreeNode(6);
	TreeNode node10 = TreeNode(2);

	node1.left = &node2;
	node1.right = &node3;
	node2.left = &node4;
	node3.left = &node5;
	node3.right = &node6;
	node4.left = &node7;
	node4.right = &node8;
	node5.left = &node9;
	node6.right = &node10;

	std::cout << isEvenOddTree(&node1) << std::endl;

	return 0;
}
