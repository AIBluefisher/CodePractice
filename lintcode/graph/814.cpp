/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: a list of Undirected graph node
     * @param A: nodeA
     * @param B: nodeB
     * @return:  the length of the shortest path
     */
    int shortestPath(vector<UndirectedGraphNode*> graph, UndirectedGraphNode* A, UndirectedGraphNode* B) {
        vector<int> visited(graph.size() + 10, 0);
        vector<int> d(graph.size() + 10, 0);
        queue<UndirectedGraphNode*> qu;
        for(auto node : graph) {
            if(node->label == A->label) {
                qu.push(node);
                break;
            }
        }
        visited[A->label] = 1;
        while(!qu.empty()) {
            UndirectedGraphNode* g = qu.front();
            qu.pop();
            vector<UndirectedGraphNode *> neighbors = g->neighbors;
            for(auto neighbor : neighbors) {
                if(!visited[neighbor->label]) {
                    if(neighbor->label == B->label) {
                        d[B->label] = d[g->label] + 1;
                        return d[B->label];
                    }
                    else {
                        visited[neighbor->label] = 1;
                        d[neighbor->label] = d[g->label] + 1;
                        qu.push(neighbor);
                    }
                }
            }
        }
    }
};