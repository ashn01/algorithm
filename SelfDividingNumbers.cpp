/* https://leetcode.com/problems/self-dividing-numbers/description/
 * A self-dividing number is a number that is divisible by every digit it contains.
 *
 * For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
 *
 * Also, a self-dividing number is not allowed to contain the digit zero.
 *
 * Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.
 *
 * Example 1:
 * Input: 
 * left = 1, right = 22
 * Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
 * Note:
 *
 * The boundaries of each input argument are 1 <= left <= right <= 10000.
 */

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        for(int i=left; i <= right && i<=10000; i++)
        {
            int temp=i;
            if(i == 0)
                continue;
            switch((int)log10(i))
            {
                case 4:
                    if(temp-(temp/10000)*10000 < 1000 || i%(temp/10000) != 0)
                        break;
                    else
                        temp-=(temp/10000)*10000;
                case 3:
                    if(temp-(temp/1000)*1000 < 100 || i%(temp/1000) != 0)
                        break;
                    else
                        temp-=(temp/1000)*1000;
                case 2:
                    if(temp-(temp/100)*100 < 10 || i%(temp/100) != 0)
                        break;
                    else
                        temp-=(temp/100)*100;
                case 1:
                    if(temp-(temp/10)*10 < 1 || i%(temp/10) != 0)
                        break;
                    else
                        temp-=(temp/10)*10;
                case 0:
                    if(temp == 0 || i%temp != 0)
                        break;
                    else
                    {
                        ret.push_back(i);
                        break;
                    }
            }
        }
        return ret;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int left = stringToInteger(line);
        getline(cin, line);
        int right = stringToInteger(line);
        
        vector<int> ret = Solution().selfDividingNumbers(left, right);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}