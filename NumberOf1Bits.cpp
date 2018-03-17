//https://leetcode.com/problems/number-of-1-bits/description/
//Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
//
//For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.


static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret=0;
        while(n > 0)
        {
            if(n%2)
                ret++;
            n/=2;
        }
        return ret;
    }
};
