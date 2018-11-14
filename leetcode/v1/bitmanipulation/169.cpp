// ID: 169

// Description:
// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

// You may assume that the array is non-empty and the majority element always exist in the array.

// Example 1:

// Input: [3,2,3]
// Output: 3
// Example 2:

// Input: [2,2,1,1,1,2,2]
// Output: 2

// Solution:

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> appMap;
        for(auto n : nums) {
            unordered_map<int, int>::iterator it = appMap.find(n);
            if(it == appMap.end()) appMap.insert(make_pair(n, 1));
            else (it->second)++;
        }
        
        int ans = 0;
        for(unordered_map<int, int>::iterator it = appMap.begin(); it != appMap.end(); it++) {
            if(it->second > nums.size() / 2) { 
                ans = it->first;
                break;
            }
        }
        return ans;
    }
};