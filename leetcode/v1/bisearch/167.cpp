

// 1. brute-force
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size(); i++) {
            for(int j = i + 1; j < numbers.size(); j++) {
                if(numbers[i] + numbers[j] == target) return {i + 1 ,j + 1};
            }
        }
    }
};

// 2. two-pointer
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lb = 0, ub = numbers.size() - 1;
        while(ub - lb >= 1) {
            int s = numbers[lb] + numbers[ub];
            if(s > target) ub--;
            else if(s < target) lb++;
            else return {lb + 1, ub + 1};
        }
    }
};