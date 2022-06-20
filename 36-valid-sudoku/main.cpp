#include <iostream>
#include <vector>
#include "unordered_map"
#include "unordered_set"

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rowMap;
        unordered_map<int, unordered_set<char>> columnMap;
        unordered_map<int, unordered_set<char>> boxMap;

        for(int x = 0; x < board.size(); x++) {
            for(int y = 0; y < board[0].size(); y++) {

                if(rowMap[y].find(board[x][y]) != rowMap[y].end()) return false;
                if(columnMap[x].find(board[x][y]) != columnMap[x].end()) return false;

                int idx = (x / 3) * 3 + y / 3;

                if(boxMap[idx].find(board[x][y]) != boxMap[idx].end()) return false;

                rowMap[y].insert(board[x][y]);
                columnMap[x].insert(board[x][y]);
                boxMap[idx].insert(board[x][y]);
            }
        }

        return true;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
