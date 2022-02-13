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

vector<int> rightSideView(TreeNode* root) {
	if(root == nullptr) return vector<int>();
	vector<int> ans;
	ans.push_back(root->val);

	queue<pair<TreeNode*, int>> nodeQueue;
	nodeQueue.push(pair<TreeNode*, int>(root, 0));

	while (!nodeQueue.empty()) {
		pair<TreeNode*, int> nodeElement = nodeQueue.front();
		nodeQueue.pop();

		if(nodeQueue.empty() || nodeQueue.front().second > nodeElement.second) {
			ans.push_back(nodeElement.first->val);
		}

		if(nodeElement.first->left != nullptr) nodeQueue.push(pair<TreeNode*, int>(nodeElement.first->left, nodeElement.second+1));
		if(nodeElement.first->right != nullptr) nodeQueue.push(pair<TreeNode*, int>(nodeElement.first->right, nodeElement.second+1));
	}

	return ans;
}

int main() {



	std::cout << "Hello, World!" << std::endl;
	return 0;
}
