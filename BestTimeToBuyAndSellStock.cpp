//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
//Say you have an array for which the ith element is the price of a given stock on day i.
//
//If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//
//Example 1:
//Input: [7, 1, 5, 3, 6, 4]
//Output: 5
//
//max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
//Example 2:
//Input: [7, 6, 4, 3, 1]
//Output: 0
//
//In this case, no transaction is done, i.e. max profit = 0.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<pair<int,int>> vt;
        int ret=0;
        int prev = INT_MAX;
        
        for(auto& a : prices)
        {
            vt.push_back(make_pair(a,0));
            if(prev < a)
                for(auto& r : vt)
                    if(r.second < a - r.first)
                        r.second = a - r.first;
            prev = a;
        }
        
        for_each(vt.begin(),vt.end(),[&](auto& val){
           if(ret < val.second)
               ret = val.second;
        });
        
        return ret;
    }
};
