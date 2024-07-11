class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        R = len(board)
        C = len(board[0])
        N = len(word)
        
        used = [[False] * C for _ in range(R)]
        found = False
        
        directions = [
            (1, 0),
            (0, 1),
            (-1, 0),
            (0, -1),
        ]
        
        def search(index, x, y):
            if board[x][y] != word[index]:
                return
            
            if index == N - 1:
                nonlocal found
                found = True
                return

            used[x][y] = True
            
            # word[index] == board[x][y]
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                
                if 0 <= nx < R and 0 <= ny < C and not used[nx][ny]:
                    search(index + 1, nx, ny)
                    
            used[x][y] = False
                    
        for x in range(R):
            for y in range(C):
                search(0, x, y)
        return found
        