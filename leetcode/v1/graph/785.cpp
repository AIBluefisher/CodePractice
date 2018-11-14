// 实际上是一个二分图问题
class Solution {
public:
    bool isBipartite(vector<vector<int>> &graph) {
        vector<int> color(110, 0);
        for(int i = 0; i < graph.size(); i++) {
            if(color[i] == 0) {
                if(!dfs(graph, color, i, 1)) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool dfs(vector<vector<int>> &graph, vector<int>& color, int v, int c ) {
        color[v] = c;
        for(int i = 0; i < graph[v].size(); i++) {
            if(color[graph[v][i]] == c) return false;
            if(color[graph[v][i]] == 0 && !dfs(graph, color, graph[v][i], -c)) return false;
        }
        return true;
    }
};