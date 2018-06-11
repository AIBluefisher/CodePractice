
## 20. Valid Parentheses

**Difficulty**: Easy

**Description**

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

**分析**

使用栈很简单。遇到左括号进栈，遇到右括号时进行判断，若栈顶括号和此时需入栈的括号配对，则将栈顶括号出栈，若不配对，就是一个错误的字符串。

**代码**

```C++
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
            else
            {
                if(st.empty()) return false;
                char tmp = st.top();
                if((tmp == '(' && s[i] == ')') || (tmp == '[' && s[i] == ']') || (tmp == '{' && s[i] == '}')) st.pop();
                else 
                    return false;
            }
        }
        if(st.size() == 0) return true;
        else 
            return false;
    }
};
```