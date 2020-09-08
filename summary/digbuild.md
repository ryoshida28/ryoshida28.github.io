[_metadata_:tags]:- "Kattis Graph combinatorics"

# [Digbuild](https://open.kattis.com/problems/digbuild)

---

## Problem Description
> Given $N$ which implies a $3 \times N$ grid of which cells can contain torches, determine how many ways the torches can be placed so that no two torches are adjacent.

### Example
#### Input
```
4
```
#### Output
```
227
```

## [Solution](%PUBLIC_URL%/solutions/digbuild.cpp)
This problem is an instance of a particular `graph` thery problem: counting the number of independent sets of vertices on a lattice graph. Papers have been written on how this can be solved on general $n \times m$ lattices (

### Analysis
