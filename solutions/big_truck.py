# Python 2.7
import heapq
from sys import maxint


n = int(raw_input().rstrip())

# elements of form node:num_items
pickups = {i:num for i,num in enumerate(map(int, raw_input().rstrip().split()), 1)}

m = int(raw_input().rstrip())

# elements of form init: set{(dest, weight)}
graph = {i : set() for i in range(1, n+1)}
for _ in range(m):
    a,b,d = map(int, raw_input().rstrip().split())
    graph[a].add((b,d))
    graph[b].add((a,d))


# Dijkstra's Shortest Path
# elements of form (distance, -items_picked_up, node, traversed_nodes)
# All other nodes beside the start are hypothetically at infinity
pq = [(0, -pickups[1], 1)]
min_to_node = {i:maxint for i in range(1, n+1)}
min_to_node[1] = 0

found = False
while len(pq) > 0:              # In a typical Dijkstra's implementation continue until node is found
    curr = heapq.heappop(pq)    # dequeue highest priority path
    if curr[2] == n:
        found = True
        print curr[0], -curr[1]
        break

    for dest, weight in graph[curr[2]]:         # add to highest priority path all of its edges (can ignore some edges for certain implementations)
        if min_to_node[dest] >= curr[0]+weight:
            min_to_node[dest] = curr[0] + weight
            heapq.heappush(pq,(curr[0]+weight, curr[1]-pickups[dest], dest))

if not found:
    print "impossible"
        