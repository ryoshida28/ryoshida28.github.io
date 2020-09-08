[_metadata_:tags]:- "Kattis string_processing combinatorics"

# [Speaking of Which](https://open.kattis.com/problems/speakingofwhich)

---

## Problem Description
> Consider a "Robber Language" where all consonants are doubled, with an 'o' between. Given a string in the "Robber Language" in which there may, or may not, have been some consonants that were never properly converted, determine how many possible original strings are possible. The output should be given as remainder of possible original strings divided by $1,000,009$.

### Example
#### Input
```
cocaror
```
#### Output
```
4
```

## [Solution](%PUBLIC_URL%/speaking_of_which.cpp)
There are 3 cases to consider
1. If there exists no pattern in the string of `*o*` where `*` is a consonant then there is only one possible original string
2. If there is a standalone pattern `*o*` the number of possibilities is multiplied by two for this string could either be `*o*` or `*`. 
3. If there is pattern in the string of the form `*o*o*...`  then the total number of possibilities is multiplied by $floor(\frac{n+1}{2}) + 1$ where $n$ is the number of occurences of `o`. This is because of the following:
    * The $+1$ comes from the fact that the string can be kept the same with no replacements
    * Because no two adjacent patters (e.g. `*o*o*`) can be simultaneously replaced, only $floor(\frac{n+1}{2})$ patterns can be replaced at a time.
      * Any simultaneous replacement of $m$ patterns will always result in the same original string as any other simultaneous replacement of $m$ patterns.

### Analysis
This, being a very straightforward string processing algorithm only requires $O(N)$ time complexity. Furthermore, this problem is $\Omega(N)$ as any solution would at minimum require looking at every character at least once.