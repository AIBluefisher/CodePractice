// ID: 6

// Description:
// Merge two given sorted integer array A and B into a new sorted integer array.

// Have you met this question in a real interview?  
// Example
// A=[1,2,3,4]

// B=[2,4,5,6]

// return [1,2,2,3,4,4,5,6]

// Challenge
// How can you optimize your algorithm if one array is very large and the other is very small?

// Solution:
class Solution {
public:
    /**
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        vector<int> results;
        int i = 0, j = 0;
        while(i < A.size() && j < B.size()) {
            if(A[i] < B[j]) {  results.push_back(A[i]); i++; }
            else { results.push_back(B[j]); j++; }
        }
        while(i < A.size()) { results.push_back(A[i++]); }
        while(j < B.size()) { results.push_back(B[j++]); }
        return results;
    }
};