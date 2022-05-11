#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int sizeY = mat.size();
        int sizeX = mat[0].size();

        vector<vector<int>> result(mat.size(), vector<int> (mat[0].size(), -1));
        queue<pair<int,int>> queue;

        for(int x = 0; x < sizeY; x++) {
            for(int y = 0; y < sizeX; y++) {
                if(mat[x][y] == 0) {
                    result[x][y] = 0; //Set to 0 in result because it takes 0 steps and we can skip it in the BFS
                    queue.push(pair<int,int>(x,y)); //Push every 0 to the queue. With BFS we are sure we have the shortest route (min number of steps) to a 1.
                }
            }
        }

        while (!queue.empty()) {
            int currentQueueSize = queue.size();

            //The for loop below isn't needed.
            //This is only neccessary when we need to keep track of the number of steps we do or something like that and we can't store te number of steps in an array
            //BUT: Not 100% sure why but when this for loop is used, it finishes in ~80ms and without in ~130ms.
            //The only reason I can think of is because of the for loop it can skip the queue.empty for a lot of times.
            for(int x = 0; x < currentQueueSize; x++) {
                pair<int,int> pos = queue.front();
                queue.pop();

                if(pos.first > 0 && result[pos.first-1][pos.second] == -1) {
                    result[pos.first-1][pos.second] = result[pos.first][pos.second]+1;
                    queue.push(pair<int,int>(pos.first-1, pos.second));
                }
                if(pos.first < sizeY-1 && result[pos.first+1][pos.second] == -1) {
                    result[pos.first+1][pos.second] = result[pos.first][pos.second]+1;
                    queue.push(pair<int,int>(pos.first+1, pos.second));
                }
                if(pos.second > 0 && result[pos.first][pos.second-1] == -1) {
                    result[pos.first][pos.second-1] = result[pos.first][pos.second]+1;
                    queue.push(pair<int,int>(pos.first, pos.second-1));
                }
                if(pos.second < sizeX-1 && result[pos.first][pos.second+1] == -1) {
                    result[pos.first][pos.second+1] = result[pos.first][pos.second]+1;
                    queue.push(pair<int,int>(pos.first, pos.second+1));
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> mat = {{0, 1}};
    vector<vector<int>> res = sol.updateMatrix(mat);
    return 0;
}
