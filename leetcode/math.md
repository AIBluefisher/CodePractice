## 67. Add Binary

**Difficulty**: Easy

**Description**
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

**分析**
二进制加法，由于字符串正序，但是加法是从低位加起，因此需要从两个字符串的最后一位开始加起。注意进位以及最后将字符串反转即可。

**代码**

```C++
class Solution {
public:
    string addBinary(string a, string b) {
        int len = max(a.size(), b.size());
        char* result = new char [len + 2];
        int carry = 0;
        int i = 0;
        int l1 = a.size() - 1;
        int l2 = b.size() - 1;
        for(; i < len; i++)
        {
            int v1 = (l1 >= 0 ? a[l1] - '0' : 0);
            int v2 = (l2 >= 0 ? b[l2] - '0' : 0);
            l1--; l2--;
            
            int val = v1 + v2 + carry;
            carry = val >= 2 ? 1 : 0;
            val %= 2;
            result[i] = val + '0';
        }
        if(carry) result[i++] = '1';
        result[i] = '\0';
        string str = result;
        reverse(str.begin(), str.end());
        return str;
    }
};
```

## 268. Missing Number

**Difficulty**: Easy

**Description**
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

Example 1

Input: [3,0,1]
Output: 2
Example 2

Input: [9,6,4,2,3,5,7,0,1]
Output: 8

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

**分析**
这题没有思路的话不太好做，有思路的话就非常简单了。因为所给的数组一定是一个缺了某个数的等差数列，对于一个给定的等差数列，总可以计算出它的和，再减去所给数组的和，就能得到所差的那个数了。

**代码**

```C++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) sum += nums[i];
        
        int n = nums.size();
        return ((n + 1) * n) / 2 - sum;
    }
};
```