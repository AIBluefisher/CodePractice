// ID: 79

// Description:
// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, 
// where "adjacent" cells are those horizontally or vertically neighboring. 
// The same letter cell may not be used more than once.

// Example:

// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]

// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.

// Solution:
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(board[i][j] == word[0]) {
                    if(dfs(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string word, int x, int y, int k) {
        if(k == word.size()) return true;
        if(!(0 <= x && x < board.size() && 0 <= y && y < board[x].size()))
            return false;
        if(board[x][y] != word[k]) return false;
        
        board[x][y] = '*';
        int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
        for(int i = 0; i < 4; i++) {
           int ox = x + dx[i], oy = y + dy[i];
           if(dfs(board, word, ox, oy, k + 1)) return true;
        }
        board[x][y] = word[k];
        return false;
    }
};
