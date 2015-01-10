class Solution:
    # @param s, a string
    # @return an integer
    def lengthOfLastWord(self, s):
        s = s.rstrip()
        length = len(s)
        if length == 0:
            return 0

        index = s.rfind(' ');
        if index == -1:
            return length

        return length - index -1


if __name__ == '__main__':
    sl = Solution()
    print sl.lengthOfLastWord("a ")
