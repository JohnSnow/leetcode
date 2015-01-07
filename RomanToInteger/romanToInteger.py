#!/usr/bin/env python
# encoding: utf-8

ROMAN_REG = """
    ^                   # begging of string
    (M{0,3})              # thousands - 0 to 3 M's
    (CM|CD|D?C{0,3})    # hundreds - 900 (CM), 400 (CD), 0-300 (0 to 3 C's),
                        #            or 500-800 (D, followed by 0 to 3 C's)
    (XC|XL|L?X{0,3})    # tens - 90 (XC), 40 (XL), 0-30 (0 to 3 X's),
                        #        or 50-80 (L, followed by 0 to 3 X's)
    (IX|IV|V?I{0,3})    # ones - 9 (IX), 4 (IV), 0-3 (0 to 3 I's),
                        #        or 5-8 (V, followed by 0 to 3 I's)
    $                   # end of string

    """


class Solution:

    MAP={
        "M"     : 1000,
        "CM"    : 900,
        "CD"    : 400,
        "D"     : 500,
        "C"     : 100,
        "XC"    : 90,
        "XL"    : 40,
        "L"     : 50,
        "X"     : 10,
        "IX"    : 9,
        "IV"    : 4,
        "V"     : 5,
        "I"     : 1
    }

    LL = ['M', 'CM', 'CD', 'D', 'C', 'XC', 'XL', 'L', 'X', 'IX', 'IV', 'V', 'I']
    # @return an integer
    def romanToInt(self, s):
        if not s:
            return 0

        integer = 0
        length = len(s)
        i = 0
        done = False
        for RO in self.LL:
            if len(RO) == 1:
                cnt = 0
                while i < length and s[i] == RO and cnt < 4:
                    cnt += 1
                    i += 1
                integer += cnt * self.MAP[RO]
            elif s[i:i+2] == RO:
                i += 2
                integer += self.MAP[RO]

            if i == length:
                break

        return integer


def test():
    sl = Solution()
    print sl.romanToInt("MCDXXXVII")


if __name__ == '__main__':
    test()
