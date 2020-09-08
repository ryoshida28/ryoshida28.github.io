[_metadata_:tags]:- "Kattis geometry"

# [Completing the Square](https://open.kattis.com/problems/completingthesquare)

---

## Problem Description
> Given three points on a cartesian coordinate system, determine the fourth point that would, with the other three poirnts, create a square.

### Example
#### Input
```
2 -5
-8 -1
-5 -8
```
#### Output
```
-1 2
```

## [Solution](%PUBLIC_URL%/solutions/completing_the_square.cpp)
Between the three points we can create 3 vectors where each point is the origin of a vector and the destination of another vector. Between these vectors, given that the three points make up a corner of the square, it can be found which points make up which part of the square as the dot product between orthogonal vectors is alsways 0. Once it is known whcih point is which, the fourth point can be determined with some vector subtraction.

### Analysis
All operations are performed in $O(1)$ as it is only simple mathematical operations