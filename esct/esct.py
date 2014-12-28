#!/bin/env python


class Solution:
    # @return a string
    def convertToTitle(self, num):
        s = ''
        while num:
            t = num % 26
            if t == 0:
                t = 26
            s = str(unichr(t + 64)) + s
            num = (num - t) / 26
        return s


if __name__ == '__main__':
    sl = Solution()
    print sl.convertToTitle(26)
    print sl.convertToTitle(27)
