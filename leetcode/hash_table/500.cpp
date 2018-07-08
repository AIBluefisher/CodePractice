// ID: 500

// Description:
// Given a List of words, return the words that can be typed using letters of alphabet on 
// only one row's of American keyboard like the image below.

// Example 1:
// Input: ["Hello", "Alaska", "Dad", "Peace"]
// Output: ["Alaska", "Dad"]
// Note:
// You may use one character in the keyboard more than once.
// You may assume the input string will only contain letters of alphabet.


// Solution:
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> letter_map = 
            { {'q', 0}, {'w', 0}, {'e', 0}, {'r', 0}, {'t', 0}, {'y', 0}, {'u', 0}, {'i', 0}, {'o', 0}, {'p', 0}, 
             {'a', 1}, {'s', 1}, {'d', 1}, {'f', 1}, {'g', 1}, {'h', 1}, {'j', 1}, {'k', 1}, {'l', 1},
             {'z', 2}, {'x', 2}, {'c', 2}, {'v', 2}, {'b', 2}, {'n', 2}, {'m', 2}};
        vector<string> results;
        for(auto str : words) {
            int row = letter_map.find(tolower(str[0]))->second;
            bool same_row = true;
            for(int i = 1; i < str.size(); i++) {
                if(!(row == letter_map.find(tolower(str[i]))->second)) { same_row = false; break; }
            }
            if(same_row) results.push_back(str);
        }
        return results;
    }
};