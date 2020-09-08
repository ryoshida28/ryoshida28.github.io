[_metadata_:tags]:- "Kattis Graph dfs"

# [Class Picture](https://open.kattis.com/problems/classpicture)

---

## Problem Description
> Given up to 5 classes with the names of students in each class and pairs of students who cannot line up next to each other for a picture, find the lexicographically first ordering of students for each class picture that will not violate any of the pairs. If no such ordering exists output `you all need therapy.`.

### Example
#### Input
```
5
Ron
George
Bill
Fred
Jenny
3
Fred Jenny
Bill Ron
George Jenny
```
#### Output
```
Bill Fred George Ron Jenny
```

## [Solution](./solutions/class_picture.cpp)
From the given pairs of students which cannot be adjacent a graph can be constructed in which each student maps to every student that they can be adjacent to. Then compute a `depth-first-search` originated from each student starting from the lexicographically first student to determine if there exists a `simple path` through every node in the graph.

### Analysis
The process of constructing the graph has complexity $O(V+E)$ where $V$ is the number of vertices and $E$ is the number of edges in the graph. $E$ can be at maximimum $V^2$. The `depth-first-search` is worst case $O(V^2)$ because each node is a starting point and each dfs traversal will go through a maximum of $V$ steps. Thus, the entire algorithm is on the order of $O(V^2)$.
