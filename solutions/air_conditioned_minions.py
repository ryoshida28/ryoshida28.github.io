# Python 2.7

n = int(raw_input().rstrip())

minions = []
for _ in range(n):
    l,u = map(int, raw_input().rstrip().split())

    minions.append((l,u))


minions.sort()

last_edge = 0
rooms = 0
for l,u in minions:
    if l > last_edge:
        rooms += 1
        last_edge = u
    else:
        last_edge = min(last_edge, u)

print rooms