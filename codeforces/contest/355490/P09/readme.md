# P9. Phone Number

Let's call a string a phone number if it has length 11 and fits the pattern "8xxxxxxxxxx",

> 長さ11 で '8xxxxxxxxxx' というパターンの文字列なら電話番号と呼びます

where each "x" is replaced by a digit.

For example, "80123456789" and "80000000000" are phone numbers,

while "8012345678" and "79000000000" are not.

You have n cards with digits,
and you want to use them to make as many phone numbers as possible.

Each card must be used in at most one phone number,
and you don't have to use all cards.

The phone numbers do not necessarily have to be distinct.

# Input

The first line contains an integer `n`
— the number of cards with digits that you have (1≤n≤100).

The second line contains a string of `n` digits
(characters "0", "1", ..., "9") s1,s2,…,sn .

The string will not contain any other characters, such as leading or trailing spaces.

# Output

If at least one phone number can be made from these cards,
output the maximum number of phone numbers that can be made.

Otherwise, output 0.
