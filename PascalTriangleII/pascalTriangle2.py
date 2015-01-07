#!/usr/bin/env python # encoding: utf-8


class Solution:
    # @return a list of integers
    def getRow(self, rowIndex):
        if rowIndex < 0:
            return []
        elif rowIndex == 0:
            return [1]

        retList = [1]
        odd = False
        if rowIndex % 2 == 0:
            odd = True
        stop = rowIndex / 2 + 1

        for k in xrange(1, stop):
            retList.append(retList[-1] * (rowIndex + 1 -k) / k);

        if odd:
            retList += retList[-2::-1]
        else:
            retList += retList[::-1]

        return retList


def test():
    sl = Solution()
    print sl.getRow(0)
    print sl.getRow(1)
    print sl.getRow(4)
    print sl.getRow(5)

if __name__ == '__main__':
    test()

