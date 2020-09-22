[_metadata_:tags]:- "CodeForces Graph trees greedy easy"

# [Fridge Lockers](https://codeforces.com/contest/1255/problem/B)

---

## Problem Description
> Given there are $N$ fridges and $M$ chains, chains can be connected between two fridges. The owners of either fridge connected to a chain can unlock the chain. A fridge can be unlocked when all chains connected to it are unlocked. Furthermore, each chain has a cost based on the sum of the weights of the two fridges it is connected to. Find some way, if possible, to connect the fridges such that only the owner can unlock his own fridge while also minimizing the cost of the chains.

### Example
#### Input
* First line: an integer `T` representing the number of test cases
* The next `T` test cases
  * Begins with two integers `N` and `M` representing the number of fridges and chains respectively

```
3
4 4
1 1 1 1
3 1
1 2 3
3 3
1 2 3
```
#### Output
* -1 if impossible
* If possible, print the minimum cost
  * Followed by `m` lines representing a connection between fridges $u$ and $v$
```
8
1 2
4 3
3 2
4 1
-1
12
3 2
1 2
3 1
```

## [Solution](%PUBLIC_URL%/solutions/fridge_lockers.cpp)
Although this is a relatively trivial problem the underlying `Graph` concepts are interesting. It is impossible to lock the fridges if $m < n$. This is because there would have to exist some kind of underlying `tree` structure if this is the case. If there exists a subtree anywhere in the graph there then exists at least one leaf node which would violate the conditions of the problem. From this, the optimal solution is obvious: `greedily` connect all fridges in one large `cycle` and any extra chains can be used between the min sum of fridge weights.

### Analysis
The complexity analysis is trival for the problem as the chain construction can be completed in $O(M)$.