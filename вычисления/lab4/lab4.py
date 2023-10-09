import math

a = [[81, -45, 45],
     [-45, 50, -15],
     [45, -15, 38]]
b = [531, -460, 193]

l = [[0 for j in range(len(a))] for i in range(len(a))]
lt = [[0 for j in range(len(a))] for i in range(len(a))]


for i in range(len(a)):
    for j in range(i):
        tmp = 0
        for k in range(j):
            tmp += l[i][k] * l[j][k]
        l[i][j] = (a[i][j] - tmp) / l[j][j]

    tmp = a[i][i]
    for k in range(i):
        tmp -= l[i][k] * l[i][k]
    l[i][i] = math.sqrt(tmp)

for i in range(len(a)):
    for j in range(len(a)):
        lt[j][i] = l[i][j]
print("L: ")
print(*l, sep="\n", end="\n\n")
print("Lt: ")
print(*lt, sep="\n", end="\n\n")

# l*y=b
# lt*x=y
ys = [0 for i in range(len(a))]
xs = [0 for i in range(len(a))]

for y in range(len(a)):
    s = 0
    for i in range(y+1):
        s += ys[i] * l[y][i]
    ys[y] = (b[y] - s)/l[y][y]

for x in reversed(range(len(a))):
    s = 0
    for i in range(x+1, len(a)):
        s += xs[i] * lt[x][i]
    xs[x] = (ys[x] - s)/lt[x][x]

print("Y: ")
print(*ys, end="\n\n")
print("X: ")
print(*xs, end="\n\n")
