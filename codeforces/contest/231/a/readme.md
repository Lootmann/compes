> One day three best friends Petya, Vasya and Tonya
> decided to form a team and take part in programming contests.

三人でチームを組んだ

> Participants are usually offered several problems during programming contests.

参加者は いくつか問題が提供される

> Long before the start the friends decided that they will implement a problem
> if at least two of them are sure about the solution.

コンテストの前に、以下の条件で回答の実装をすることにした
少なくとも二人以上が回答を出せたら

> Otherwise, the friends won't write the problem's solution.

そうでなければ回答は出力できない

> This contest offers n problems to the participants.

n 問ある

For each problem we know,

which friend is sure about the solution.

Help the friends find the number of problems for which they will write a solution.

# Input

> The first input line contains a single integer n (1 ≤ n ≤ 1000)
> — the number of problems in the contest.

問題数がN

Then n lines contain three integers each,

each integer is either 0 or 1.

If the first number in the line equals 1,
then Petya is sure about the problem's solution, otherwise he isn't sure.

The second number shows Vasya's view on the solution,
the third number shows Tonya's view.
The numbers on the lines are separated by spaces.

# Output

Print a single integer — the number of problems the friends will implement on the contest.
