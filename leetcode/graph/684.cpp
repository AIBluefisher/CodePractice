// ID: 684
// Description: Redundant Connection
// solution: can be solved by Union-Find-Set simply.

class Solution {
private:
        vector<int> parent;
        vector<int> rank;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init();
        for(auto edge : edges) {
            if(find(edge[0]) == find(edge[1])) return edge;
            unite(edge[0], edge[1]);
        }
    }
    
    void init() {
        parent.reserve(1010);
        rank.reserve(1010);
        for(int i = 0; i < 1010; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    } 
    
    int find(int x) {
        return (parent[x] == x) ? x : parent[x] = find(parent[x]);
    }
    
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        
        if(rank[x] < rank[y]) parent[x] = y;
        else {
            parent[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }
};