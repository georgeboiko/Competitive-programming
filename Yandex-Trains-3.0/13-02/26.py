n, m = map(int, input().split())

tos = [(-1, 2), (1, 2), (2, 1), (2, -1)]
dp = [[0] * m for _ in range(n)]
dp[0][0] = 1

for i in range(n):
    for j in range(min(i + 1, m)):
        x = i-j
        y = j
        for dx, dy in tos:
            xTo = x + dx
            yTo = y + dy
            if 0 <= xTo < n and 0 <= yTo < m:
                dp[xTo][yTo] += dp[x][y]

for i in range(1, m):
    for j in range(min(m - i, n)):
        x = n - j - 1
        y = i + j
        for dx, dy in tos:
            xTo = x + dx
            yTo = y + dy
            if 0 <= xTo < n and 0 <= yTo < m:
                dp[xTo][yTo] += dp[x][y]

print(dp[n-1][m-1])
