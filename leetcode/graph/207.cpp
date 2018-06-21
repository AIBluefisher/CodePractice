// ID: 207
// Description: 
// There are a total of n courses you have to take, labeled from 0 to n-1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

// Example 1:

// Input: 2, [[1,0]] 
// Output: true
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: 2, [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0, and to take course 0 you should
//              also have finished course 1. So it is impossible.

// ## 1. DFS
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<pair<int, unordered_set<int>>> courses(numCourses); // pair.first: marker, pair.second: adjacency list
        for (auto& p : prerequisites) { // create directed graph
            courses[p.second].second.insert(p.first);
        }
        for (auto& node : courses) { // DFS to find cycle
            if (node.first == 0 && hasCycle(courses, node)) return false;
        }
        return true;
    }
    
    bool hasCycle(vector<pair<int, unordered_set<int>>>& courses, pair<int, unordered_set<int>>& node) {
        if (node.first == 1) return true;
        node.first = 1; // Mark as DFS initiated
        for (int i : node.second) {
            if (hasCycle(courses, courses[i])) return true;
        }
        node.first = 2; // Mark as DFS completed
        return false;
    }
};


// ## 2. Top Sort
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<int> degree(numCourses, 0);
        vector<unordered_set<int>> graph(numCourses);
        for(auto pre : prerequisites) {
            graph[pre.second].insert(pre.first);
            degree[pre.first]++;
        }
        
        stack<int> st;
        for(int i = 0; i < graph.size(); i++) {
            if(degree[i] == 0) st.push(i);
        }     
        while(!st.empty()) {
            int node = st.top(); st.pop();
            visited[node] = 1;
            unordered_set<int> adjs = graph[node];
            for(auto adj : adjs) {
                degree[adj]--;
                if(degree[adj] == 0) st.push(adj);
            }
        }
        for(int i = 0; i < graph.size(); i++) {
            if(degree[i] != 0) return false;
        }   
        return  true;
    }
};