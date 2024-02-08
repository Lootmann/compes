# D. Double Strings

> You are given n strings s1,s2,…,sn of length at most 8 .

最大で長さ8の文字列が与えられる

> For each string s_i,
> determine if there exist two strings s_j and s_k such that s_i = s_j + s_k.
> That is, s_i is the concatenation of s_j and s_k.

各文字列 s_iについて
s_i について s_j + s_k という2つの文字列があるかどうか

> Note that j can be equal to k.

j == k は同じ可能性があります

> Recall that the concatenation of strings s and t
> is s + t = s1 s2 ... sp t1 t2 ... tq,
> where p and q are the lengths of strings s and t respectively.

s と t をくっつけて s1s2...t1t2... == p

> For example, concatenation of "code" and "forces" is "codeforces".

code forces となります
