// ID: 89

// Description:
// The gray code is a binary numeral system where two successive values differ in only one bit.

// Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

// Example 1:

// Input: 2
// Output: [0,1,3,2]
// Explanation:
// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2

// For a given n, a gray code sequence may not be uniquely defined.
// For example, [0,2,3,1] is also a valid gray code sequence.

// 00 - 0
// 10 - 2
// 11 - 3
// 01 - 1
// Example 2:

// Input: 0
// Output: [0]
// Explanation: We define the gray code sequence to begin with 0.
//              A gray code sequence of n has size = 2n, which for n = 0 the size is 20 = 1.
//              Therefore, for n = 0 the gray code sequence is [0].

// Solution:

// 1. recursive
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> results;
        unordered_set<string> bit_set;
        string bits;
        for(int i = 0; i < n; i++) bits += '0';
        bit_set.insert(bits);
        changeBits(results, bits, bit_set, n);
        return results;
    }
    
    void changeBits(vector<int>& results, string bits, unordered_set<string>& bit_set, int n) {
        results.push_back(bin2Dec(bits));
        for(int i = n - 1; i >= 0; i--) {
            char tmp = bits[i];
            bits[i] = (bits[i] == '1') ? '0' : '1';
            if(bit_set.find(bits) == bit_set.end()) {
                bit_set.insert(bits);
                changeBits(results, bits, bit_set, n);
            }
            else bits[i] = tmp;
        }
    }
    
    int bin2Dec(string bits) {
        int ans = 0;
        for(int i = 0; i < bits.size(); i++) {
            ans += pow(2, bits.size() - i - 1) * (bits[i] - '0');
        }
        return ans;
    }
};

// 2. G[i] = i ^ (i >> 1)
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> results;
        for(int i = 0; i < (1 << n); i++) {
            results.push_back(i ^ (i >> 1));
        }
        return results;
    }
};