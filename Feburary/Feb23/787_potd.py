class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        K += 1

        e = collections.defaultdict(list)
        for u, v, c in flights:
            e[u].append((v, c))


        INF = 10 ** 20

        dist = [[INF] * (K + 1) for _ in range(N)]

        h = []
        heapq.heappush(h, (0, 0, src))
        dist[src][0] = 0

        while len(h) > 0:
            d, s, index = heapq.heappop(h)

            if dist[index][s] < d:
                continue

            for v, c in e[index]:
                if s + 1 <= K and dist[v][s + 1] > d + c:
                    dist[v][s + 1] = d + c
                    heapq.heappush(h, (d + c, s + 1, v))

        best = INF
        for i in range(K + 1):
            best = min(best, dist[dst][i])
        if best >= INF:
            return -1
        return best