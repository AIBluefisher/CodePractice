## 344. Reverse String

**Difficulty**: Easy

**Description**
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".

**分析**

有两种实现方法，一种是使用stl中的reverse(str.begin(), str.end());一种是设置两个指针，一个从头开始扫，一个从字符串末尾开始扫，交换这两个指针指向的字符。

**代码**

```C++
class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
};
```

```C++
class Solution {
public:
    string reverseString(string s) {
        if(s.empty()) return s;
        int i = 0;
        int j = s.length() - 1;
        while(i < j) swap(s[i++], s[j--]);
        return s;
    }
};
```


## 14. Longest Common Prefix

**Difficulty**: Easy

**Description**

Write a function to find the longest common prefix string amongst an array of strings.

**分析**

求某几个字符串的最长公共前缀。暴力的方法，只要从头开始，一次比较当前索引下，各个字符串的字符是否相同即可。

**代码**

```C++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen = 0x7fffffff;
        for(int i = 0; i < strs.size(); i++) 
        {
            if(minLen > strs[i].length()) minLen = strs[i].length();
        }
        if(minLen == 0 || minLen == 0x7fffffff) return "";
        char* com = new char [minLen + 1];
        int i = 0;
        for(i = 0; i < minLen; i++)
        {
            char cur = strs[0][i];
            for(int k = 1; k < strs.size(); k++)
            {
                if(strs[k][i] != cur)
                {
                    com[i] = '\0';
                    string str = com;
                    return str;
                }
            }
            com[i] = cur;
        }
        com[i] = '\0';
        string str = com;
        return str;
    }
};
```


## 58. Length of Last Word

**Difficulty**: Easy

**Description**

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5


**分析**

求字符串最后一个单词的长度。可以从头开始扫，也可以从末尾开始扫。

**代码**

```C++
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ll = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != ' ') ll++;
            else if(s[i] == ' ' && i + 1 < s.length())
            {
                if(s[i + 1] != ' ') ll = 0;
            }
        }
        return ll;
    }
};
```

```C++
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0, tail = s.length() - 1;
        while(tail >= 0 && s[tail] == ' ') tail--;
        while(tail >= 0 && s[tail] != ' ') 
        {
            len++; 
            tail--;
        }
        return len;
    }
};
```

## 125. Valid Palindrome

**Difficulty**: Easy

**Description**

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.


**分析**

判断字符串是否回文，忽略大小写，不考虑非字母和数字的字符。只要设置两个指针分别从字符串的开始和最后扫描并比较是否相等即可。

**代码**

```C++
class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int i = 0, j = s.length() - 1;
        while(i < j)
        {
            if(!::isalnum(s[i])) i++;
            else if(!::isalnum(s[j])) j--;
            else if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
};
```

## 38. Count and Say

**Difficulty**: Easy

**Description**

The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

**分析**

题目描述具有一定误导性，不过仔细看数字就能推出结果，nthString = countAndSay((n-1)thString)。也就是说，第n个字符串是通过数第n-1个字符串的得来的。这样理解的话就很容易了。

**代码**

```C++
class Solution {
public:
    string countAndSay(int n) {
        string result;
        string preStr = "1";
        while(--n)
        {
            int num  = 1;
            for(int i = 0; i < preStr.length(); i++)
            {
                if(i + 1 == preStr.length())
                {
                    result.push_back(num + '0');
                    result.push_back(preStr[i]);
                }
                else
                {
                    if(preStr[i] == preStr[i + 1]) num++;
                    if(preStr[i] != preStr[i + 1])
                    {
                        result.push_back(num + '0');
                        result.push_back(preStr[i]);
                        num = 1;
                    }
                }
            }
            preStr.assign(result);
            result.clear();
        }
        return preStr;
    }
};
```

## 551. Student Attendance Record I

**Difficulty**: Easy

**Description**

You are given a string representing an attendance record for a student. The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False

**分析**

注意题目描述：不是两个L，而是两个连续的L，在这里WA了好几次T_T。

**代码**

```C++
class Solution {
public:
    bool checkRecord(string s) {
        int aNum = 0, lNum = 0;
        int left = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'A') aNum++;
            if(i + 1 < s.length())
            {
                if(s[i] == 'L' && s[i + 1] == 'L') lNum++;
                else lNum = 0;
            }
            if(aNum > 1 || lNum > 1) return false;
        }
        
        return true;
    }
};
```