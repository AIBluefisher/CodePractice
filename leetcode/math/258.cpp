// ID: 258.cpp

// Description:

// Solution:
// 1.
class Solution {
public:
    int addDigits(int num) {
        while(true) {
            int sum = 0;
            string str = to_string(num);
            for(auto s : str) sum += s - '0';
            if(sum < 10) return sum;
            num = sum;
        }
    }
};


// 2.
// Reference: 
// https://leetcode.com/problems/add-digits/discuss/68580/Accepted-C++-O(1)-time-O(1)-space-1-Line-Solution-with-Detail-Explanations
class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};