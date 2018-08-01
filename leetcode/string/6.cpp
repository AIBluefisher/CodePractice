// ID: 6

// Description: 
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
// (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);
// Example 1:

// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// Example 2:

// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:

// P     I    N
// A   L S  I G
// Y A   H R
// P     I

// Solution:
class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        int k = 0, direction = 1;
        vector<vector<char>> cmap(numRows);
        
        while(k < s.size()) {
            if(direction == 1) {
                for(int i = 0; i < numRows && k < s.size(); i++)
                    cmap[i].push_back(s[k++]);
                direction = 0;  // go to top
            }
            else if(direction == 0) {
                for(int i = numRows - 2; i >= 1 && k < s.size(); i--)
                    cmap[i].push_back(s[k++]);
                direction = 1;  // go to bottom
            }
        }
        for(int i = 0; i < numRows; i++) {
            for(int j = 0; j < cmap[i].size(); j++)
                ans += cmap[i][j];
        }
        return ans;
    }
};