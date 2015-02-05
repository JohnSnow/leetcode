#include <string>
#include <iostream>
using std::string;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        if(s.length() == 1) return s;

        int n = s.length();
        int TN = 2 *n +3;
        char* T = preProcess(s, TN);

        int *P = new int[TN];

        int C = 0, R=0;

        for(int i = 1; i< TN-1; i++) {
            int i_mirror = 2 * C - i;

            P[i] = R > i? std::min(R-i, P[i_mirror]):0;

            while(T[i+1 + P[i]] == T[i-1-P[i]]) {
                P[i]++;
            }

            if(i+P[i] > R) {
                C = i;
                R = i+P[i];
            }
        }

        int maxLen = 0;
        int centerIdx = 0;
        for(int i=1; i<TN-1; i++) {
            if(P[i] > maxLen) {
                maxLen = P[i];
                centerIdx = i;
            }
        }
        delete[] P;
        delete[] T;
        return s.substr((centerIdx-maxLen-1)/2, maxLen);
    }


    char *preProcess(string s, int N) {

        int n = s.length();
        char *T = new char[N];
        T[0] = '^';
        int j = 1;
        for(int i=0; i<n; i++) {
            T[j++] = '#';
            T[j++] = s[i];
        }
        T[j++] = '#'; T[j++]='$';
        return T;
    }
};

int main(int argc, char *argv[])
{
    Solution *sl = new Solution();
    std::cout<< sl->longestPalindrome(string("ccc")) << std::endl;
    std::cout<< sl->longestPalindrome(string("bb")) << std::endl;

    std::cout<< sl->longestPalindrome(string("abb")) << std::endl;
    std::cout<< sl->longestPalindrome(string("")) << std::endl;

    return 0;
}
