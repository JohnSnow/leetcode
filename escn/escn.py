#!/bin/env python


class Solution:
    # @param s, a string
    # @return an integer
    def titleToNumber(self, s):
        num = 0
        for c in s:
            num = 26 * num + ord(c.lower()) - 96
        return num

if __name__ == '__main__':
    sl = Solution()
    print sl.titleToNumber('AA')
