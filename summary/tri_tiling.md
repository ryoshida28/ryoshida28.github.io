[_metadata_:tags]:- "Kattis combinatorics complete_search"

# [Tri Tiling](https://open.kattis.com/problems/tritiling)

---

## Problem Description
> Given a $3 \times n$ rectangle filled with $2 \times 1$ dominoes, determine the number of differnt possible tilings. Input will be a sequence of testcases ended by a $-1$.

### Example
#### Input
```
2
8
12
-1
```
#### Output
```
3
153
2131
```

## [Solution](%PUBLIC_URL%/solutions/tri_tiling.cpp)
The problem can best be viewed in $2 unit$ increments. The first observation to make is that, in any $3 \times 2$ space there are $3$ possible arrangments of the dominoes. The other scenario is to tile the dominoes in an "odd" fashion in which one piece sticks out: an example would be to have one horizontal domino and one verical one underneath. This second scenario can continue in this odd pattern or be brought back to the standard $3 \times 2$ form. A `complete search` can be performed over all possible scenarios with `counting` to calculate the total number of possibilities.

### Analysis
Analysis of the `complete search` will reveal that for every $2-wide$ section there are $2$ possiblities to branch out of. Thus the entire operation is $O(2 ^ \frac{n}{2})$. The space complexity will be of similar magnitude.