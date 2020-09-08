[_metadata_:tags]:- "Kattis greedy BST"

# [Chopping Wood](https://open.kattis.com/problems/chopwood)

---

## Problem Description
> The problem assumes there initially existed an unrooted tree of numbered nodes. One at a time the minimum valued leaf node is removed until only one node remains. At each remove the node removed and its adjacent node are recorded. This record of which node was removed, however, is lost and all that remains is the record of the nodes adjacent to the nodes removed. From this record, attempt to rederive the original record. If it cannot be done or multiple solutions exist return 'ERROR'. 

### Example
#### Input
First Line: `n` the number of records
Next `n` Lines: The node adjacent to the leaf node being removed
```
6
5
1
1
2
2
7
```
#### Output
`n` Lines: The node to be removed corresponding to the input
```
3
4
5
1
6
2
```

## [Solution](%PUBLIC_URL%/solutions/chopping_wood.cpp)
The first key observation to make is that there can never be an instance where multiple solutions exist. Thus, a greedy approach to reconstruct the tree will work. As the tree is reconstructed, if a contradiction occurs then the process is halted and 'Error' is returned. The method for reconstructing the tree is as follows. The list of nodes from the input is iterated through in reverse fashion. The first node in the tree is always the last node given in the input. Then, to decide which node to add to the tree apply the following rule: from the available nodes add the highest valued one unless the next node in the input has not been added. We try to add the highest valued nodes first so as not to violate the property of the least valued leaves being removed in the initial destructuring of the tree. We are forced to go against this heuristic when the node preceding the curren node in the input has not been added to the tree because failing to do so would invalidate the ordering of the tree destructuring. To perform this requires the use of binary search trees as they allow for efficient search and efficient removal.


### Analysis
Each node in the input is iterated through one at a time to find the corresponding node in the record $(O(N))$. For each node, it must be determined from a set of remaining nodes which to add to the tree. This step can be performed with binary search tree $(O(\log N))$. Thus, the entire algorithm is $O(N \log N)$.

