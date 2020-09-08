[_metadata_:tags]:- "Kattis Graph trivial"

# [Dominoes 2](https://open.kattis.com/problems/dominoes2)

---

## Problem Description
> Given a set of dominoes and which dominoes knock over which, determine the total number of dominoes that fall when $l$ dominoes are knocked over.

### Example
First Line: `t` test cases
For each test case: First Line: `n`, `m`, and `l`, the number of dominoes, relationships between dominoes, and dominoes knocked over
Next `m` lines: `a` and `b` which means domino `a` will knock over domino `b`
Next `l` lines: `d` means domino `d` will be knocked over
#### Input
```
1
3 2 1
1 2
2 3
2
```
#### Output
```
2
```

## [Solution](%PUBLIC_URL%/solutions/dominoes_2.md)
This problem can be trivially reduced to a basic graph traversal problem. After constructing the directed graph, for each domino knocked down simply traverse the graph until there are no more dominos to remove. This will produce the final count

### Analysis
This solution can be achieved with either a breadth first search or a depth first search. Both algorithms are $O(V + E)$. 