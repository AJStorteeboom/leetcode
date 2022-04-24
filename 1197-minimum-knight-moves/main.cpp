#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

/*
 * class Solution {
    public int minKnightMoves(int x, int y) {
        // the offsets in the eight directions
        int[][] offsets = {
        {1, 2}, {2, 1}, {2, -1}, {1, -2},
                {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

        // - Rather than using the inefficient HashSet, we use the bitmap
        //     otherwise we would run out of time for the test cases.
        // - We create a bitmap that is sufficient to cover all the possible
        //     inputs, according to the description of the problem.
        boolean[][] visited = new boolean[607][607];

        Deque<int[]> queue = new LinkedList<>();
        queue.addLast(new int[]{0, 0});
        int steps = 0;

        while (queue.size() > 0) {
            int currLevelSize = queue.size();
            // iterate through the current level
            for (int i = 0; i < currLevelSize; i++) {
                int[] curr = queue.removeFirst();
                if (curr[0] == x && curr[1] == y) {
                    return steps;
                }

                for (int[] offset : offsets) {
                    int[] next = new int[]{curr[0] + offset[0], curr[1] + offset[1]};
                    // align the coordinate to the bitmap
                    if (!visited[next[0] + 302][next[1] + 302]) {
                        visited[next[0] + 302][next[1] + 302] = true;
                        queue.addLast(next);
                    }
                }
            }
            steps++;
        }
        // move on to the next level
        return steps;
    }
}
 *
 *
 *
 */

class Solution {
public:

    vector<vector<int>> possibleSteps = {
            {1, 2}, {2, 1},
            {-1 ,2}, {-2, 1},
            {-1, -2}, {-2, -1},
            {1,-2}, {2, -1}
    };

    int VISIT_OFFSET = 302;

    int minKnightMoves(int x, int y) {
        int visited[607][607] = {0};

        queue<pair<int,int>> posQueue;
        posQueue.push(pair<int,int>(0,0));

        int currentSteps = 0;

        while (!posQueue.empty()) {
            int currentQueueSize = posQueue.size();
            for(int posQueueIterator = 0; posQueueIterator < currentQueueSize; posQueueIterator++) {
                pair<int,int> currentPos = posQueue.front();
                posQueue.pop();

                if(currentPos.first == x && currentPos.second == y) return currentSteps; //Target reached!

                //Add all locations to the queue that we didn't visit
                for(vector<int> step : possibleSteps) {
                    if(visited[currentPos.first+step[0] + VISIT_OFFSET][currentPos.second+step[1] + VISIT_OFFSET] != 0) continue; //Skip if already visited

                    visited[currentPos.first+step[0] + VISIT_OFFSET][currentPos.second+step[1] + VISIT_OFFSET] = 1; //Very important to set visited to true here to prevent duplicate locations in queue.

                    posQueue.push(pair<int,int>(currentPos.first+step[0], currentPos.second+step[1]));
                }
            }

            currentSteps++;
        }

        return -1; //Should never be reached
    }
};

int main() {
    Solution sol;

    std::cout << sol.minKnightMoves(300, 300) << std::endl;
    return 0;
}
