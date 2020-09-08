[_metadata_:tags]:- "HackerRank all_pairs_shortest_path Graph dynamaic_programming"

# [City of Blinding Lights](https://www.hackerrank.com/challenges/floyd-city-of-blinding-lights/problem)

---

## Problem Description
> A weighted directed graph is given. From this graph determine for each query the shortest path between the two nodes specified by the query. If no path exists, return -1.

### Example
#### Input
First Line: `n` and `m` which are the number of nodes and edges respectively
Next `m` Lines: `x`, `y`, and `r` which are the out-node, in-node, and weight respectively of an edge in the graph
Next Line: `q` which is the number of queries.
Next `q` Lines: `a` and `b` which are the two nodes which you are supposed to determine the shortest distance between
```
4 5
1 2 5
1 4 24
2 4 6
3 4 4
3 2 7
3
1 2
3 1
1 4
```
#### Output
```
5
-1
11
```

## [Solution](%PUBLIC_URL%/solutions/city_of_blinding_lights.cpp)
This problem is an obvious instance of the all pairs shortest path problem as it is expected that there could be many queires and thus, re-computing the shortest path for each query would be infeasible. The algorithm which I chose was the Floyd-Warshall algorithm which uses dynamic programming to compute the shortest distances between each node initially so that all queries require constant time.

### Analysis
The way Floyd-Warshall works is as follows: for each node, check against every other node all possible intermediary nodes for the shortest distance between the two nodes. This entire process is $O(N^3)$ where $N$ is the number of nodes in the graph. Once this is completed every query only reaquires $O(1)$ time. Thus, the entire solution is $O(N^3)$.