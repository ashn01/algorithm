/* https://leetcode.com/problems/hamming-distance/description/
 * The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 *
 * Given two integers x and y, calculate the Hamming distance.
 *
 * Note:
 * 0 ¡Â x, y < 231.
 *
 * Example:
 *
 * Input: x = 1, y = 4
 *
 * Output: 2
 *
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 *       ¡è   ¡è
 *
 * The above arrows point to positions where the corresponding bits are different.
 */


// make both number binary and check if there is different number at the same position. So xor operator is used.
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ret = x ^ y; 
        int cnt = 0;
        
        while(ret!=0) // this loop counting if there is 1 in binary number. if so, cnt += 1;
        {
            if(ret%2 == 1)
            {
                cnt++;
            }
            ret/=2;         
        }        
        return cnt;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);
        getline(cin, line);
        int y = stringToInteger(line);
        
        int ret = Solution().hammingDistance(x, y);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}