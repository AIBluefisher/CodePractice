// ID: 743

// Description:
// There are N network nodes, labelled 1 to N.

// Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

// Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

// Note:
// N will be in the range [1, 100].
// K will be in the range [1, N].
// The length of times will be in the range [1, 6000].
// All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.

// Solution:

// 1. Dijkstra
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<unordered_map<int, int>> graph(N);
        for(int i = 0; i < times.size(); i++) {
            graph[times[i][0] - 1].insert(make_pair(times[i][1] - 1, times[i][2]));
        }
        const int INF = 1000000;
        vector<int> d(N, INF);
        vector<bool> visited(N, false);
        d[K - 1] = 0;
        while(true) {
            int v = -1;
            for(int u = 0; u < N; u++) {
                if(!visited[u] && (v == -1 || d[u] < d[v])) v = u;
            }
            if(v == -1) break;
            visited[v] = 1;
            
            for(int u = 0; u < N; u++) {
                auto edge = graph[v].find(u);
                if(edge != graph[v].end()) {
                    d[u] = min(d[u], d[v] + edge->second);
                }
            }
        }
        int ans = *(max_element(d.begin(), d.end()));
        return ans == INF ? -1 : ans;
    }
};

// 2. Dijkstra with priority_queue
class Solution {
    typedef pair<int, int> P;   // first is min-distance, second is destination
    const int INF = 1000000;
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<unordered_map<int, int>> graph(N);
        for(int i = 0; i < times.size(); i++) {
            graph[times[i][0] - 1].insert(make_pair(times[i][1] - 1, times[i][2]));
        }
        
        vector<int> d(N, INF);
        d[K - 1] = 0;
        priority_queue<P, vector<P>, greater<P>> qu;
        qu.push(P(0, K - 1));
        
        while(!qu.empty()) {
            P p = qu.top(); qu.pop();
            if(d[p.second] < p.first) continue;
            for(int i = 0; i < N; i++) {
                auto u = graph[p.second].find(i);
                if(u != graph[p.second].end()) {
                    if(d[i] > d[p.second] + u->second) {
                        d[i] = d[p.second] + u->second;
                        qu.push(P(d[i], i));
                    }
                }
            }// end for
        }
        int ans = *(max_element(d.begin(), d.end()));
        return ans == INF ? -1 : ans;
    }
};