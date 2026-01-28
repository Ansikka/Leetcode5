import heapq
from typing import List

class Solution:
    def minCost(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        
        # dist[r][c][t] = min cost to reach (r, c) with t teleports
        dist = [[[float('inf')] * (k + 1) for _ in range(n)] for _ in range(m)]
        dist[0][0][0] = 0
        
        max_val = 0
        for r in range(m):
            for c in range(n):
                max_val = max(max_val, grid[r][c])

        for t in range(k + 1):
            # Phase 1: Intra-layer Dijkstra for normal moves
            pq = []
            for r in range(m):
                for c in range(n):
                    if dist[r][c][t] != float('inf'):
                        heapq.heappush(pq, (dist[r][c][t], r, c))
            
            while pq:
                cost, r, c = heapq.heappop(pq)
                
                if cost > dist[r][c][t]:
                    continue
                
                # Normal move: right
                if c + 1 < n:
                    new_cost = cost + grid[r][c + 1]
                    if new_cost < dist[r][c + 1][t]:
                        dist[r][c + 1][t] = new_cost
                        heapq.heappush(pq, (new_cost, r, c + 1))
                
                # Normal move: down
                if r + 1 < m:
                    new_cost = cost + grid[r + 1][c]
                    if new_cost < dist[r + 1][c][t]:
                        dist[r + 1][c][t] = new_cost
                        heapq.heappush(pq, (new_cost, r + 1, c))

            if t == k:
                break
                
            # Phase 2: Inter-layer propagation for teleports
            min_cost_at_val = [float('inf')] * (max_val + 1)
            for r in range(m):
                for c in range(n):
                    val = grid[r][c]
                    if dist[r][c][t] != float('inf'):
                        min_cost_at_val[val] = min(min_cost_at_val[val], dist[r][c][t])
            
            min_cost_from_val_ge = [float('inf')] * (max_val + 2)
            for v in range(max_val, -1, -1):
                min_cost_from_val_ge[v] = min(min_cost_at_val[v], min_cost_from_val_ge[v+1])
            
            for r in range(m):
                for c in range(n):
                    val = grid[r][c]
                    teleport_cost = min_cost_from_val_ge[val]
                    if teleport_cost < dist[r][c][t+1]:
                        dist[r][c][t+1] = teleport_cost
    
        min_total_cost = float('inf')
        for t in range(k + 1):
            min_total_cost = min(min_total_cost, dist[m-1][n-1][t])
            
        return min_total_cost