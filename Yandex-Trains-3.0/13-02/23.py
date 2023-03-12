n = int(input())
dpUp = [0] * (n+1)
dpDown = [0] * (n+1)

dpUp[1] = 1
dpDown[1] = 0

for i in range(2, n+1):
    dpUp[i] = dpUp[i-1] + ((1 + i) * i) // 2
    if i % 2:
        x = i // 2
        dpDown[i] = dpDown[i-1] + (1 + x) * x
    else:
        x = i // 2 - 1
        dpDown[i] = dpDown[i-1] + (1 + x) * x + x + 1

print(dpUp[n] + dpDown[n])
