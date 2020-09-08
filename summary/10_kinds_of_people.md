[_metadata_:tags]:- "Kattis Graph union-find"

# [10 Kinds of People](https://open.kattis.com/problems/10kindsofpeople)

---

## Problem Description
> Given a grid of size $r$ by $c$ where each cell has value either `1` or `0` determine for each subsequent query whether there exists a path from $(r_1,c_1)$ to $(r_2,c_2)$ by only traversing through either the adjacent `1`'s or the `0`'s. If there exists a path through the `0`'s output `binary`; if there exists a path through the `1`'s output `decimal`; otherwise, if no path exists, output `neither`.

### Example
#### Input
```
1 4
1100
2
1 1 1 4
1 1 1 1
```
#### Output
```
neither
decimal
```

## [Solution](%PUBLIC_URL%/solutions/10_kinds_of_people.cpp)
Given that it is one graph for $0 \le n \le 1000$ queries an `equivalence class` can be constructed once on the entire grid to `union find` all `disjoint sets`. This allows for a very efficient query handling by determining whether the two locations are in the same `disjoint set`.

### Analysis
The process of building the `equivalence class` is $O(rc\log*(rc))$ because each of the cells in the grid must be added to the `equivalence class` ($O(rc)$), and each insertion requires $O(\log*(rc))$ where $\log*$ is the `iterated logarithm` (number of times the logarithm must be applied until the result is 1) because `union by rank` is performed which ensures the height of the tree remains very small. Each following query also has the complexity of this `iterated logarithm` ($O(\log*(rc))$). Thus, the entire process is $O(rc\log*(rc) + n\log*(rc))$.
