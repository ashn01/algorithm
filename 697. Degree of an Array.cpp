/*
Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6
Note:

nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.

49 ms 46.79 %
*/

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> mp; // value = cnt, first, length
        int ret=INT_MAX;
        int b=0;
        for(int i =0 ; i <nums.size();i++)
        {
            auto& t = mp[nums[i]];
            if(t.size() == 0)
            {
                t.push_back(1);
                t.push_back(i);
            }
            else
                t[0]++;
            if((b== t[0] && ret > i - t[1]) || b < t[0])
            {
                b = t[0];
                ret = i - t[1];
            }
        }
        
        return ret+1;
    }
};