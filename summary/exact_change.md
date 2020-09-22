[_metadata_:tags]:- "Kattis dynamic_programming medium"

# [Exact Change](https://open.kattis.com/problems/exactchange2)

---

## Problem Description
> Given a cost of and various 'coins' of various values, determine the minimum you will have to pay to equal or exceed the cost and the number of coins necessary to achieve such.

### Example
#### Input
First line: `T` number of testcases

For each test case:
* An integer `c` representing the cost
* An integer `n` representing the number of coins
* Next `n` lines
  * An integer representing the value of the ith coin
```
1
1400
3
500
1000
2000
```
#### Output
```
1500 2
```

## [Solution](%PUBLIC_URL%/solutions/exact_change.cpp)
This is an example of the classic coin change problem. This is a well known dynamic programming problem that can be approached with either a bottom-up or top-down strategy. For each available coin attempt to add it to a running list of sums (which can be memoized) and determine the minimum.

### Analysis
Each coin must be iterated through $O(n)$ and for every coin one pass must be made through the array $O(c)$. Thus, the final solution is $O(nc)$