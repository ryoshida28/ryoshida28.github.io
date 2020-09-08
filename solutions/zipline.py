
from math import sqrt


# (g-r)/(h-r) = w0/(w-w0)
# (g-r)(w-w0)/(h-r) = w0
# gw-gw0-rw+rw0 = hw0 -rw0
# gw-rw = hw0+gw0-2rw0

# (h-r)*w/(g-r) = w2 + (h-r)*w2/(g-r)

n = int(input().rstrip())

for _ in range(n):
    w,g,h,r = map(int, input().rstrip().split())

    minLen = sqrt(w*w + abs(g-h)**2)

    denom = h+g-(2*r)
    if g-r == 0:
        print( minLen, minLen)
    else:
        w0 = (g*w - r*w)/(denom)

        l1 = sqrt((g-r)**2 + w0*w0)
        l2 = sqrt((h-r)**2 + (w-w0)**2)
        maxLen = l1+l2

        print(minLen, maxLen)