// ID: 744
/**
 * Given a list of sorted characters letters containing only lowercase letters, 
 * and given a target letter target, find the smallest element in the list that is larger than the given target.
 * Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], 
 * the answer is 'a'.
 */
// solution: sort the list and then bi-search
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        sort(letters.begin(), letters.end());
        if(letters[letters.size() - 1] <= target) return letters[0];
        int lb = -1, ub = letters.size() - 1;
        while(ub - lb > 1) {
            int mid = (lb + ub)  / 2;
            if(letters[mid] > target) ub = mid;
            else lb = mid;
        }
        return letters[ub]; 
    }
};