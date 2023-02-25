from queue import PriorityQueue
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        x = [-j for j in stones]
        heapq.heapify(x)
        while len(x)>1:
            a = heapq.heappop(x)
            b = heapq.heappop(x)
            if a!=b:
                heapq.heappush(x, -abs(-a - -b))
        if len(x):
            return -x[0]
        return 0
