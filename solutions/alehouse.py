# Python 2.7
import heapq

n,k = map(int, raw_input().rstrip().split())

l = []
for _ in range(n):
    a,b = map(int, raw_input().rstrip().split())
    l.append((a,b))

l.sort()

heap = []       # min-heap
                # will pop by first to leave
                # will represent number of friends that can be made during that time period

ct = 0
for a,b in l:
    if len(heap) == 0:
        ct = max(ct, 1)
        heapq.heappush(heap, ((b,a), (a,b)))
    else:
        add_val = True
        while len(heap) > 0:
            # Pop off values until time range is less than k
            val = heapq.heappop(heap)
            rear_pop = val[1][1]
            if a - rear_pop <= k:   # break out of loop
                heapq.heappush(heap, val)
                heapq.heappush(heap, ((b,a),(a,b)))
                ct = max(ct, len(heap))
                add_val = False
                break

        if add_val:
            heapq.heappush(heap,((b,a), (a,b)))
            ct = max(ct, 1)

print ct
        
        
        



