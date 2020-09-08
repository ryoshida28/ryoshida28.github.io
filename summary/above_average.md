[_metadata_:tags]:- "Kattis trivial"

# [Above Average](https://open.kattis.com/problems/aboveaverage)

---

## Problem Description
> For each test case, given a list of numbers determine what percentage of those numbers are about the average of those numbers.

### Example
#### Input
```
5
5 50 50 70 80 100
7 100 95 90 80 70 60 50
3 70 90 80
3 70 90 81
9 100 99 98 97 96 95 94 93 91
```
#### Output
```
40.000%
57.143%
33.333%
66.667%
55.556%
```

## [Solution](%PUBLIC_URL%/solutions/above_average.cpp)
The solution can easily be reached with two iterations over the list of numbers. The first iteration to calculate the average. The second iteration is to count how many numbers are greater than the average.

### Analysis
It can easily be ascertained that lower bound for this prolem is $\Omega (N)$ as it is always required for every element in the list to be checked. The solution makes two iterations through the lists which is $O(N)$, hence, the solution is tightly bound at $\theta (N)$.
