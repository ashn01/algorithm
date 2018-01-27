/* https://leetcode.com/problems/judge-route-circle/description/
Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.
 *
 * The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.
 * 
 * Example 1:
 * Input: "UD"
 * Output: true
 * Example 2:
 * Input: "LL"
 * Output: false
 */

class Solution {
public:
    bool judgeCircle(string moves) {
        int ret[] = {0,0};
        for(int i=0;i<moves.length();i++)
        {
            switch(moves[i])
            {
                case 'U' :
                    ret[0]++;
                    break;
                case 'D' : 
                    ret[0]--;
                    break;
                case 'L' :
                    ret[1]++;
                    break;
                case 'R' :
                    ret[1]--;
                    break;
            }
        }
        
        return ret[0] == 0 && ret[1] == 0 ? true : false;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string moves = stringToString(line);
        
        bool ret = Solution().judgeCircle(moves);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
