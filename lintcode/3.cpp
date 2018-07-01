// ID: 3
// Description: digit count
// Count the number of k's between 0 and n. k can be 0 - 9.
// Solution:
class Solution {
public:
    /*
     * @param : An integer
     * @param : An integer
     * @return: An integer denote the count of digit k in 1..n
     */
    int digitCounts(int k, int n) {
        int num = 0;
        for(int i = 0; i <= n; i++) {
            string str = to_string(i);
            for(auto s : str) {
                if(s - '0' == k) num++;
            }
        }
        return num;
    }
};