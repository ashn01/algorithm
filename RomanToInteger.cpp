//https://leetcode.com/problems/roman-to-integer/description/
//Given a roman numeral, convert it to an integer.
//
//Input is guaranteed to be within the range from 1 to 3999.

static int x=[](){
    // toggle off cout & cin, instead, use printf & scanf
    std::ios::sync_with_stdio(false);
    // untie cin & cout
    cin.tie(NULL);
    return 0;
}();

class Solution {
    
public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int ret=0;
        
        for(int i=0;i<s.length();i++)
        {
            switch(mp.find(s[i])->first)
            {
                case 'I' :
                    ret += (s[i+1] == 'V') || (s[i+1] == 'X') ? -1 : 1;
                    break;
                case 'X' :
                    ret += (s[i+1] == 'L') || (s[i+1] == 'C') ? -10 : 10;
                    break;
                case 'C' :
                    ret += (s[i+1] == 'D') || (s[i+1] == 'M') ? -100 : 100;
                    break;
                default :
                    ret += mp.find(s[i])->second;
            }
        }
        return ret;       
    }
};