#include <string>
#include <iostream>

using std::string;

class Solution {
public:
    string convert(string s, int nRows) {
        if(s.empty() || s == "") return string("");
        if (nRows == 1) return s;

        unsigned  size = 2 * nRows - 2;

        string ret;
        for(int i = 0; i < nRows; i++)
        {
            for(unsigned j = i;  j<  s.length(); j +=size)
            {
                ret.append(s, j, 1);
                if (i!=0 && i!=nRows -1 && j + 2*(nRows - i - 1) < s.length())
                {
                    ret.append(s, j + 2*(nRows - i -1), 1);
                }
            }
        }
        return ret;
    }
};


int main(int argc, char *argv[])
{
    string s("PAYPALISHIRING");
    Solution *sl = new Solution();
    std::cout << sl->convert(s,4) << std::endl;
    return 0;
}
