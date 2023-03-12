n, a, b = map(int, input().split())

dp = [0] * (n + 1)
for i in range(2, n+1):
    dp[i] = 10**20
    for j in range(1, i):
        dp[i] = min(dp[i], max(dp[j] + a, dp[i-j] + b))

print(dp[n])
