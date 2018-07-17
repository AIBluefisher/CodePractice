// ID: 867

// Description:


// Solution:
// 1.
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if(A.empty()) return {};
        vector<vector<int>> ans;
        for(int j = 0; j < A[0].size(); j++) {
            vector<int> tmp;
            for(int i = 0; i < A.size(); i++)
                tmp.push_back(A[i][j]);
            ans.push_back(tmp);
        }
        return ans;
    }
};

// 2.
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if(A.empty()) return {};
        vector<vector<int>> ans(A[0].size());
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < A[i].size(); j++) {
                ans[j].push_back(A[i][j]);
            }
        }
        return ans;
    }
};