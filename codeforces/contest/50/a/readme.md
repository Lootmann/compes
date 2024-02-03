# A. Domino piling

> You are given a rectangular board of M × N squares.

M x N のgrid

> Also you are given an unlimited number of standard domino pieces of 2 × 1 squares.

2 x 1 のピースが無限にある

> You are allowed to rotate the pieces.

ピースは回転しても良い

> You are asked to place as many dominoes as possible on the board so as to meet the following conditions:
>
> 1. Each domino completely covers two squares.
> 2. No two dominoes overlap.
> 3. Each domino lies entirely inside the board. It is allowed to touch the edges of the board.

限界までボードにピースをおいていく

1. 各ピースは2つのマスを完全に埋める
2. ドミノがかぶってはいけない
3. はみ出てはいけない

Find the maximum number of dominoes, which can be placed under these restrictions.

# Input

In a single line you are given two integers M and N — board sizes in squares (1 ≤ M ≤ N ≤ 16).

# Output

Output one number — the maximal number of dominoes, which can be placed.
