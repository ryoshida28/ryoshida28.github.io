[_metadata_:tags]:- "Kattis complete_search"

# [Cranes](https://open.kattis.com/problems/cranes)

---

## Problem Description
> Given a set of $c$ cranes each with an $x,y$ location and a radius $r$, determine the maximum area that can be covered by the cranes if no cranes overlap. Give this area as the coefficient preceding $\pi$.

### Example
#### Input
```
1
3
0 0 4
5 0 4
-5 0 4
```
#### Output
```
32
```

## [Solution](%PUBLIC_URL%/solutions/cranes.cpp)
The number of cranes $c$ is guarenteed to be at most $20$. Thus, a complete search approach will be feasible. It also means a bitmask can be used for storing states as an integer (32 bits) can hold the $2^20$ possible states in 20 bits. With this in mind, the first step is to determine which cranes intersect which. This requires a nested loop to check for intersections and a bit mask for each crane can store which cranes intersect it. After finding the intersections, a complete search which attempts, for each crane, to either include it or exclude it from the final set of cranes must be performed. It can easily be checked in constant time whether a particular crane can be added to a particular set of cranes using the bitmasks.

### Analysis
Finding the intersections requires a nested loop which is $O(N^2)$. The complete search attempts every possible combination on cranes which is $O(2^N)$. Because $N$, the number of cranes, is never greater than $20$, this complete search is feasible.