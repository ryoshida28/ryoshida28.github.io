[_metadata_:tags]:- "HackerRank BST"

# [Median Updates](https://www.hackerrank.com/challenges/median/problem)

---

## Problem Description
> A set of queries will be given. Each query will either be to add or remove a value from a set. After each query, determine the median at that time. If it would not make sense for the set to have a median return `Wrong!`

### Example
#### Input
```
7  
r 1  
a 1  
a 2  
a 1  
r 1  
r 2  
r 1 
```
#### Output
```
Wrong!  
1  
1.5  
1  
1.5  
1  
Wrong!
```

## [Solution](%PUBLIC_URL%/solutions/median_updates.md)
Because there will be a lot of queries and subsequently a lot of median calculations the solution requires an efficient data-structure which has some sort of order property and is efficiently mutable. The optimal data structure in this instance is a `Binary Search Tree`. This solution involves two BSTs - one representing the the values to the left of the median and the other representing the values to the right. A separate integer will hold the value of the current median. For each query all that must be done is either add or remove a value from either tree and then determine whether the median needs to be altered by moving a value from either tree to the median. 

### Analysis
Each query only requires $O(\log(N))$ time as all that is required is to traverse the tree find the location to add/remove a value $(O(\log(N)))$, perform that add/remove operation $O(1)$, and then adjust the median if necessary $O(\log(N))$. For all of these tree traversals there is no worry about pathological trees for the cpp STL self-balancing red-black tree implementation is be used. Hence, if there are $Q$ queries, the entire solution is $O(Q\log(N))$.