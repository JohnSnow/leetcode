#!/usr/bin/env python
# encoding: utf-8

import re

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

MAP={
        "MMM"   : 3000,
        "MM"    : 2000,
        "M"     : 1000,
        "CM"    : 900,
        "CD"    : 400,
        "DCCC"  : 800,
        "DCC"   : 700,
        "DC"    : 600,
        "D"     : 500,
        "CCC"   : 300,
        "CC"    : 200,
        "C"     : 100,
        "XC"    : 90,
        "XL"    : 40,
        "LXXX"  : 80,
        "LXX"   : 70,
        "LX"    : 60,
        "L"     : 50,
        "XXX"   : 30,
        "XX"    : 20,
        "X"     : 10,
        "IX"    : 9,
        "IV"    : 4,
        "V"     : 5,
        "VIII"  : 8,
        "VII"   : 7,
        "VI"    : 6,
        "III"   : 3,
        "II"    : 2,
        "I"     : 1
    }

class Solution:

    # @return an integer
    def romanToInt(self, s):
        if not s:
            return 0

        integer = 0
        m = re.search(ROMAN_REG, s, re.X)

        for mm in m.groups():
            if mm:
                integer += MAP[mm]

        return integer


def test():
    sl = Solution()
    print sl.romanToInt("MCDXXXVII")


if __name__ == '__main__':
    test()
