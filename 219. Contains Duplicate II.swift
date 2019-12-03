/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: [1,2,3,1], k = 3
Output: true
Example 2:

Input: [1,0,1,1], k = 1
Output: true
Example 3:

Input: [1,2,1], k = 0
Output: false

44 ms 95.55%
*/

class Solution {
    func containsNearbyDuplicate(_ nums: [Int], _ k: Int) -> Bool {
        var dc:Dictionary<Int,Int> = [:]
        
        for i in 0..<nums.count
        {
            if let exist = dc[nums[i]]
            {
                if i - exist > k
                {
                    dc[nums[i]] = i
                }
                else
                {
                    return true
                }
            }
            else
            {
                dc[nums[i]]=i
            }
        }
        return false
    }
}