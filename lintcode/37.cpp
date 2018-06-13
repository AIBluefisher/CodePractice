// ID: 37
// Description: Reverse a 3-digit integer.
// You may assume the given number is larger or equal to 100 but smaller than 1000.


class Solution {
public:
    /**
     * @param number: A 3-digit number.
     * @return: Reversed number.
     */
    int reverseInteger(int number) {
        vector<int> digits;
        while(number > 0) {
            digits.push_back(number % 10);
            number /= 10;
        }
        
        int sum = 0;
        for(int i = 0; i < 3; i++) {
            if(!digits[i]) continue;
            sum += digits[i] * pow(10, 2 - i);
        }
        return sum;
    }
};