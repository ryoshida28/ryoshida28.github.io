[_metadata_:tags]:- "Kattis geometry"

# [Glyph Recognition](https://open.kattis.com/problems/glyphrecognition)

---

## Problem Description
> Given a $n$ points on a coordinate plane determine which regular $k$-gon $(3 \le k \le 8)$ best fits these points. The best fit is determined by which $k$-gon has the greatest ratio of inner enclosed area over outer enclosed area. The inner area must contain no points and the outer area must contain all points.

### Example
#### Input
`n followed by n coordinate points`
```
9
-4 -1
-4 6
-3 -6
-3 4
0 -4
2 -3
2 3
5 1
7 0
```
#### Output
`k` and $\frac{A_inner}{A_outer}$
```
3 0.5625000000
```

## [Solution](%PUBLIC_URL%/solutions/glyph_recognition.cpp)
Each coordinate can be converted from cartesian to polar. This conversion allows the sorting of the points by angle $\theta$ from the horizontal. This is done because, for each $k$-gon, $k$-triangles can be constructed with the center and two adjacent vertices. Then, because it is a *regular* $k$-gon, it can be determined for each coordinate, based on its polar angle, which triangle it is a part of. The length of the apothem of that triangle can be calculated based of this polar coordinate ($r \cos(\phi)$ where $\phi$ is the angle between the polar coordinate and the apothem). The minimum area $k$-gon will always have the minimum apothem length and the maximum area $k$-gon will always have the maximum apothem length. The ration of the areas $\frac{A_inner}{A_outer}$ can be simplified to $\frac{{apothem_{inner}}^2}{{apothem_{outer}}^2}$.

### Analysis
The solution begins with converting each cartesian coordinate to polar which is $O(N)$. These polar coordinates are then sorted $O(N \log(N))$. Every possible $k$-gon will have to be checked, however there are only $6$ possible $k$-gons $(3 \le k \le 8)$ so this can be reduced to a constant $O(1)$. For each $k$-gon every coordinate must be iterated through $O(N)$. Thus, the entire solution is on the order of $O(N \log(N))$.