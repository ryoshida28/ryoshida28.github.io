[_metadata_:tags]:- "Kattis binary_search"

# [Fence Bowling](https://open.kattis.com/problems/fencebowling)

---

## Problem Description
> A bowling has the side-rails up. When the ball hits the rail at an angle of $\alpha$ relative to the normal it will bounce back at an angle of $\tan^{-1}(2\tan(\alpha))$ relative to the normal. Determine at what initial angle $\Beta$ the ball should be thrown at to get a strike (middle of the bowling lane) on a lane of length $l$ and hitting the rails exactly $k$ times. Must be within $10^{-6}$

### Example
#### Input
```
2 8 27
```
#### Output
```
36.8698976
```

## [Solution](%PUBLIC_URL%/solutions/fence_bowling.py)
This problem is best approached using a binary search because there is a known range of possible solutions and it can be easily determined if a solution is correct. The initial angle will always be in the range $[0,90]$ A binary search can be performed to make guesses which can be verified by calculating the total length the ball must travel to have $k$ bounces and end up in the center. If this calculated length equals the length of bowling lane then it is correct. Otherwise, it must be determined if the angle needs to be increased or decreased.

### Analysis
Because the answer must be within an error of $10^{-6}$ there are $N=90\times 10^{6}$ different possibilities. The binary search will sucessfully find the answer within $O(\log(N))$ which is at worst case about 27. To check if a solution is correct requires $O(K)$ time where $1 \le k \le 10$.