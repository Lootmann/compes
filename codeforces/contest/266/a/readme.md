# A. Stones on the Table

> There are n stones on the table in a row,
> each of them can be red, green or blue.

n 個の石が一列に並んでいる　赤と緑と青です

> Count the minimum number of stones to take from the table
> so that any two neighboring stones had different colors.

テーブルから最小の石を取る数をカウントします
両隣の石の色が違うものの場合

> Stones in a row are considered neighboring
> if there are no other stones between them.

すべての石は両隣にピッタリくっついていると思え

# Input

The first line contains integer n (1 ≤ n ≤ 50) - the number of stones on the table.
The next line contains string s, which represents the colors of the stones.
We'll consider the stones in the row numbered from 1 to n from left to right.

Then the i-th character s equals "R",
if the i-th stone is red, "G", if it's green and "B", if it's blue.

# Output

Print a single integer — the answer to the problem.
