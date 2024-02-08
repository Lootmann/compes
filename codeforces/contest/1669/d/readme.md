# D. Colorful Stamp

> A row of n cells is given, all initially white.

N個のセルが与えられる　最初は全部White 'W'

> Using a stamp,
> you can stamp any two neighboring cells
> such that one becomes red and the other becomes blue.
>
> A stamp can be rotated,
> i.e. it can be used in both ways: as BR and as RB .

スタンプを使うことで
すべての隣接するセルを 片方赤に、もう片方を青にできる

> During use,
> the stamp must completely fit on the given n cells
> (it cannot be partially outside the cells).

RBのセル片方はみだすとかはだめ
最後のセルに WWW -> RBRBR(B)

> The stamp can be applied multiple times to the same cell.
> Each usage of the stamp recolors both cells that are under the stamp.

同じセルを何度も押すのはOK

> For example,
> one possible sequence of stamps to make the picture BRBBW could be
> Here W, R, and B represent a white, red, or blue cell, respectively.

```
WWWWW → WWRBW → BRRBW → BRBBW.
```

こんな感じでスタンプ押せるよ

> Given a final picture,
> is it possible to make it using the stamp zero or more times?

最終結果が与えられるので、
initial状態からこのスタンプにできるかどうか判定してね
スタンプは0回以上押すものとする
