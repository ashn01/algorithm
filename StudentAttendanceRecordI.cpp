//https://leetcode.com/problems/student-attendance-record-i/description/
//You are given a string representing an attendance record for a student. The record only contains the following three characters:
//'A' : Absent.
//'L' : Late.
//'P' : Present.
//A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).
//
//You need to return whether the student could be rewarded according to his attendance record.
//
//Example 1:
//Input: "PPALLP"
//Output: True
//Example 2:
//Input: "PPALLL"
//Output: False
//
class Solution {
public:
    bool checkRecord(string s) {
        int ab=0;
        pair<int,int> late(0,0);
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == 'A')
            {
                ab++;
                if(ab == 2)
                    return false;
            }
            else if(s[i] == 'L')
                if(late.first == i-1)
                {
                    late.first = i;
                    late.second++;
                    if(late.second == 3)
                        return false;
                }
                else
                {
                    late.first = i;
                    late.second = 1;
                }
        }
        return true;
    }
};
