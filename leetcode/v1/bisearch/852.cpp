// ID: 852

// Description:
// Let's call an array A a mountain if the following properties hold:

// A.length >= 3
// There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
// Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

// Example 1:

// Input: [0,1,0]
// Output: 1
// Example 2:

// Input: [0,2,1,0]
// Output: 1
// Note:

// 3 <= A.length <= 10000
// 0 <= A[i] <= 10^6
// A is a mountain, as defined above.

// Solution:

// 1. max_element
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        return max_element(A.begin(), A.end()) - A.begin();
    }
};

// 2. linear search
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int index = 0;
        for(int i = 1; i < A.size(); i++) {
            if(A[i - 1] < A[i] && A[i] > A[i + 1]) {
                index = i;
                break;
            }
        }
        return index;
    }
};

// 3. binary search
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int lb = 0, ub = A.size() - 1;
        while(lb < ub) {
            int mid = (lb + ub) / 2;
            if(A[mid - 1] > A[mid]) ub = mid;
            else if(A[mid] < A[mid + 1]) lb = mid;
            else return  mid;
        }
    }
};