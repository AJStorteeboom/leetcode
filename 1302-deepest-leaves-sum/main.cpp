#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode() : val(0), left(nullptr), right(nullptr) {}

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int deepestLeavesSum(TreeNode* root) {
	queue<pair<TreeNode*, int>> nodeQueue;
	nodeQueue.push(pair<TreeNode*, int>(root, 0));

	vector<pair<TreeNode*,int>> leafNodes;

	int maxDepth = 0;
	while (!nodeQueue.empty()) {
		pair<TreeNode*,int> queueElement = nodeQueue.front();
		maxDepth = max(maxDepth, queueElement.second);
		nodeQueue.pop();

		if(queueElement.first->left == nullptr && queueElement.first->right == nullptr) leafNodes.push_back(queueElement);
		if(queueElement.first->left != nullptr) nodeQueue.push(pair<TreeNode*, int>(queueElement.first->left, queueElement.second+1));
		if(queueElement.first->right != nullptr) nodeQueue.push(pair<TreeNode*, int>(queueElement.first->right, queueElement.second+1));
	}


	int currentSum = 0;

	for(pair<TreeNode*, int> leafNode : leafNodes) {
		if(leafNode.second == maxDepth) currentSum += leafNode.first->val;
	}

	return currentSum;
}


int main() {

	TreeNode node1 = TreeNode(6);
	TreeNode node2 = TreeNode(7);
	TreeNode node3 = TreeNode(8);
	TreeNode node4 = TreeNode(2);
	TreeNode node5 = TreeNode(7);
	TreeNode node6 = TreeNode(1);
	TreeNode node7 = TreeNode(3);
	TreeNode node8 = TreeNode(9);
	TreeNode node9 = TreeNode(1);
	TreeNode node10 = TreeNode(4);
	TreeNode node11 = TreeNode(5);

//	node1.left = &node2;
//	node1.right = &node3;
//
//	node2.left = &node4;
//	node2.right = &node5;
//
//	node3.left = &node6;
//	node3.right = &node7;
//
//	node4.left = &node8;
//
//	node5.left = &node9;
//	node5.right = &node10;
//
//	node7.right = &node11;

	std::cout << deepestLeavesSum(&node1) << std::endl;
	return 0;
}
