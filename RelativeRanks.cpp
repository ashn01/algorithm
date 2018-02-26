//https://leetcode.com/problems/relative-ranks/description/
//Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
//
//Example 1:
//Input: [5, 4, 3, 2, 1]
//Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
//Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
//For the left two athletes, you just need to output their relative ranks according to their scores.
//Note:
//N is a positive integer and won't exceed 10,000.
//All the scores of athletes are guaranteed to be unique.
//
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int,int>> vt;
        vector<string> ret(nums.size());
        
        for(int i=0;i<nums.size();i++)
            vt.push_back(make_pair(nums[i],i));
        
        sort(vt.rbegin(),vt.rend());
        
        for(int i=0;i<nums.size();i++)
            if(i == 0)
                ret[vt[i].second] = "Gold Medal";
            else if(i==1)
                ret[vt[i].second] = "Silver Medal"; 
            else if(i==2)
                ret[vt[i].second] = "Bronze Medal"; 
            else
                ret[vt[i].second] = to_string(i+1);     
        
        return ret;
    }
};