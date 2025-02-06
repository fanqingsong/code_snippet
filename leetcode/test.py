from typing import List
from math import inf
import heapq


class Graph:
    def __init__(self, n: int, edges: List[List[int]]):
        self.graph = [[] for _ in range(n)]
        for x, y, cost in edges:
            self.graph[x].append((y, cost))

    def addEdge(self, edge: List[int]) -> None:
        x, y, cost = edge[0], edge[1], edge[2]
        self.graph[x].append((y, cost))

    def shortestPath(self, node1: int, node2: int) -> int:
        dist = [inf] * len(self.graph)
        dist[node1] = 0
        q = [(0, node1)]
        while q:
            cost, x = heapq.heappop(q)
            if x == node2:
                return cost
            for y, ncost in self.graph[x]:
                if dist[y] > cost + ncost:
                    dist[y] = cost + ncost
                    heapq.heappush(q, [cost + ncost, y])
        return -1


if __name__ == "__main__":
    g = Graph(4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]])
    g.shortestPath(3, 2)
    g.shortestPath(0, 3)
    g.addEdge([1, 3, 4])
    ret = g.shortestPath(0, 3)
    print(ret)



