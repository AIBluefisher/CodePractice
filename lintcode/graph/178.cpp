class Solution {
private:
    vector<int> parent;
    vector<int> rank;
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        init(n);
        for(auto edge : edges) {
            if(findParent(edge[0]) == findParent(edge[1])) return false;
            else unite(edge[0], edge[1]);
        }
        //int all_parent = findParent(0);
        //for(int i = 1; i < n; i++) {
            //if(findParent(i) != all_parent) return false;
        //}
        
        return edges.size() == (n - 1);
    }
    
    void init(int n) {
        parent.reserve(n);
        rank.reserve(n);
        for(int i = 0; i < n; i++) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    
    int findParent(int idx) {
        return (parent[idx] == idx) ? idx : parent[idx] = findParent(parent[idx]);
    }
    
    void unite(int x, int y) {
        x = findParent(x);
        y = findParent(y);
        if(x == y) return;
        
        if(rank[x] < rank[y]) parent[x] = y;
        else {
            parent[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }
};