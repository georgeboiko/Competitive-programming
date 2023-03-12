from sys import setrecursionlimit
setrecursionlimit(100000)


def vertex_gluing(i, j, st_height):
    global cnt_to, cnt_all

    if not (0 <= i < n and 0 <= j < m) or (a[i][j] == st_height and visited[i][j]):
        return 0

    if a[i][j] != st_height:
        if a[i][j] < st_height:
            cnt_to += 1
        cnt_all += 1
        return 0

    visited[i][j] = 1
    vertex_gluing(i-1, j, st_height)
    vertex_gluing(i+1, j, st_height)
    vertex_gluing(i, j-1, st_height)
    vertex_gluing(i, j+1, st_height)


n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]

visited = [[0]*m for _ in range(n)]
ans = 0
for i in range(n):
    for j in range(m):
        cnt_to = 0
        cnt_all = 0
        vertex_gluing(i, j, a[i][j])

        if cnt_all and not cnt_to:
            ans += 1

print(max(ans, 1))
