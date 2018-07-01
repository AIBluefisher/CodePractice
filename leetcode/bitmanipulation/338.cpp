// ID: 338

// Description:
// Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's 
// in their binary representation and return them as an array.

// Example:
// For num = 5 you should return [0,1,1,2,1,2].

// Follow up:

// It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
// Space complexity should be O(n).
// Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
// Credits:
// Special thanks to @ syedee for adding this problem and creating all test cases.

// Solution:
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> results;
        for(int i = 0; i <= num; i++) {
            int n = i;
            int count = 0;
            while(n > 0) {
                if(n & 1) count++;
                n >>= 1;
            }
            results.push_back(count);
        }
        return results;
    }
};

