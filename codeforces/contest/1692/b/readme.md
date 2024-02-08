# B. All Distinct

> Sho has an array a consisting of n integers.

n整数の配列

> An operation consists of choosing two distinct indices i and j
> and removing ai and aj from the array.

2つのi, j を選び ai, aj を削除します

> For example,
> for the array [2,3,4,2,5],
> Sho can choose to remove indices 1 and 3.

[2,3,4,2,5] で 1, 3 を削除すると

> After this operation, the array becomes [3,2,5].

[3,2,5] になります

> Note that after any operation,
> the length of the array is reduced by two.

どの操作のあとも Arrayは2つ減ります

> After he made some operations,
> Sho has an array that has only distinct elements.

いくつかの操作を行った後には
Arrayの中身がユニークな要素だけになってます

> In addition,
> he made operations such that the resulting array is the longest possible.

可能な限り配列は長くあってほしいです

More formally,
the array after Sho has made his operations respects these criteria:

- No pairs such that (i`<`j) and ai=aj exist.
- The length of a is maximized.

Output the length of the final array.
