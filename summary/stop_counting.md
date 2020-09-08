[_metadata_:tags]:- "Kattis Greedy"

# [Stop Counting](https://open.kattis.com/problems/stopcounting)

---

## Problem Description
> Given a list of numbers, positive and negative, the maximum payout. The maximum payout is determined by taking the average of the values with an optional skip of any number of consecutive values, however only one skip can be performed.

### Example
#### Input
```
5
10 10 -10 -4 10
```
#### Output
```
10.0000000000
```

## [Solution](%PUBLIC_URL%/solutions/stop_counting.md)
There are only two ranges of values that matter. The cumulative sum for all indexes starting from the first index; and the cumulative sum for all indexes starting from the last index. Once this is calculated it can be greedily determined what ranges of values to include for the max average from the left and the max average from the right will always be the desired average.

### Analysis
The problem requires iteration through the list of values twice to find the cumulative sums, $O(2N)$ and another two iterations are made to determine the max average from both ends. Thus, the entire problem is on the order of $O(N)$.