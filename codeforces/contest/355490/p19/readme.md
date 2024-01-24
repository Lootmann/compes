# p19. mountain peaks

We want to hike mountains with N peaks, numbered from left to right from 0 to N−1.

> N この山のピークがある、0 -> N - 1 まで番号がつけられている

We will visit them in this order (first peak 0, then peak 1, and so on till peak N−1)
The height of peak i is Hi .

> 左から順番に

A peak `i` is challenging if its two adjacent peaks are lower.

> peak i を挑戦的であると定義します 両隣のピークが、i の高さより低かったら
> That is, `Hi−1<Hi` and `Hi+1<Hi` must be both true.

Please note that the first and the last peak (with numbers 0 and N−1 respectively) cannot be challenging.

> 最初と最後のピークはカウントされない

We want to split our trip into some number of days.

> 数日間に分ける

Each day we want to visit the same number of peaks.

> 前日程を通じて、同じピーク数に分割したい

A one-day hike is successful if we visited at least one challenging peak that day.

> チャレンジ具なピークは一日最低でも一箇所は登りたい

We want every day in our trip to be successful.

What is the maximum number of days that we can split our trip into?

> 最大で何日間に旅行を分割できるか

# Input

The first line contains a single integer N (1≤N≤100000), the number of peaks.

The next line contains N integers Hi (1≤Hi≤109), the heights of the peaks.

# Output

Output a single integer,
the maximum number of days that we can split our hike into.

If we cannot find any split into any number of days, then output 0.
