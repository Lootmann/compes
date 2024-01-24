# Cashier

Vasya has recently got a job as a cashier at a local store. His day at work is `L` minutes long.

> 全体でL分

Vasya has already memorized `n` regular customers,

> n 人のよく来る客

the i-th of which comes after `ti` minutes after the beginning of the day, and his service consumes `li` minutes.

> ti 分あとに来る li時間消費する

It is guaranteed that no customer will arrive while Vasya is servicing another customer.

Vasya is a bit lazy, so he likes taking smoke breaks for `a` minutes each.

> a分 タバコ休憩したい

Those breaks may go one after another,

but Vasya must be present at work during all the time periods he must serve regular customers,
otherwise one of them may alert his boss.

What is the maximum number of breaks Vasya can take during the day?

> 最大で何分休めるか？

# Input

The first line contains three integers `n` , `L` and `a` (0≤n≤105, 1≤L≤109, 1≤a≤L).

The i-th of the next `n` lines contains two integers `ti` and `li` (0≤ti≤L−1, 1≤li≤L).

It is guaranteed that `ti`+`li` ≤ `ti+1` and `tn`+`ln` ≤ `L`.

# Output

Output one integer — the maximum number of breaks.
