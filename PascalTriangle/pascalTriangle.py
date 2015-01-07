class Solution:
    # @return a list of lists of integers
    def generate(self, numRows):
        retList = [[1], [1,1]]
        if numRows < 3:
            return retList[:numRows -1]

        for k in xrange(3, numRows + 1):
            tmpList=[1]
            for j in xrange(1, k -1):
                prev = retList[k-2]
                tmpList.append(prev[j-1] + prev[j])
            tmpList.append(1)
            retList.append(tmpList)

        return retList


if __name__ == '__main__':
    sl = Solution()
    print sl.generate(5)
