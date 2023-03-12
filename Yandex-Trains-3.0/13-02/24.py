n = int(input())

a = []
for i in range(n):
    time, t = input().split()
    h, m, s = map(int, time.split(':'))
    t = int(t)
    timeInSec = h * 3600 + m * 60 + s
    a.append((timeInSec, t))

a.append((18*3600+1, 0))

t = [0] * (24*3600 + 1)


for i in range(len(a)-1):
    for j in range(a[i][0], a[i+1][0]):
        t[j] = a[i][1]

dp1 = [0] * (14 * 3600+1)
for i in range(9 * 3600, 13 * 3600+1):
    dp1[i] = max(dp1[i-1], dp1[i])
    if i + t[i] <= 13 * 3600:
        dp1[i + t[i]] = max(dp1[i] + 1, dp1[i])

dp2 = [0] * (18 * 3600+1)
for i in range(14 * 3600, 18 * 3600+1):
    dp2[i] = max(dp2[i-1], dp2[i])
    if i + t[i] <= 18 * 3600:
        dp2[i + t[i]] = max(dp2[i] + 1, dp2[i])

# print(dp1)

print(dp1[13 * 3600] + dp2[18 * 3600])
