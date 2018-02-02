//https://leetcode.com/problems/subarray-sum-equals-k/description/
//Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
//
//Example 1:
//Input:nums = [1,1,1], k = 2
//Output: 2
//Note:
//The length of the array is in range [1, 20,000].
//The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        int sum = 0;
        int cnt = 0;
        m[sum]++; // if sum - k == 0, cnt++ ;
        
        for(auto& a : nums)
        {
            sum += a;
            cnt += m[sum-k]; // add key = sum - k, value = 1
            m[sum]++;  // add key = sum, value = 1
        }
        return cnt;
    }
};

/*
[1,2,3,4,5]  k=5

m = [[0,1]];

1 round :
    a = 1;
    sum = 1;
    cnt = m[-4];
    m = [[-4,1],[0,1],[1,1]]
    
2 round :
    a = 2;
    sum = 3;
    cnt = m[-2];
    m = [[-4,1],[-2,1],[0,1],[1,1],[3,1]];

3 round :
    a = 3;
    sum = 6;
    cnt = m[1]; => cnt = 1;
    m = [[-4,1],[-2,1],[0,1],[1,1],[3,1],[6,1]];
    
4 round :
    a = 4;
    sum = 10;
    cnt = m[5];
    m = [[-4,1],[-2,1],[0,1],[1,1],[3,1],[5,1],[6,1],[10,0]];
    
5 round :
    a = 5;
    sum = 15;
    cnt = m[10]; => cnt = 2;
    m = [[0,1],[1,1],[3,1],[6,1],[10,0],[15,0]];

loop end;
    return cnt;
*/