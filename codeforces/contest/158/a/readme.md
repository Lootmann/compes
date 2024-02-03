# A. Next Round

> "Contestant (who earns a score equal to or greater than the k-th place finisher's score)
> will advance to the next round,

競技者は、次のラウンドに進める
k-th place で競技を終了したやつのスコアより大きい、もしくはそれと同等のスコアをもらえたものは

> as long as the contestant earns a positive score..." — an excerpt from contest rules.

競技者が正の数スコアをもらえる限り

> A total of n participants took part in the contest (n ≥ k),
> and you already know their scores. Calculate how many participants will advance to the next round.

全部で N 人の競技者がいる コンテストに参加する

あなたはすでに彼らのスコアを全部知っているので
何人の参加者が次のラウンドに進める人間がいるのかを調べろ

# Input

> The first line of the input contains two integers n and k (1 ≤ k ≤ n ≤ 50) separated by a single space.

N K の2つの数字が与えられる

> The second line contains n space-separated integers a1, a2, ..., an (0 ≤ ai ≤ 100),
> where ai is the score earned by the participant who got the i-th place.

n 個の整数が与えられる
ai というのは i番目の競技者が獲得したスコアです

> The given sequence is non-increasing
> (that is, for all i from 1 to n - 1 the following condition is fulfilled: ai ≥ ai + 1).

ai は 減少増加数列

# Output

> Output the number of participants who advance to the next round.

何人が次のラウンドに行けるか数えてね
