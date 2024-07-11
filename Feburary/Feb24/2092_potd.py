class Solution:
    def findAllPeople(self, N: int, meetings: List[List[int]], firstPerson: int) -> List[int]:

        # Need to be mastered : BFS, DFS and all main graph concepts....
        parents = [i for i in range(N)]
        meetings.append((0, firstPerson, -1))

        def ufind(x):
            if parents[x] != x:
                parents[x] = ufind(parents[x])
            return parents[x]

        def uunion(x, y):
            ux = ufind(x)
            uy = ufind(y)

            parents[ux] = uy

        e = collections.defaultdict(list)
        for x, y, t in meetings:
            e[t].append((x, y))

        for t in sorted(e.keys()):
            q = collections.deque()
            et = collections.defaultdict(list)

            done = set()
            for x, y in e[t]:
                if ufind(x) == ufind(0) and x not in done:
                    q.append(x)
                if ufind(y) == ufind(0) and y not in done:
                    q.append(y)

                et[x].append(y)
                et[y].append(x)

            while len(q) > 0:
                x = q.popleft()

                if x in done:
                    continue

                done.add(x)
                for y in et[x]:
                    if y not in done:
                        uunion(x, y)
                        q.append(y)

        ans = []
        for i in range(N):
            if ufind(i) == ufind(0):
                ans.append(i)
        return ans