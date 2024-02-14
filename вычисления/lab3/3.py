matrix = []
x = []

print("Enter numbers? (Empty - standard matrix): ")
lines = 0
rows = 0


def rearrange(n):
    if matrix[n][n] != 0:
        return True
    for i in range(n+1, lines):
        if matrix[i][n] != 0:
            matrix[i], matrix[n] = matrix[n], matrix[i]
            return True
    return False

if input() == "":
    matrix = [[0.389, 0.273, 0.126, 0.418, 0.144],
              [0.329, 2.796, 0.179, 0.278, 0.297],
              [0.186, 0.275, 2.987, 0.316, 0.529],
              [0.197, 0.219, 0.274, 3.127, 0.869]]
    #matrix = [[0, -1, -5],
    #          [2, 1, -7]]
    lines = len(matrix)
    rows = len(matrix[0])
    x = [float("inf") for i in range(0, lines)]

else:
    print("Enter N: ")
    lines = int(input())
    rows = lines + 1
    for i in range(lines):
        matrix.append(list(map(int, input().split())))
    x = [float("inf") for i in range(0, lines)]


for n in range(0, lines):
    if matrix[n][n] == 0:
        r = rearrange(n)
        if not r:
            continue
    cur = matrix[n][n]

    for i in range(n+1, lines):
        coef = matrix[i][n] / cur
        for j in range(n, rows):
            matrix[i][j] -= matrix[n][j]*coef

for n in reversed(range(0, lines)):
    s = 0
    for i in range(n+1, lines):
        s += x[i] * matrix[n][i]
    x[n] = (matrix[n][-1] - s)/matrix[n][n]


print(x)
