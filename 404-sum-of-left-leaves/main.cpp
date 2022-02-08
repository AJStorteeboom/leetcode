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


int sumOfLeftLeaves(TreeNode* root) {
	queue<pair<TreeNode*, bool>> nodeQueue;
	nodeQueue.push(pair<TreeNode*, bool>(root, false));

	int currentSum = 0;
	while (!nodeQueue.empty()) {
		pair<TreeNode*, bool> queueElement = nodeQueue.front();
		nodeQueue.pop();

		if(queueElement.second && queueElement.first->left == nullptr && queueElement.first->right == nullptr) currentSum += queueElement.first->val;
		if(queueElement.first->right != nullptr) nodeQueue.push(pair<TreeNode*, bool>(queueElement.first->right, false));
		if(queueElement.first->left != nullptr) nodeQueue.push(pair<TreeNode*, bool>(queueElement.first->left, true));
	}

	return currentSum;
}


int main() {
	TreeNode node1 = TreeNode(3);
	TreeNode node2 = TreeNode(9);
	TreeNode node3 = TreeNode(20);
	TreeNode node4 = TreeNode(15);
	TreeNode node5 = TreeNode(7);

	node1.left = &node2;
	node1.right = &node3;
	node3.left = &node4;
	node3.right = &node5;

	std::cout << sumOfLeftLeaves(&node1) << std::endl;
	return 0;
}
