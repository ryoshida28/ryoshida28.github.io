[_metadata_:tags]:- "Kattis Graph breadth-first-search dijkstras"

# [Torn To Pieces](https://open.kattis.com/problems/torn2pieces)

---

## Problem Description
> Given a torn up map where each fragment depicts a single station along with all adjacent stations, determine the path from one station to another. If no such path exists, output `no route found`.

### Example
#### Input
```
3
Uptown Midtown
Midtown Uptown Downtown
Downtown Midtown
Uptown Downtown
```
#### Output
```
Uptown Midtown Downtown
```

## [Solution](%PUBLIC_URL%/solutions/torn_to_pieces.cpp)
A graph can be constructed in which edges are formed between nodes representing adjacent stations. From this graph a `breadth-first-search` can used to find a path from the origin to the destination node. When performing this `breadth-first-search` it is important not to visit any stations already visited as doing so would not be the most efficient path; this aspect makes the problem a psuedo-`dijkstras` problem were all edges are weighted equally.

### Analysis
Given that the graph can be very dense with every node being adjacent to up to $n-1$ edges, the `breadth-first-search` will be, in the worse case, $O(N^2)$. Furthermore, the space complexity of the algorithm due to the necessity of calculating the path can end up as $O(N)$. The implementation I used is not the most efficient as it uses $O(N^2)$ space for storing the paths however a setup where nodes point back to their origin nodes is much more space efficient. This is, however, an irrelevant aspect to the problem as the constraints set $2 \le N \le 32$.