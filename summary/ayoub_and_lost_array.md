[_metadata_:tags]:- "CodeForces combinatorics dynamic_programming"

# [Ayoub and Lost Array](https://codeforces.com/contest/1105/problem/C)

---

## Problem Description
> Determine how many different arrays of size $N$ consisting only of letters between $l$ and $r$ inclusive would have a cumulative sum divisible by 3. Give the answer modulo $10^{9} + 7$.

### Example
#### Input
Input given in form: `n,l,r`
```
2 1 3
```
#### Output
```
3
```

## [Solution](%PUBLIC_URL%/solutions/ayoub_and_lost_array.cpp)
The first key observation to make is that, given you already have an array of size $k$ whose sum modulo $3$ is $m$, when another number is appended to the array, it will then have size $k+1$ and sum modulo $3$ either $0, 1, 2$. Thus, if it can be determined how many arrays of size $k$ have $sum\%3 = 0,1,2$, then it can also be determined how many arrays of size $k+1$ will have $sum\%3 = 0,1,2$. This intermediary step between $k$ and $k+1$ requires knowing how many numbers between $l$ and $r$ have modulo $3$ equal to $0,1,2$ respectively. Using an inital base case for $k=0$ we know there is only one array with modulo $3$ equal to $0$. By induction, we can then solve for the number of arrays when $k=n$ that have modulo $3$ equal $0$.

### Analysis
The solution is very well fit for a bottom-up dynamic programming approach with an $n \times 3$ 2d array. Because the $3$ is constant and relatively small, we can treat this array as taking linear space. The dynamic programming solution requires iteration through each row of the array ($O(N)$) and at each value in each row $9$ arithmetic operations to adjust the values of the next row ($O(9)=$O(1)$). Hence, the entire solution is $O(N)$