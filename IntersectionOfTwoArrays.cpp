//https://leetcode.com/problems/intersection-of-two-arrays/description/
//Given two arrays, write a function to compute their intersection.
//
//Example:
//Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
//
//Note:
//Each element in the result must be unique.
//The result can be in any order.

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        map<int, int> mp;
        for(auto& a: nums1)
            mp.insert(pair<int,int>(a,1));
        
        for(auto& a : nums2)
            if(mp[a])
            {
                ret.push_back(a);
                mp[a] = 0;
            }
        
        return ret;
    }
};