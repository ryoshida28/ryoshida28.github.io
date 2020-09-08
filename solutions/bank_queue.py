n,t = map(int, input().rstrip().split())

people = []
for _ in range(n):
    people.append(tuple(map(int, input().rstrip().split())))

people.sort(key=(lambda x: (-x[0], x[1])))

cache = [0 for _ in range(t+1)]

for cash, time in people:
    for i in range(time, -1, -1):
        if cache[i] == 0:
            cache[i] = cash
            break

    

print(sum(cache))