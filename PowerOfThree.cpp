//https://leetcode.com/problems/power-of-three/description/
//Given an integer, write a function to determine if it is a power of three.
//
//Follow up:
//Could you do it without using any loop / recursion?

static string opt =[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return "";
}();


class Solution {
public:
    bool isPowerOfThree(int n) {
        double temp = log10(n) / log10(3);
        return !(temp - (int)temp);
    }
};
