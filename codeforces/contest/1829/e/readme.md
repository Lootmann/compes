# E. The Lakes

You are given an n×m grid a of non-negative integers.
The value ai,j represents the depth of water at the i-th row and j-th column.

A lake is a set of cells such that:

- each cell in the set has a{i,j} > 0, and

- there exists a path between any pair of cells in the lake
  by going up, down, left, or right a number of times
  and without stepping on a cell with ai,j=0

The volume of a lake is the sum of depths of all the cells in the lake.

Find the largest volume of a lake in the grid.
