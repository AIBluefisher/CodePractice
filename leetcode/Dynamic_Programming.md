## 63. Unique Paths

**Difficulty**: Medium

**描述**

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.



**分析**

很简单，设dp[i][j]为走到坐标为(i,j)的格子的不同路径数，则状态转移方程为dp[i][j] = dp[i][j - 1] + dp[i - 1][j]．
注意初始时，第一行和第一列的所有格子的路径数都是１，因此初始化的时候将dp均设为１．

**代码**
```C++
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1));
        
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++) dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
        return dp[m - 1][n - 1];
    }
};
```

## 63. Unique Paths II

**Difficulty**: Medium

**描述**

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

**分析**

让我们来仔细分析一下！
（１）考虑当前格子的值．和Unique Path相似，不同的是若当前格子的值为１，表示有障碍，不能走，可走的路径为０．状态转移方程为：
若 obstacleGrid[i][j] == 1, dp[i][j] = 0;　否则　dp[i][j] = dp[i][j - 1] + dp[i - 1][j]．时间复杂度和空间复杂度均为o(mn).
这里需要注意的是dp的初始化．若第一行或者第一列中某个格子出现了障碍，那么接下来改行或者该列中的所有格子都不能走．
（２）考虑当前格子最近的左上角对角线处的格子．若(i-1, j-1)处格子值为１，那么无论如何，当前格子都是走不到的，因为第(i-1,j)个格子和第(i,j-1)个格子
都被对角线处的那个格子挡住了．因此状态转移方程为若obstacleGrid[i - 1][j - 1] == 0, dp[i][j] = dp[i][j - 1] + dp[i - 1][j]．

**代码**
```C++
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        bool hasObstacle = false;
        for(int i = 0; i < n; i++) 
        {
            if(obstacleGrid[0][i]) hasObstacle = true;
            dp[0][i] = hasObstacle ? 0 : 1;
        }
        hasObstacle = false;
        for(int i = 0; i < m; i++) 
        {
            if(obstacleGrid[i][0]) hasObstacle = true;
            dp[i][0] = hasObstacle ? 0 : 1;
        }
        
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(!obstacleGrid[i][j]) dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
```

**更为简洁的代码**
```C++
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size() , n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1,vector<int>(n + 1,0));
        dp[0][1] = 1;　// same for dp[1][0] =1
        for(int i = 1 ; i <= m ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                if(!obstacleGrid[i - 1][j - 1]) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};
```