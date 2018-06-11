## 349. Intersection of Two Arrays

**Difficulty**: Easy

**Description**

Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.

**分析**

这里我实现了两种方法。一种是先排序，然后删除两个vector中的相同元素，再依次查找；另一种是使用unordered_set。

**代码**

```C++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int>::iterator nums1_unique = unique(nums1.begin(), nums1.end());
        nums1.erase(nums1_unique, nums1.end());
        vector<int>::iterator nums2_unique = unique(nums2.begin(), nums2.end());
        nums2.erase(nums2_unique, nums2.end());
        
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] == nums2[j]) 
            {
                result.push_back(nums1[i]);
                i++;j++;
            }
            else if(nums1[i] < nums2[j]) i++;
            else j++;
        }
        return result;
    }
};
```

```C++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> s(nums1.begin(), nums1.end());
        
        for(auto n : nums2)
        {
            if(s.erase(n)) result.push_back(n);
        }
        
        return result;
    }
};
```