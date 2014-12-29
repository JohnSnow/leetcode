#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    int compareVersion(string version1, string version2) {

        int i1 = version1.find('.');
        int i2 = version2.find('.');

        int v1_major, v2_major;
        v1_major = v2_major = 0;

        if (i1 == -1)
        {
            v1_major = std::stoi(version1);
        }else {
            v1_major = std::stoi(version1.substr(0, i1));
        }

        if(i2 == -1)
        {
            v2_major = std::stoi(version2);
        }
        else
        {
            v2_major = std::stoi(version2.substr(0, i2));
        }


        if(v1_major > v2_major) {
            return 1;
        }
        else if (v1_major < v2_major) {
            return -1;
        }
        else {
            if(i1 == -1 && i2 == -1) {
                return 0;
            }
            else if(i1 == -1) {
                i1 = version1.length();
                version1 += ".0";
            }
            else if(i2 == -1) {
                i2 = version2.length();
                version2 += ".0";
            }
            return compareVersion(version1.substr(i1+1), version2.substr(i2+1));
        }
    }
};


int main(int argc, char *argv[])
{
    Solution *sl = new Solution();
    std::cout << sl->compareVersion(std::string("1"), std::string("1.0.1")) << std::endl;
    return 0;
}
