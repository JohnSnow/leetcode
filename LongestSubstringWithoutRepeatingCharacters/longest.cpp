#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        std::vector<char> vec;
        int longest = 0;
        int len = 0;
        std::vector<char>::iterator it;;

        for(unsigned i=0; i < s.size(); i++) {
            it = std::find(vec.begin(), vec.end(), s[i]);
            if(it!=vec.end()) {
                if(len > longest) {
                    longest = len;
                }
                len -= it - vec.begin();
                vec.erase(vec.begin(), it + 1);
                vec.push_back(s[i]);
            }else{
                len++;
                vec.push_back(s[i]);
            }
            std::cout << "iter: " <<i << " " << s[i] << " current len: " << len << std::endl;
        }
        if(len > longest) longest = len;
        return longest;
    }
};

int main(int argc, char *argv[])
{
    string s("bpfbhmipx");
    Solution *sl = new Solution();
    std::cout << sl->lengthOfLongestSubstring(s) << std::endl;
    return 0;
}
