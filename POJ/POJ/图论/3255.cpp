#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

const int MAXV = 5010;
const int INF = 0x7FFFFFFF;

typedef pair<int, int> P;
struct edge { int to, cost; };
vector<edge> G[MAXV];

int N, R;
int dist[MAXV];
int dist2[MAXV];

void solve()
{
    priority_queue<P, vector<P>, greater<P> > qu; 
    for(int i = 0; i < N; i++) {
        dist[i] =  dist2[i] = INF;
    }
    dist[0] = 0;
    qu.push(P(0, 0));
    while(!qu.empty()) {
        P p = qu.top(); qu.pop();
        int v = p.second, d = p.first;
        if(dist2[v] < d) continue;
        
        for(int i = 0; i < G[v].size(); i++) {
            edge e = G[v][i];
            int d2 = d + e.cost;
            if(dist[e.to] > d2) {
                swap(dist[e.to], d2);
                qu.push(P(dist[e.to], e.to));
            }
            if(dist[e.to] < d2 && d2 < dist2[e.to]) {
                dist2[e.to] = d2;
                qu.push(P(dist2[e.to], e.to));
            }
        }
    }
    cout << dist2[N - 1] << endl;
}

int main()
{
    int A, B, D;
    cin >> N >> R;
    for(int i = 0; i < R; i++) {
        cin >> A >> B >> D;
        edge e;
        e.to = B - 1;
        e.cost = D;
        G[A - 1].push_back(e);
    }

    solve();
}