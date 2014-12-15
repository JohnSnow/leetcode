#include <iostream>
#include <cstring>

class Solution {
public:

/*    // simple one*/
    //int strStr(char *haystack, char *needle) {

        //register const size_t len = strlen(needle);
        //register const size_t hay_len = strlen(haystack);
        //if (len == 0 ) {
            //return 0;
        //}

        //char *s = haystack;
        //while( *s != *needle || strncmp(s, needle, len)) {
            //if(*s++ == '\0') {
                //return -1;
            //}
        //}
        //return (s - haystack);
    /*}*/

    // KMP
    int strStr(char *haystack, char *needle) {
        int n = strlen(haystack);
        int m = strlen(needle);

        if (m == 0) {
            return 0;
        }

        int q = 0;
        int *pi = prefix_funtion(needle, m);

        for (int i =0; i < n; i++) {
            while(q > 0 && needle[q] != haystack[i]) {
                q = pi[q - 1];
            }
            if(needle[q] == haystack[i]) {
                q++;
            }
            if(q == m) {
                return (i - m + 1);
            }
        }
        return -1;
    }

    // return prefix function
    int *prefix_funtion(char* Pat, int m) {
        int *pi = new int[m];
        bzero(pi, m*sizeof(int));

        int k = 0;
        for (int i = 1; i <m; i++)
        {
            while(k > 0 && Pat[k] != Pat[i]) {
                k = pi[k - 1];
            }
            if (Pat[k] == Pat[i]) {
                k++;
            }
            pi[i] = k;
        }
        return pi;
    }
};


int main(int argc, const char *argv[])
{
    char *haystack = "bbaa";
    char *needle = "bbb";

    Solution *sl = new Solution();
    std::cout << sl->strStr(haystack, needle) << std::endl;
    return 0;
}
