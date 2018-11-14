// ID: 119

// Description:
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?


// Solution:
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pre(rowIndex + 2, 0);
        vector<int> cur(rowIndex + 2, 0);
        pre[1] = 1;
        if(!rowIndex) return { pre[1] };
        for(int k = 1; k <= rowIndex; k++) {
            for(int i = 1; i <= k + 1; i++) {
                cur[i] = pre[i - 1] + pre[i];
            }
            // update pre
            pre = cur;
        }
        return vector<int>(cur.begin() + 1, cur.end());
    }
};