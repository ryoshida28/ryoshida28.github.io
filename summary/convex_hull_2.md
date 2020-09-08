[_metadata_:tags]:- "Kattis geometry"

# [Convex Hull 2](https://open.kattis.com/problems/convexhull)

---

## Problem Description
> Given a set of cartesian points where each point is marked as either a part or not a part of the convex hull, return the points in the order in which it forms the convex hull.

### Example
#### Input
Each test case begins with a number `n` which is the number of points. The input will be terminated with a `0`
```
5
1 1 Y
1 -1 Y
0 0 N
-1 -1 Y
-1 1 Y
```
#### Output
```
4
-1 -1
1 -1
1 1
-1 1
```

## [Solution](%PUBLIC_URL%/solutions/convex_hull_2.md)
Determining which points are a part of the convex hull is trivial as it is given to you. To returnt the points in sorted order requires finding the initial point and finding the polar coordinates of all other points with respect to the original point. Once this is done the points can easily be sorted by their respective polar angle. There is one edge case the be aware of which occurs when two points have the same polar angle. To determine which point comes first requires knowing the position of the first previous point in the sorted order that does not have the same polar angle. Once this point is found, all that needs to be done is to determine whether its distance from the reference point is larger or smaller than the points with the same polar angle. From this it can be determined which order to sort the points.

### Analysis
The solution requires sorting all points in the convex hull by their polar angles which is $O(N \log (N))$. It is possible for a lot of points to lie on the same polar angle so additional sorting is required although this is also $O(N \log (N))$. Hence, the solution is $O(N \log (N))$.