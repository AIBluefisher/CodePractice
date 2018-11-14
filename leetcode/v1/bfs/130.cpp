// ID: 130

// Description:
// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// Example:

// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:

// X X X X
// X X X X
// X X X X
// X O X X
// Explanation:

// Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. 
// Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. 
// wo cells are connected if they are adjacent cells connected horizontally or vertically.

// Solution:
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        vector<vector<int>> visited;
        for(int i = 0; i < board.size(); i++) {
            vector<int> v(board[0].size(), 0);
            visited.push_back(v);
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                // traverse from border
                if(board[i][j] == 'O' && (i == 0 || i == board.size() - 1 || j == 0 || j == board[i].size() - 1)) {
                    dfs(board, visited, dx, dy, i, j);
                }
            }
        }
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                if(!visited[i][j] && board[i][j] == 'O') {
                    board[i][j] ='X';
                }
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int dx[], int dy[], int x, int y) {
        visited[x][y] = 1;
        for(int i = 0; i < 4; i++) {
            int ox = x + dx[i], oy = y + dy[i];
            if(0 <= ox && ox < board.size() && 0 <= oy && oy < board[0].size()) {
                if(!visited[ox][oy] && board[ox][oy] == 'O') dfs(board, visited, dx, dy, ox, oy);
            }
        }
    }
};