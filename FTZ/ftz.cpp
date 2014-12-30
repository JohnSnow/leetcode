class Solution {
public:
    int trailingZeroes(int n) {
        int num_5 = 0;

        while(n > 1)
        {
            int tmp = n / 5;
            num_5 += tmp;
            n = tmp;
        }

        return num_5;
    }

};

