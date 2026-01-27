import heapq
from typing import List

class Solution:
    def minCost(self, n: int, edges: List[List[int]]) -> int:
        """
        Calculates the minimum cost to travel from node 0 to node n-1
        allowing edge reversals.
        
        Logic:
        1. Normal Move: u -> v with cost w (from input edges).
        2. Reverse Move: If there is an edge u -> v, one can arrive at v, 
           activate the switch, and traverse v -> u with cost 2*w.
           This effectively adds a directed edge v -> u with weight 2*w.
           
        Since we are finding the shortest path with positive weights, we never
        need to visit a node more than once, satisfying the 'switch used at most once' constraint.
        """
        
        # Adjacency list: adj[u] = [(v, weight), ...]
        adj = [[] for _ in range(n)]
        
        for u, v, w in edges:
            # 1. Normal directed edge: u -> v
            adj[u].append((v, w))
            
            # 2. Reversed edge option: v -> u
            # Using the switch at node 'v' allows us to traverse 'v -> u'
            # Cost is 2 * w
            adj[v].append((u, 2 * w))
            
        # Dijkstra's Algorithm
        # Priority Queue stores tuples: (current_accumulated_cost, current_node)
        pq = [(0, 0)]
        
        # Track minimum cost to reach each node
        # Initialize with infinity
        min_costs = [float('inf')] * n
        min_costs[0] = 0
        
        while pq:
            current_cost, u = heapq.heappop(pq)
            
            # Optimization: If we found a shorter way to 'u' already, skip this stale entry
            if current_cost > min_costs[u]:
                continue
            
            # Target reached
            if u == n - 1:
                return current_cost
            
            # Explore neighbors
            for v, weight in adj[u]:
                new_cost = current_cost + weight
                
                if new_cost < min_costs[v]:
                    min_costs[v] = new_cost
                    heapq.heappush(pq, (new_cost, v))
                    
        # If node n-1 is unreachable
        return -1