from collections import deque

def solution(maps):
    
    n = len(maps)
    m = len(maps[0])
    
    board = [[0]*m for _ in range(n)]
    
    board[0][0] = 1
    board[n-1][m-1] = -1
    
    queue = deque([(0, 0)])
    
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    
    while queue:
        row, col = queue.popleft()
        for i in range(4):
            nr = row + dy[i]
            nc = col + dx[i]
            if nr < 0 or nc < 0 or nr >= n or nc >= m:
                continue
            if maps[nr][nc] == 0:
                continue
            if board[nr][nc] > 0:
                continue
            
            board[nr][nc] = board[row][col] + 1
            queue.append((nr, nc))
            
    return board[n-1][m-1]