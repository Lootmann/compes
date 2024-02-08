# C. Most Similar Words

You are given n words of equal length m,
consisting of lowercase Latin alphabet letters.
The i-th word is denoted s_i.

In one move
you can choose any position in any single word
and change the letter at that position to the previous or next letter
in alphabetical order.

For example:

- you can change 'e' to 'd' or to 'f';
- 'a' can only be changed to 'b';
- 'z' can only be changed to 'y'.

The difference between two words is the minimum number of moves required
to make them equal.

For example,
the difference between "best" and "cost" is 1+10+0+0=11.

Find the minimum difference of si and sj
such that (i`<`j).

In other words,
find the minimum difference over all possible pairs of the n words.
