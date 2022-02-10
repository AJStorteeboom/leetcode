#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
	queue<pair<int,int>> posQueue;
	posQueue.push(pair<int,int>(sr, sc));

	int xMax = image.size();
	int yMax = image[0].size();
	int colorStartingPixel = image[sr][sc];

	while (!posQueue.empty()) {
		pair<int,int> location = posQueue.front();
		posQueue.pop();
		image[location.first][location.second] = newColor;
		if(location.first > 0 && image[location.first-1][location.second] == colorStartingPixel && image[location.first-1][location.second] != newColor) posQueue.push(pair<int,int>(location.first-1, location.second));
		if(location.first < xMax && image[location.first+1][location.second] == colorStartingPixel && image[location.first+1][location.second] != newColor) posQueue.push(pair<int,int>(location.first+1, location.second));
		if(location.second > 0 && image[location.first][location.second-1] == colorStartingPixel && image[location.first][location.second-1] != newColor) posQueue.push(pair<int,int>(location.first, location.second-1));
		if(location.second < yMax && image[location.first][location.second+1] == colorStartingPixel && image[location.first][location.second+1] != newColor) posQueue.push(pair<int,int>(location.first, location.second+1));
	}

	return image;
}

int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}

// 0, 0, 0
// 0, 1, 1
//