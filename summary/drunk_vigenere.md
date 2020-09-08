[_metadata_:tags]:- "Kattis string_processing"

# [Drunk Vignere](https://open.kattis.com/problems/drunkvigenere)

---

## Problem Description
> Given an encrypted string and a the code for that encryption, return the printed string. The encryption method is every even-indexed character is shifted forward by the key in the code string and every odd-indexed character is shifted backword by the key in the code string.

### Example
#### Input
```
CPMCRYY
ALBERTA
```
#### Output
```
CALGARY
```

## [Solution](%PUBLIC_URL%/solutions/drunk_vigenere.md)
For the problem all that needs to be done is the reverse the encryption by applying the code string to the encrypted string the opposite way to how the string was originally encrypted.

### Analysis
This problem is a simple string processing problem which only requires one iteration through the string. Thus, it is $O(N)$