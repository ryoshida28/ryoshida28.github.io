





n = int(input().rstrip())

print('? 1 2')
ab = int(input().rstrip())
print('? 1 3')
ac = int(input().rstrip())
print('? 2 3')
bc = int(input().rstrip())

a = (ac + ab - bc)//2
b = ab - a
c = ac - a
arr = [a, b, c]

for i in range(4,n+1):
    print(f'? 1 {i}')
    num = int(input().rstrip()) - a
    arr.append(num)
print('! ' + ' '.join(map(str,arr)))