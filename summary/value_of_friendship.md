[_metadata_:tags]:- "HackerRank Graph greedy union_find combinatorics"

# [The Value of Friendship](https://www.hackerrank.com/challenges/value-of-friendship/problem)

---

## Problem Description
> Given $q$ queries where each query gives a set of $m$ friendships among $n$ students. The friendships are bidirectional and transitive. A "Total Value" is calculated after each given friendship by adding to the previous "Total Value" by the number of friends each of the already given friends have. Determine the maximum this "Total Value" can be with any ordering of friendship relationships.

### Example
#### Input
```
1
5 4
1 2
3 2
4 2
4 3
```
#### Output
```
32
```
#### Explanation
1. pair 1&2 - $Total = (1+1) = 2$
2. pair 2&4 - $Total = 2 + (2+2+2) = 8$
3. pair 3&4 - $Total = 8 + (3+3+3+3) = 20$
4. pair 3&2 - $Total = 20 + (3+3+3+3) = 32$

## [Solution](%PUBLIC_URL%/solutions/value_of_friendship.cpp)
The first step in the solution is to determine the friend-groups. Each friend-group can be abstracted as a `Disjoint Set`. The optimal algorithm for finding disjoint sets is the `union_find` algorithm.

Once the friend-groups are found the next step is to calculate the optimal total. This can be done with a greedy approach where the optimal choice is always to first connect the groups in ordering of largest to smallest. 

The calculation of the "Total Value" using this process is as follows:
**Find "Total Value" to connect on friend group of size $N$**

$Total = \sum_{i=1}^{N} (i(i-1))$

$=\sum_{i=1}^{N} (i^2 - i)$

$=\sum_{i=1}^{N} (i^2) - \sum_{i=1}^{N} (i)$

$=\frac{n(n+1)(2n+1)}{6} - \frac{n(n+1)}{2}$

**Add to $nt_0$ where $t_0$ is the number of friends already found**

### Analysis
The process of building the equivalence class is approximately $O(\log*n)$ where $\log*$ is the iterated logarithm (number of logarithms that must be applied to achieve a value less than or equal to 1. Then the disjoint sets must be sorted by size which is $O(G\log(G))$ where $G$ is the number of groups (this is usually very small). Finally, after sorting, the process of calculating the total is simply $O(G)$.
