## 200. Number of Islands

**Difficulty**: Medium

**描述**

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

**分析**

不知道为什么这一题在leetcode里归为并查集一类，很明显是深度有限搜索题．对于每一次搜索，将遍历到的区域置为０，一次深度优先搜索可将相邻连通的陆地遍历完．非联通的部分继续调用深度优先搜索即可．深度优先搜索调用的次数即为岛屿的数目．

**代码**：

```C++
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == '1') 
                {
                    dfs(i, j, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
    
    void dfs(int x, int y, vector<vector<char>>& grid)
    {
        grid[x][y] = '0';
        int dx[4] = {-1, 0, 0, 1};
        int dy[4] = {0, -1, 1, 0};
        for(int i = 0; i < 4; i++)
        {
            int ox = x + dx[i];
            int oy = y + dy[i];
            if(0 <= ox && ox < grid.size() && 0 <= oy && oy < grid[0].size() && grid[ox][oy] == '1')
                dfs(ox, oy, grid);
        }
    }
    
};
```
