[_metadata_:tags]:- "Kattis PriorityQueue"

# [Alehouse](https://open.kattis.com/problems/alehouse)

---

## Problem Description
> Given a sequence of ranges $[a,b]$ find a range of maximum length $k$ which captures the maximum number of given ranges. Return the maximum number of ranges that can be captures.

### Example
#### Input
```
6 2
0 2
1 8
5 9
2 4
7 8
10 10
```
#### Output
```
4
```

## [Solution](%PUBLIC_URL%/solutions/alehouse.py)
This solution involves smart use of a `Priority Queue`. The first step is to sort the given list of ranges by their initial start values. This sorted list can be iterated over and each range can be pushed to a `Priority Queue` with highest priority given to the range with the smallest $b$. While this is happening, the total range of values in the `Priority Queue` is continuously verified to be less than $k$. If it ever exceeds k values are popped off the priority queue until this constraint is satasfied. While this is a happening a $maxcount$ value is being calculated to determine the maximum size of the `Priority Queue` during the entire operation. After the entire list of ranges are iterated over the $maxcount$ is returned.

### Analysis
The first step of sorting the values is $O(N\log(N))$. Then all $N$ values are iterated over while, in each iteration values may be pushed or popped from a priority queue. Each value can only be pushed and popped once. Thus, this process is $O(2N\log(N))$ worst case and the entire solution simplifies to be $O(N\log(N))$ complexity.