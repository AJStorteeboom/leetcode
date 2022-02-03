#include <iostream>

#include <vector>

using namespace std;


void recursive(vector<vector<int>>& allSolutions, vector<vector<int>>& graph, vector<int> currentSolution, int currentNode) {
	currentSolution.push_back(currentNode);

	if(graph.at(currentNode).empty()) {
		if(currentNode == graph.size()-1) {
			allSolutions.push_back(currentSolution);
		}

		return;
	}

	for(int path : graph.at(currentNode)) {
		recursive(allSolutions, graph, currentSolution, path);
	}
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
	vector<vector<int>> allSolutions;

	for(int path : graph.at(0)) {
		vector<int> currentSolution = {0};
		recursive(allSolutions, graph, currentSolution, path);
	}

	return allSolutions;
}



int main() {
	vector<vector<int>> graph = {
			{4,3,1}, {3,2,4}, {3}, {4}, {}
	};

	vector<vector<int>> allSolutions = allPathsSourceTarget(graph);

	for(vector<int> sol : allSolutions) {
		cout << "[";

		for(int y : sol) {
			cout << y << ",";
		}
		cout << "]" << endl;
	}

	return 0;
}

/*
 * [0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]
 * [0,4,],[0,3,4,],[0,1,3,4,],[0,1,2,3,4,],[0,1,4,]
 */