#!/usr/bin/env python


class Solution:
    ''' sulotion for two sum problem'''
    # @return a tuple, (index1, index2)

    def twoSum(self, num, target):

        index1 = 0
        index2 = 0
        newDict = {}
        for idx in xrange(0, len(num)):
            if num[idx] not in newDict:
                newDict[num[idx]] = [idx + 1]
            else:
                newDict[num[idx]].append(idx+1)

        for key in newDict:
            index1 = newDict[key][0]
            remain = target - key
            if remain in newDict:
                index2 = newDict[remain][0] \
                    if remain != key else newDict[remain][1]
                break

        if index1 > index2:
            index1, index2 = index2, index1
        return (index1, index2)


if __name__ == '__main__':
    sol = Solution()
    num = [2, 7, 11, 15]
    target = 9
    ret = sol.twoSum(num, target)
    print ret
