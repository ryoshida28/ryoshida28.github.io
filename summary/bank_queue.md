[_metadata_:tags]:- "Kattis greedy"

# [Bank Queue](https://open.kattis.com/problems/bank)

---

## Problem Description
> Given $n$ people in a queue at a bank, each who has $c_i$ cash and is willing to wait $t_i$ minutes, determine the maximum amount of cash that can be accumulated in time $T$.

### Example
#### Input
`N T` followed by $N$ lines of form `ci ti`
```
4 4
1000 1
2000 2
500 2
1200 0
```
#### Output
```
4200
```

## [Solution](%PUBLIC_URL%/solutions/bank_queue.py)
The solution requires a `greedy` approach where the priority is to find a spot for the people with the most cash first. To find a spot, place them as late as possible so that it does not conflict with any people for whom their spot is already determined. This can be accomplished by sorting the people in descending order of cash and ascending order of time. A separate array is used to keep track of what spots are available. The sorted array of people is iterated over and for each person, the array of available spots is iterated over from the max time down to index 0 until a spot is found. For those people whom a spot can be found for, their cash is added to the sum which is the returned output.

### Analysis
The first operation performed is the sort on the array of people which is $O(N \log(N))$. Then each person is iterated over $(O(N))$ and for each person a maximum of $T$ iteration must occur to find a spot. Thus, the entire solution is $O(NT + N \log(N))$.