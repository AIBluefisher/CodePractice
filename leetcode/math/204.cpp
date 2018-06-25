// ID: 204

// Description:
// Count the number of prime numbers less than a non-negative number, n.

// Example:

// Input: 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

// Solution:
// 埃式筛法
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<int> isPrime(n, 1);
        for(int i = 2; i < n; i++) {
            if(isPrime[i]) count++;
            for(int j = 2 * i; j < n; j += i) isPrime[j] = 0;
        }
        return  count;
    }
};