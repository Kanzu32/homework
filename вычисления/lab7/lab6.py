import math

# import matplotlib.pyplot as plt

matrix = [[5, -1, 3, 5],
          [1, -4, 2, 20],
          [2, -1, 5, 10]]
# matrix = [[0.389, 0.273, 0.126, 0.418, 0.144],
#           [0.329, 2.796, 0.179, 0.278, 0.297],
#           [0.186, 0.275, 2.987, 0.316, 0.529],
#           [0.197, 0.219, 0.274, 3.127, 0.869]]
lines = len(matrix)
rows = len(matrix[0])
f = [[float("inf") for j in range(rows-1)] for i in range(0, lines)]


for i in range(lines):
    f[i][0] = matrix[i][-1] / matrix[i][i]
    for j in range(0, rows-2):
        if j >= i:
            f[i][j+1] = -matrix[i][j+1]/matrix[i][i]
            continue
        f[i][j+1] = -matrix[i][j]/matrix[i][i]

last_p = [float("inf") for i in range(lines)]
p = [float("inf") for i in range(lines)]

for i in range(lines):
    last_p[i] = f[i][0]

def test():
    for i in range(lines):
        if abs(last_p[i]-p[i]) > eps:
            return False
    return True

eps = 0.0001
i = 1
while not test():



    for x in range(lines):
        s = [x][0]
        for j in range(1, rows-1):
            s += f[x][j]*last_p[j]
        p[x] =

