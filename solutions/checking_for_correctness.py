from sys import stdin

m = 10000


def exp(a,b):
    if (b == 1):
        return a%m
    else:
        val = (exp(a,b//2)**2)%m
        if b%2 == 1:
            val = (val*(a%m))%m
        return val
            
        

for line in stdin:
    a,op,b = line.rstrip().split()
    a = int(a)
    b = int(b)

    result = 0
    if op == '+':
        result = (a%m + b%m)%m
    elif op == '*':
        result = (a%m * b%m)%m
    else:
        result = exp(a,b)
    
    print(result)