// ID: 399

// Description:

// Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number 
// (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

// Example:
// Given a / b = 2.0, b / c = 3.0. 
// queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
// return [6.0, 0.5, -1.0, 1.0, -1.0 ].

// The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , 
// where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

// According to the example above:

// equations = [ ["a", "b"], ["b", "c"] ],
// values = [2.0, 3.0],
// queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
// The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.

// Solution:
class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> results;
        int l = 0;
        map<string, int> nodes;
        for(auto equation : equations) {
            if(nodes.find(equation.first) == nodes.end())
                nodes.insert(make_pair(equation.first, l++));
            if(nodes.find(equation.second) == nodes.end())
                nodes.insert(make_pair(equation.second, l++));
        }
        
        double graph[nodes.size()][nodes.size()];
        const double inf = 10000000.0;
        for(int i = 0; i < nodes.size(); i++) {
            for(int j = 0; j < nodes.size(); j++) {
                graph[i][j] = (i == j) ? 1.0 : inf;
            }
        }
        
        for(int i = 0; i < equations.size(); i++) {
            int src = nodes.find(equations[i].first)->second;
            int dst = nodes.find(equations[i].second)->second;
            graph[src][dst] = values[i];
            graph[dst][src] = 1.0 / values[i];
        }
        
        // floyd-warshall
        for(int k = 0; k < nodes.size(); k++) {
            for(int i = 0; i < nodes.size(); i++) {
                for(int j = 0; j < nodes.size(); j++) {
                    if(graph[i][k] != inf && graph[k][j] != inf) {
                        graph[i][j] = min(graph[i][j], graph[i][k] * graph[k][j]);
                    }
                }
            }
        }
        
        // query
        for(auto query : queries) {
            auto lit = nodes.find(query.first), rit = nodes.find(query.second);
            if(lit == nodes.end() || rit == nodes.end()) 
                results.push_back(-1.0);
            else {
                int u = lit->second, v = rit->second;
                results.push_back(graph[u][v] == inf ? -1.0 : graph[u][v]);
            }
        }
        return results;
    }
};