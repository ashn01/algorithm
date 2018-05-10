/*
Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: True
Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: False
Note:
The input array won't violate no-adjacent-flowers rule.
The input array size is in the range of [1, 20000].
n is a non-negative integer which won't exceed the input array size.

36 ms 61.54%
*/

class Solution {
    func canPlaceFlowers(_ flowerbed: [Int], _ n: Int) -> Bool {
        var zeroCnt:Int = 1
        var remains:Int = n
        for i in flowerbed
        {
            if i == 0
            {
                zeroCnt += 1
            }
            else
            {
                remains -= (zeroCnt-1)/2
                zeroCnt = 0
            }
        }
        
        remains -= (zeroCnt)/2
        
        return remains <= 0
    }
}