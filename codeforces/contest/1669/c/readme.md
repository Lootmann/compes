# C. Odd/Even Increments

> Given an array a=[a1,a2,…,an] of n positive integers,

N個の正の整数配列が与えられます

> you can do operations of two types on it:

以下の操作を行うことができます

> - Add 1 to every element with an odd index.
>   In other words change the array as follows: a1:=a1+1,a3:=a3+1,a5:=a5+1,… .

すべての奇数Indexの要素に1を加えること

> - Add 1 to every element with an even index.
>   In other words change the array as follows: a2:=a2+1,a4:=a4+1,a6:=a6+1,… .

すべての偶数Indexの要素に1を加えること

> Determine if after any number of operations
> it is possible to make the final array
> only even numbers or only odd numbers.

最終的に配列内のすべての要素が奇数もしくは偶数である
ようにするために操作を行えるかどうか 決定しろ

In other words,

determine if you can make all elements of the array have the same parity
after any number of operations.

Note that you can do operations of both types any number of times (even none).

Operations of different types can be performed a different number of times.
