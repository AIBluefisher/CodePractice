// ID: 145
// Description: Lowercase to Uppercase
// Convert a lowercase character to uppercase.


class Solution {
public:
    /**
     * @param character: a character
     * @return: a character
     */
    char lowercaseToUppercase(char character) {
        return character + 'A' - 'a';
    }
};