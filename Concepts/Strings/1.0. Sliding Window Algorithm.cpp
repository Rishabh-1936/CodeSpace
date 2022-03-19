1.  This algorithm has a fixed size window whose size is generally the size of the solution.

2.  The Sliding Window Algorithm is primarily used for the problems dealing with linear data structures like Arrays, Lists, Strings etc.

3.  These problems can easily be solved using Brute Force techniques which result in quadratic or exponential time complexity. 

4.  Sliding window technique reduces the required time to linear O (n).

5.  Generally speaking a sliding window is a sub-list that runs over an underlying collection. i.e., if you have an array like

[a b c d e f g h]
a sliding window of size 3 would run over it like

[a b c]
  [b c d]
    [c d e]
      [d e f]
        [e f g]
          [f g h]
This is useful if you for instance want to compute a running average, or if you want to create a set of all adjacent pairs etc.
