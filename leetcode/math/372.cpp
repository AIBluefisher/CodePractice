// ID: 372

// Description:
// Your task is to calculate ab mod 1337 where a is a positive integer and b is an 
// extremely large positive integer given in the form of an array.

// Example1:

// a = 2
// b = [3]

// Result: 8
// Example2:

// a = 2
// b = [1,0]

// Result: 1024

// Solution:
class Solution {
    const int mod = 1337;
public:
    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;
        int last_digit = b.back();
        b.pop_back();
        return mypow(superPow(a, b), 10) * mypow(a, last_digit) % mod;
    }
    
    int mypow(int a, int k) {
        int res = 1;
        a %= mod;
        for(int i = 0; i < k; i++) {
            res = res * a % mod;
        }
        return res;
    }
};