[_metadata_:tags]:- "Kattis Graph PriorityQueue dijkstras"

# [Big Truck](https://open.kattis.com/problems/bigtruck)

---

## Problem Description
> Given an undirected weighted graph where each node also has a weight, determine the least costly path to get from the first node to the $n^th$ node while simultaneously accumulating a maximum total which is the sum of the weights of all nodes passed through. 

### Example
#### Input
> $6$ nodes with respective weights $1,1,2,3,1,0$.
> Total of $7$ edges, each edge is of form `origin destination weight`.
```
6
1 1 2 3 1 0
7
1 2 2
2 3 3
3 6 4
1 4 4
4 3 2
4 5 3
5 6 2
```
#### Output
> `shortest_path_cost sum_of_node_weights`
```
9 5
```

## [Solution](%PUBLIC_URL%/solutions/big_truck.py)
The problem is essentially a pure `Dijkstra's` implementation with an added hueristic for finding the maximum sum of node weights. Thus, the graph is traversed starting at the first node and each adjacent node is subsequently pushed onto the priority queue which is ordered first by cost and second by node weights. This is guaranteed to produce the optimal path first.

### Analysis
Although the graph will have a maximum of $V=100$ vertices it can be a dense graph. Thus, at worst case the problem is $O(V^2 \log(V))$ which is doable within the problem constraints.