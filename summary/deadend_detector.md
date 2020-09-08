[_metadata_:tags]:- "ICPC_World_Finals Kattis Graph depth_first_search"

# [Deadend Detector](https://open.kattis.com/problems/deadend)

---

## Problem Description
> Given an undirected graph, determine on which edges to place deadend signs so that any path that goes through that edge in a certain direction ends in a deadend.

### Example
#### Input
First Line: `n` and `m` representing the number of nodes and the number of edges respectively
Next `m` Lines: `v` and `w` rerpesenting a bidirectional edge between nodes `v` and `w`.
```
6 5
1 2
1 3
2 3
4 5
5 6
```
#### Output
First Line: The number of deadend signs to place
Second Line: An edge `v` to `w` which is an edge to place a deadend sign along the path from `v` to `w`.
```
2
4 5
6 5
```

## [Solution](%PUBLIC_URL%/solutions/deadend_detector.cpp)
This problem requires a strong understanding of graphs. The main observation to make is that deadend signs should only be placed at the entrances to a `tree`. This is because trees are acyclical and thus will always result in a deadend. With this in mind, the graph must first be split into its connected components. This can be done with a `depth first search`. For each connected component, it must be determined if it is a tree. This can easily be done by checking if the number of edges is one less than the number of nodes in the connected component. For the components which are trees, signs should be placed on all edges connected to nodes with degree 1. For cyclical components, a sort of topological sort must be performed, removing nodes with degree 1 until no node has degree 1. The last edges to be removed are the edges to place deadend signs on.

### Analysis
The initial step of find the connected components requires a depth first search which is $O(V + E)$ where $V$ is the number of nodes and $E$ is the number of edges. Once the connected components are found, each commponent is checked to determine where to place deadend signs. For trees this process is $O(V_0)$ where $V_0$ is the number of vertices in the component. For cyclical components the process is $O(V_0 + E_0)$ as it is a sort of modified breadth first search. Thus, the entire solution is on the order $O(V+E)$