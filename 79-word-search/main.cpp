#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<char>> board;
    int boardXSize;
    int boardYSize;
    string word;
    int wordSize;

    bool backtrack(int charIndex, int x, int y) {
        if(x >= boardXSize || x < 0 || y >= boardYSize || y < 0 || board[x][y] != word[charIndex]) return false;
        if(charIndex == wordSize) return true;

        char currentChar = board[x][y];

        board[x][y] = '1'; //set board location to seen

        bool result = (backtrack(charIndex+1, x+1, y) || backtrack(charIndex+1, x-1, y) || backtrack(charIndex+1, x, y+1) || backtrack(charIndex+1, x, y-1));

        if(!result) board[x][y] = currentChar; //set board location to unseen

        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->boardXSize = board.size();
        this->boardYSize = board[0].size();

        this->word = word;
        this->wordSize = word.size()-1;

        for(int x = 0; x < boardXSize; x++) {
            for(int y = 0; y < boardYSize; y++) {
                if(backtrack(0, x, y)) return true;
            }
        }

        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
