[_metadata_:tags]:- "Kattis HashTable geometry"

# [Unique Dice](https://open.kattis.com/problems/uniquedice)

---

## Problem Description
> Given $n (1 \le n \le 500,000)$ dice which are described in the form of 6 space separated integers of the form `top bottom front back left right`, determine the size of the largest set of identical dice.

### Example
#### Input
```
5
1 1 2 2 2 2
1 2 1 2 2 2
1 2 2 1 2 2
1 2 2 2 1 2
1 2 2 2 2 1
```
#### Output
```
4
```

## [Solution](%PUBLIC_URL%/solutions/unique_dice.cpp)
This problem is heavily reliant on the usage of efficient `Hash Table` data structures with efficient hashing functions and equality comparisons. The data structure used in this solution is a hash map with hash set keys and integer values. The hash sets are all the possible orientations for a particular die. These hash sets are mapped to an integer representing the number of occurences of dice with that orientation. Using 3-dimension geometry it can be determined all the possible orientations of identical dice. The hash function used to hash the hash sets into the hash map can take advantage of the fact that all identical dice will have the same cumulative product. There is also the issue of testing for equality between orientations which can be solved checking if one unique orientation exists in the other set of orientations.

### Analysis
Determining the set of all possible identical orientations of a die is constant time $O(1)$. Inserting the set of orientations into the map is amortized to $O(1)$. This is performed $n$ times, thus giving the entire solution a time complexity of $O(N)$.