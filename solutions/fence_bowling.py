import math

k,w,l = map(float,raw_input().split(" "))
k = int(k)

def check_beta(beta):
    length_total = (w/2.0)*math.tan(beta)
    alpha = beta
    for _ in range(k-1):
        length_total += w*2.0*math.tan(alpha)
        alpha = math.atan(2.0*math.tan(alpha))
    length_total += w*math.tan(alpha)

    if length_total > l-.0000001 and length_total < l+.0000001:
        print(beta*180/math.pi)
        return 0
    elif length_total > l + .0000001:
        return 1
    else:
        return -1


if k == 0:
     print(90.0)
else:   
    max = math.pi/2
    min = 0
    while(True):
        mid = min/2.0 + max/2.0
        check = check_beta(mid)
        if check == 0:
            break
        elif check == 1:
            max = mid
            min = min
        else:
            max = max
            min = mid






