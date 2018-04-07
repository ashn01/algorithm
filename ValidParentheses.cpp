//https://leetcode.com/problems/valid-parentheses/description/
//Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto a : s)
        {
            if(st.empty())
            {
                st.push(a);
                continue;
            }
            char c = st.top();
            if(c+1 == a || c+2 == a)
                st.pop();
            else
                st.push(a);
        }
        return st.empty();
    }
};
