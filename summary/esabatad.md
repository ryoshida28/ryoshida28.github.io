[_metadata_:tags]:- "Google_Code_Jam bitwise_manipulation constructive"

# [ESAb ATAd](https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9e)

---

## Problem Description
> This is an interactive problem. You are assumed to have an unknown binary array of length $B$. Queries can be made which will receive a response giving the the bit at the queried index at that time. Every 1st, 11th, 21st, 31st,...etc. query the binary string will either: be complemented, reversed, complemented and reversed, or remain the same. In at most 150 queries determine the binary string after all queries have been performed.

## [Solution](%PUBLIC_URL%/solutions/esabatad.cpp)
The key observation for this problem is that the type of operation that is performed on the 1st, 11th, 21st, ...etc. query can be determined if the values of a pair of indices equidistant from each end of the array are known to be the same and if another pair is known to be different. In the case that a same pair or a different pair cannot be determined then it is safe to temporarily reduce the possible operations down to two as some operations will lead to the same result.

### Analysis
There are 10 queries between each operation. It requires at maximum 2 queries to determine after every operation what the operation was. Thus, the other 8 queries can be used for discovering more parts of the array.

The max size of the array is $B=100$. Thus, it will take, at maximum, $ceil(\frac{100}{8})=13$ operations before the entire array is determined. This means a max of about $13 \times 10 = 130$ queries will be required which is less than the max of 150 queries.