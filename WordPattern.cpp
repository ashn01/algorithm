//https://leetcode.com/problems/word-pattern/description/
//Given a pattern and a string str, find if str follows the same pattern.
//
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
//
//Examples:
//pattern = "abba", str = "dog cat cat dog" should return true.
//pattern = "abba", str = "dog cat cat fish" should return false.
//pattern = "aaaa", str = "dog cat cat dog" should return false.
//pattern = "abba", str = "dog dog dog dog" should return false.
//Notes:
//You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream strcin(str);
        string s;
        vector<string> v;
        while(strcin >> s) v.push_back(s);
        if (pattern.size() != v.size()) return false;
        
        map<char,string> mc;
        map<string,char> ms;
        for(int i=0;i<pattern.length();i++)
        {   
            auto itc = mc.find(pattern[i]);
            auto its = ms.find(v[i]);
            if((itc != mc.end()) && (its != ms.end()))
            {
                if((itc->second).compare(v[i]) || its->second != pattern[i])
                    return false;
            }
            else if((itc != mc.end()) ^ (its != ms.end()))
                return false;
                
            mc.insert(make_pair(pattern[i],v[i]));
            ms.insert(make_pair(v[i],pattern[i]));
        }
        return true;
    }
};
