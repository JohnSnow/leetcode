#!/usr/bin/env python


class Solution:
    # @param A, a list of integers
    # @return an integer

    # divide and conquer
    def maxSubArray(self, A):
        if len(A) == 1:
            return A[0]

        mid = len(A)/2
        left = A[:mid]
        right = A[mid:]

        max_left = self.maxSubArray(left)
        max_right = self.maxSubArray(right)
        max_border = self.maxSum(reversed(left)) + self.maxSum(right)

        return max(max_left, max_right, max_border)

    def maxSum(self, arrayB):
        """docstring for maxSum"""
        n_max = float('-inf')
        n_sum = 0
        for item in arrayB:
            n_sum += item
            if n_sum > n_max:
                n_max = n_sum
        return n_max


def test():
    """docstring for test"""

    iList = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    sol = Solution()
    print sol.maxSubArray(iList)


if __name__ == '__main__':
    test()
