[_metadata_:tags]:- "CodeForces trivial"

# [Guess the Array](https://codeforces.com/contest/727/problem/C)

---

## Problem Description
> Given the length of an array $N$, perform queries which will return the sum of two specified indices. With at most $N$ queries determine what the array is.

### Example
#### Input
`N` followed by the response to each query.
```
5
 
9
 
7
 
9
 
11
 
6
```
#### Output
$N$ queries followed by `! array`
```
 
? 1 5
 
? 2 3
 
? 4 1
 
? 5 2
 
? 3 4
 
! 4 6 1 5 5
```

## [Solution](%PUBLIC_URL%/solutions/guess_the_array.py)
The key observation is that, if one number in the array is found, finding every other number is trivial as all that is required is to query for the sum of the known number and the unknown number and subtract the result by the known number. Finding that first number can be reduced to a simple equation $A = ((A+B) + (A+C) - (B+C))/2=(2A + B + C - B - C)/2=A$. This only requires 3 queries, and $B$ and $C$ can be found immediately after. Then the rest of the array can be found with $N-3$ queries.

### Analysis
The number of queries will always have to the $N$ for the values of the array cannot be determined with any less information. 