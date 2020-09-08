[_metadata_:tags]:- "Kattis geometry greedy"

# [Zipline](https://open.kattis.com/problems/zipline)

---

## Problem Description
> Given the heights of two poles $g,h$, the distance between the two poles $w$, and the height of a rider $r$, determine the minimum and maximum length of the zipline so that the rider does not touch the ground. Assume an inelastic cable.

### Example
#### Input
Number of test cases $n$ followed by $n$ lines of integers `w g h r`
```
2
1000 100 100 20
100 20 30 2
```
#### Output
Output Format: `min_length max_length`
```
1000.00000000 1012.71911209
100.49875621 110.07270325
```

## [Solution](%PUBLIC_URL%/solutions/zipline.py)
The minimum length can be trivially calculated as the distance between the tops of each pole. The key greedy observation for the maximum length is that the lowest point in the zipline will be when the angle between the horizontal and the cable from each side are equal. From this observation the rules of similar triangles and trigonometry can be used. $\cos(\theta) = \frac{w\prime}{g} = \frac{w-w\prime}{h}$, where $\theta$ is the angle between the cable and the horizaontal, $w\prime$ is the horizontal distance between the lowest point and the pole of height $g$, and subsequently $w - w\prime$ is the distance between the lowest point and the pole of height $h$. This equation can be solved for $w\prime$ which can, in turn, be used to solve the length of the cable using the Pythagorean Theorem.

### Analysis
This solution is $O(1)$ as it is a straight geometrical calculation.