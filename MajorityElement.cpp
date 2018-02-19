//https://leetcode.com/problems/majority-element/description/
//Given an array of size n, find the majority element. The majority element is the element that appears more than [n/2] times.
//
//You may assume that the array is non-empty and the majority element always exist in the array.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        for(auto& a : nums)
            mp[a]++;
        for(auto& a : mp)
            if(a.second > nums.size()/2)
                return a.first;
    }
};