[_metadata_:tags]:- "CodeForces binary_search medium"

# [Binary Median](https://codeforces.com/contest/1360/problem/H)

---

## Problem Description
> Assuming there is a set of $2^m$ binary strings each of length $m$, and given $n$ binary strings to remove, determine what the medians string is.

### Example
#### Input
First line: `t` which is the number of test cases

For each test case: First line: `n` `m`

Next `n` lines: a binary string of length `m` that is to be removed
```
5
3 3
010
001
111
4 3
000
111
100
011
1 1
1
1 1
0
3 2
00
01
10
```
#### Output
```
100
010
0
1
11
```

## [Solution](%PUBLIC_URL%/solutions/binary_median.cpp)
Given that it is known how many strings there are after removal it is known where the median is after the remaining binary strings are sorted. To determine this a `binary search` can be performed on all $2^m$ sorted binary strings where, for each check, it can be determined how many strings were removed to the left and to the right of the guess. Thus, it can be checked if the correct index was found.

### Analysis
The binary search is done over all possible binary strings $(2^m)$ and each check can be performed in $O(1)$. Thus, the binary search is $O(log(2^m))=O(m)$. Setup and initialization for the problem, on the otherhand, requires $O(n*m)$ time