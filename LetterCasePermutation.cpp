//https://leetcode.com/problems/letter-case-permutation/description/
//Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.
//
//Examples:
//Input: S = "a1b2"
//Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
//
//Input: S = "3z4"
//Output: ["3z4", "3Z4"]
//
//Input: S = "12345"
//Output: ["12345"]
//Note:
//
//S will be a string with length at most 12.
//S will consist only of letters or digits.

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ret(1,S);
        vector<int> index;
        for(int i=0;i<S.length();i++)
            if((S[i] >= 'A' && S[i] <= 'Z') || (S[i] >= 'a' && S[i] <= 'z'))
                index.push_back(i);
        
        for(auto& a : index)
            cout<< a << endl;
        
        add(ret,index);
        return ret;
    }
    
    void add(vector<string>& vt, vector<int>& idx)
    {
        if(idx.empty())
            return;
        int size = vt.size();
        for(int i=0;i<size;i++)
        {
            string s = vt[i];
            s[idx.front()] += s[idx.front()] >= 97 ? -32 : 32;
            vt.push_back(s);
        }
        idx.erase(idx.begin(),idx.begin()+1);
        add(vt,idx);
    }
    
};

