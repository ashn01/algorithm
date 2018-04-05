//https://leetcode.com/problems/count-and-say/description/
//The count-and-say sequence is the sequence of integers with the first five terms as following:
//
//1.     1
//2.     11
//3.     21
//4.     1211
//5.     111221
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//Given an integer n, generate the nth term of the count-and-say sequence.
//
//Note: Each term of the sequence of integers will be represented as a string.
//
//Example 1:
//
//Input: 1
//Output: "1"
//Example 2:
//
//Input: 4
//Output: "1211"

class Solution {
public:
    string countAndSay(int n) {
        string read="1", store="";
        pair<int,int> p(1,0);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<read.size();j++)
            {
                if(read[j]==p.first + '0')
                    p.second++;
                else
                {
                    store.push_back(p.second+'0');
                    store.push_back(p.first+'0');
                    p.second = 1;
                    p.first = read[j] -'0';
                }
            }
            store.push_back(p.second+'0');
            store.push_back(p.first+'0');
            read = store;
            store="";
            p.first=read[0]-'0';
            p.second =0;
        }
        
        return read;
    }
};
