## 35. Search Insert Position

**Difficulty**: easy

**描述**

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 1:

Input: [1,3,5,6], 0
Output: 0

**分析**

简单的二分查找。找到时返回所在位置索引即可。若没找到，当当前位置指针指向元素小于target时，返回当前指针的下一个位置；当当前位置指针指向元素大于target时，则返回当前位置。

**代码**
```C++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lb = 0;
        int ub = nums.size() - 1;
        while(lb != ub)
        {
            int mid = (lb + ub) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) ub = mid;
            else lb = mid + 1;
        }
        if(nums[lb] < target) return lb + 1;
        else return lb;
    }
};
```


## 278. First Bad Version

**Difficulty**: Easy

**描述**

ou are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

**分析**

要求为调用isBadVersion()的次数最少。很明显，如果使用顺序的方法直接扫描，当对每一个元素均调用一次API，当第一个isBadVersion(i) == true的时候即返回i，这种方法的时间复杂度为O(n)。仔细思考，由于前一个坏的产品会影响到后面所有的产品，因此，可以考虑使用二分查找，如果当前产品没坏，说明该产品前面的产品都没有坏，下一次查找从该产品之后的产品中查找；如果当前产品坏了，那么该产品后面的产品肯定都坏了，但是该产品不一定就是第一个坏的（因为前面的会影响到后面），因此下一次查找从该产品的前一部分开始查找。由于第一个坏的产品总是存在，因此最后返回lb。

最后要注意的是计算mid时，lb + ub可能会溢出，因此需要将mid = (lb + ub) / 2改写为mid = lb + (ub - lb) / 2

**代码**

```C++
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lb = 1;
        int ub = n;
        while(lb != ub)
        {
            int mid = lb + (ub - lb) / 2;
            if(isBadVersion(mid)) ub = mid;
            else lb = mid + 1;
        }
        return lb;
    }
};
```

## 374. Guess Number Higher or Lower

**Difficulty**: Easy

**描述**

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example:
n = 10, I pick 6.

Return 6.

**分析**

思路很简单，二分查找即可。

最后要注意的是计算mid时，lb + ub可能会溢出，因此需要将mid = (lb + ub) / 2改写为mid = lb + (ub - lb) / 2

**代码**

```C++
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int lb = 1;
        int ub = n;
        while(lb != ub)
        {
            int mid = lb + (ub - lb) / 2;
            if(guess(mid) == 0) return mid;
            else if(guess(mid) == 1) lb = mid + 1;
            else ub = mid;
        } 
        return lb;
    }
};
```