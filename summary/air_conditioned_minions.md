[_metadata_:tags]:- "Kattis greedy"

# [Air Conditioned Minions](https://open.kattis.com/problems/airconditioned)

---

## Problem Description
> Given $N$ minions each with a temperature preference with lower-bound $L$ and upper-bound $U$, determine the minimum number of rooms needed so that every minion can be in a room and the temperature of that room suits their preferences.

### Example
#### Input
`N` followed by $N$ lines of `Li Ui`
```
3
1 2
2 4
5 6
```
#### Output
```
2
```

## [Solution](%PUBLIC_URL%/solutions/air_conditioned_minions.py)
A greedy approach can be taken to this problem by sorting the minions by the lower-bound of their temperature preference; placing as many minions as possible in each room based on the minimum upper-bound of the minions; when a minion cannot be placed in a room a new one must be created.

### Analysis
The sorting of the minions is $O(N \log(N))$ and the sorted minions are then iterated over once, $O(N)$. Thus, the entire algorithm is on the order of $O(N \log(N))$.