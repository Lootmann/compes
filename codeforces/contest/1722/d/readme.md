# D. Line

> There are n people in a horizontal line,
> each looking either to the left or the right.

n 人が一列に 左か右を向いている

> Each person counts the number of people in the direction they are looking.

どっちを向いているかをカウントする

> The value of the line is the sum of each person's count.

その列の「価値」の合計をカウントする

> For example,
> in the arrangement LRRLL,
> where L stands for a person looking left and R stands for a person looking right,

LRRLL では Lは左を向いている人で、Rは右を向いている

> the counts for each person are [0,3,2,3,4], and the value is 0+3+2+3+4=12 .

> You are given the initial arrangement of people in the line.

初期状態の列を受け取るので

> For each k from 1 to n,
> determine the maximum value of the line
> if you can change the direction of at most k people.

最大でK人の人の向いている方向をいじって
最大の価値を決定してください

## Input

The input consists of multiple test cases.
The first line contains an integer t (1≤t≤100)
— the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer n (1≤n≤2 x 10^5)
— the length of the line.

The following line contains a string consisting of n characters,
each of which is either L or R,
representing a person facing left or right, respectively — the description of the line.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅10^5.

Please note that the answer for some test cases won't fit into 32-bit integer type,
so you should use at least 64-bit integer type in your programming language (like long long for C++).

## Output

For each test case,
output n space-separated non-negative integers
— the maximum value of the line
if you can change the direction of at most k people for each k from 1 to n, inclusive.
