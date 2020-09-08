[_metadata_:tags]:- "Kattis dynamic_programming best_first_search PriorityQueue"

# [Nikola](https://open.kattis.com/problems/nikola)

---

## Problem Description
> Given a row of $N$ squares numbered $1$ through $N$, find the minimum cost to reach square $N$ from square $1$. The entry fees for each square are given. To traverse the squares each subsequent move in the positive direction must advance 1 more square than the previous; each move in the negative direction must advance the same number of squares as the previous jump.  

### Example
#### Input
```
6
1
2
3
4
5
6
```
#### Output
```
12
```

## [Solution](%PUBLIC_URL%/solutions/nikola.cpp)
For the problem the solution is a `best first search` with `memoization`. Utilizing a priority queue weighted by cost, the best choice can be made for the next step. There is, however, an issue of redundancy as certain squares can be reached with the step. This aspect can be memoized preventing redundancy. Thus, due to the nature of `best first search`, the first path to reach the final square is the minimum cost.

### Analysis
Due to the memoization property, there will be a maximum of $N$ values in the priority queue. Thus, enqueuing and dequeuing will always be $O(\log(N))$. The number of times enqueuing or dequeuing will occur will be on the order of $N^2$ because each square can be reached with $N$ different steps. Hence, the complexity of the entire algorthms is $N^2\log(N)$.