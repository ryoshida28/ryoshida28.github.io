[_metadata_:tags]:- "Kattis dynamic_programming"

# [Drink Responsibly](https://open.kattis.com/problems/drinkresponsibly)

---

## Problem Description
> Given a list of drinks of varying alcohol levels and costs, find some combination of those drinks so that a certain alcohol level is reached and a certain amount of money is spent.

### Example
#### Input
First Line: `m`, `u`, `d` which each represent the amount of money to be spent, the alcohol level to attain and the number of drinks available.
Next `d` Lines: The name of the drink, a fraction representing the units of alcohol per liter, and the cost of each drink
```
10.00 9.0 2
fire 2 1/1 4.00
water 10 1/2 2.00
```
#### Output
For each link output the drink name and the number of that drink to buy.
```
fire 2
water 1
```

## [Solution](%PUBLIC_URL%/solutions/drink_responsibly.cpp)
This problem is an instance of the knapsack problem. Thus, 2-d bottom `dynamic programming` can be performed as if it can be found a certain alcohol level and cost can be achieved with one combination of drinks it is unecessary to consider any other combination that achieves that same alcohol level and cost. 

### Analysis
The 2-d dynamic programming array must be $m \times u$ where $m$ is the number of possible money states and $u$ is the number of possible alcohol level states. This table will encompass all posssible states and hence the algorithm is $O(m \times u)$.