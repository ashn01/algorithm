/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

24 ms 66.71 % 
*/

class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var dic:Dictionary<Int,Int> = [:]
        
        for i in 0..<nums.count
        {
            if dic.keys.contains(nums[i]){
                return [dic[nums[i]]!, i]
            }else{
                dic[target - nums[i]] = i
            }
        }
        
        return [0]
    }
}