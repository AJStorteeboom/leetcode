#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <tuple>

using namespace std;

class Solution {
public:
	unordered_map<int, int> memo;

	int dfs(unordered_map<int, vector<vector<int>>> flightsMap, int src, int dst, int K) {
		queue<tuple<int,int,int>> queue;
		queue.push(tuple<int,int,int>(src, 0, 0));

		while (!queue.empty()) {
			tuple<int,int,int> node = queue.front();
			get<1>(node);
			queue.pop();

			if(get<2>(node) > K+1 || (memo.find(get<0>(node)) != memo.end() && memo[get<0>(node)] <= get<1>(node))) continue;

			memo[get<0>(node)] = get<1>(node);
			vector<vector<int>> flights = flightsMap[get<0>(node)];

			for(vector<int> flight : flights) queue.push(tuple<int,int,int>(flight[1], get<1>(node)+flight[2], get<2>(node)+1));
		}

		return (memo.find(dst) != memo.end()) ? memo[dst] : -1;
	}

	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
		unordered_map<int, vector<vector<int>>> flightsMap;

		for(vector<int> flight : flights) {
			if(flightsMap.find(flight[0]) != flightsMap.end()) {
				flightsMap.at(flight[0]).push_back(flight);
			} else {
				vector<vector<int>> temp = {{flight}};
				flightsMap.insert({flight[0], temp});
			}
		}

		return dfs(flightsMap, src, dst, K);
	}
};


int main() {
	vector<vector<int>> flights = {{0, 1, 100}, {1,2,100}, {0,2,500}};
	Solution solution;
	std::cout << solution.findCheapestPrice(3, flights, 0, 2, 1) << std::endl;
	return 0;
}
