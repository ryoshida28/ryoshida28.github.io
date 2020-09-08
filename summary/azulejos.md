[_metadata_:tags]:- "ICPC_World_Finals Kattis Greedy BST"

# [Azulejos](https://open.kattis.com/problems/azulejos)

---

## Problem Description
> Given two sets of paired numbers $(p_i,h_i)$ find an ordering for the sets in which all $p$ are in non-decreasing order and the $h$ of the first set of pairs is greater than $h$ of the second set of pairs. Output the ordering by the indexes (starting at 1) the pairs as given in the input. Output `impossible` if there is no solution.

### Example
#### Input
```
4
3 2 1 2
2 3 4 3
2 1 2 1
2 2 1 3
```
#### Output
```
3 2 4 1
4 2 1 3
```

## [Solution](%PUBLIC_URL%/solutions/azulejos.cpp)
This problem can be solved with a **greedy** approach. Simultaneously iterate through each set sorted by $p$ (satifies "non-decreasing order" constraint). At each discrete value of $p$ in each set, iterate over the set with least number of pairs values with the smallest $p$. *Greedily* match the pair being iterated over with a pair from the other set with a $h$ as small as possible but larger than the $h$ (other way around if selecting iterating over top row) of the pair being iterated over.

This can be accomplished using a `binary search tree` of `multi-key binary search trees`. This allows iteration by $p$ as well as efficient matching and removing for the *Greedy* step of finding the pair with the smallest $h$ larger than the other pair.

### Analysis
If $N$ is the number of pairs in each row then construction of the tree is $O(N\log(N) + N_0\log(N_0))$ where $N_0$ is the average size of the `multi-key binary search trees`. In-order iteration over each tree is $O(N)$ and the removal of all elements from the tree is $O(N_0\log(N_0))$. Thus, the overall time-complexity of the entire algorithm is $O(N\log(N))$.