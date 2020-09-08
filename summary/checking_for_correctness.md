[_metadata_:tags]:- "Kattis combinatorics"

# [Checking for Correctness](https://open.kattis.com/problems/checkingforcorrectness)

---

## Problem Description
> There are 4 different operations: $+$, $\times$, $^$. Given an expression of the form $a operation b$ find the last 4 digits of the resulting value. All integers will be in range $[0,2^{32})$

### Example
#### Input
```
4231 + 13402
4231 * 13402
4231 ^ 13402
4321 ^ 7
```
#### Output
```
7633
3862
3361
641
```

## [Solution](%PUBLIC_URL%/solutions/checking_for_correctness.py)
For addition and multiplication the following modulous rules can be used: $(a+b)$ $mod$ $n$ $=$ $a$ $mod$ $n$ $+$ $b$ $mod$; $ab$ $mod$ $n$ $=$ $(a$ $mod$ $n)\times(b$ $mod$ $n)$. For exponenents, modular exponentiation can be used. Modular exponentiation takes advantage of the equality $a^b = {(a^{floor(b/2)})}^{2} \times a^{n mod 2}$. Thus, the modular exponent an be calculated recursively by dividing the exponent by 2 every recursive call and taking the modulous with each multiplication operation.

### Analysis
Both addition and multiplation are $O(1)$. The exponent operation is $O(\log(N))$ where $N$ is the exponent. Because the maximum value the exponent can be is $2^{32}$, the modulare exponentiation will have at worst case $32$ recursive calls.