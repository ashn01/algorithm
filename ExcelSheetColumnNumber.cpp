//https://leetcode.com/problems/excel-sheet-column-number/description/
//Related to question Excel Sheet Column Title
//
//Given a column title as appear in an Excel sheet, return its corresponding column number.
//
//For example:
//
//    A -> 1
//    B -> 2
//    C -> 3
//    ...
//    Z -> 26
//    AA -> 27
//    AB -> 28 

class Solution {
public:
    int titleToNumber(string s) {
        int ret=0;
        for(auto& a : s)
            ret= ret*26 + (a-64);
        return ret;
    }
};