/* https://leetcode.com/problems/number-complement/description/
 * Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation. 
 *
 * Note:
 * The given integer is guaranteed to fit within the range of a 32-bit signed integer.
 * You could assume no leading zero bit in the integer¡¯s binary representation.
 * Example 1:
 * Input: 5
 * Output: 2
 * Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
 * Example 2:
 * Input: 1
 * Output: 0
 * Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output
 */

class Solution {
public:
    int findComplement(int num) {
        int ret = num;
        ret = ~num<<32-(int)(log2(num)+1);
        ret = ret >> 32-(int)(log2(num)+1);
        
        return ret;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);
        
        int ret = Solution().findComplement(num);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}