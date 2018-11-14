// ID: 350

// Description:
// Given two arrays, write a function to compute their intersection.

// Example:
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

// Note:
// Each element in the result should appear as many times as it shows in both arrays.
// The result can be in any order.
// Follow up:
// What if the given array is already sorted? How would you optimize your algorithm?
// What if nums1's size is small compared to nums2's size? Which algorithm is better?
// What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

// Solution:
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums_map;
        for(auto num : nums1) {
            if(nums_map.find(num) == nums_map.end())
                nums_map.insert(make_pair(num, 1));
            else nums_map[num]++;
        }

        vector<int> results;
        for(auto num : nums2) {
            if(nums_map.find(num) != nums_map.end()) {
                if(nums_map[num] > 0) {
                    results.push_back(num);
                    nums_map[num]--;
                }
            }
        }
        return results;
    }
};
