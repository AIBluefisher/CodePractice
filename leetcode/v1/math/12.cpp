// ID: 12

// Description:


// Solution:

// 1. hash map
class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> roman_map = {{1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"},
                                                {4, "IV"}, {9, "IX"}, {40, "XL"}, {90, "XC"}, {400, "CD"}, {900, "CM"}};
        string ans = "";
        while(num > 0) {
            auto it = roman_map.find(num);
            if(it == roman_map.end()) {
                if(1 < num && num < 5) { ans += "I"; num -= 1; }
                else if(5 < num && num < 10) { ans += "V"; num -= 5; }
                else if(10 < num && num < 40) { ans += "X"; num -= 10; }
                else if(40 < num && num < 50) { ans += "XL"; num -= 40; }
                else if(50 < num && num < 90) { ans += "L"; num -= 50; }
                else if(90 < num && num < 100) { ans += "XC"; num -= 90; }
                else if(100 < num && num < 400) { ans += "C"; num -= 100; }
                else if(400 < num && num < 500) { ans += "CD"; num -= 400; }
                else if(500 < num && num < 900) { ans += "D"; num -= 500; }
                else if(900 < num && num < 1000) { ans += "CM"; num -= 900; }
                else if(1000 < num) { ans += "M"; num -= 1000; }
            }
            else {
                ans += it->second;
                num -= it->first;
            }
        }
        return ans;
    }
};

// 2
class Solution {
public:
    string intToRoman(int num) {
        string rome[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        int ints[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        string ans = "";
        for(int i = 0; i < 13 && num > 0; i++) {
            int j = num / ints[i];
            for(int k = 0; k < j; k++) ans += rome[i];
            num = num - j * ints[i];
        }
        return ans;
    }
};
