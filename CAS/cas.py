#!/usr/bin/env python
# encoding: utf-8

class Solution:
    # @return a string
    def countAndSay(self, n):
        str_li = ["0", "1", "11", "21", "1211"]
        if n < 1:
            return None

        if n < 5:
            return str_li[n]

        for idx in xrange(5, n + 1):
            curStr = ''
            preStr = str_li[idx - 1]
            pre = preStr[0]
            cnt = 1
            for c in preStr[1:]:
                if c==pre:
                    cnt += 1
                else:
                    curStr += str(cnt) + pre
                    pre = c
                    cnt = 1
            curStr += str(cnt) + pre
            str_li.append(curStr)
        return str_li[-1]


if __name__ == '__main__':

    sl = Solution();
    print sl.countAndSay(6);
