//https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
//Given an array of integers where 1 ¡Â a[i] ¡Â n (n = size of array), some elements appear twice and others appear once.
//
//Find all the elements of [1, n] inclusive that do not appear in this array.
//
//Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
//
//Example:
//
//Input:
//[4,3,2,7,8,2,3,1]
//
//Output:
//[5,6]

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        if(nums.size() == 0)
            return nums;
        
        vector<int> ret(nums.size(),0);
        for(auto& a : nums)
            ret[a-1]++;
        
        int resize=0;
        for(int i=0;i<ret.size();i++)
            if(ret[i] == 0)
                ret[resize++]=i+1;
        
        ret.resize(resize);
                
        return ret;
    }
};