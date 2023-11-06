import math

import matplotlib.pyplot as plt

data = [
    [-9, 5],
    [-4, 2],
    [-1, -2],
    [7, 9]
]

# data = [
#     [1.257, 3.081],
#     [1.524, 3.837],
#     [1.728, 3.648],
#     [1.849, 3.424],
#     [1.867, 3.175],
#     [1.768, 2.910],
#     [1.547, 2.638],
#     [1.215, 2.369],
#     [0.798, 2.109],
#     [0.339, 1.864],
#     [-0.104, 1.637]
# ]

# data = [
#     [0, -2],
#     [1, -5],
#     [2, 0],
#     [3, -4]
# ]

# data = [
#     [-1.5, -14.1014],
#     [-0.75, -0.931569],
#     [0, 0],
#     [0.75, 0.931569],
#     [1.5, 14.1014]
# ]

# data = [
#     [0.32, 1.377],
#     [0.73, 2.075],
#     [0.97, 2.637],
#     [1.13, 3.095],
#     [1.52, 4.572],
#     [1.57, 4.806],
#     [2.02, 7.538],
#     [2.52, 12.428],
#     [2.96, 19.297],
#     [3.40, 39.964],
#     [3.79, 44.256]
# ]

coef = [[0 for __ in range(len(data))] for _ in range(len(data))]


def calc_f(j, k):
    d = data[k][0] - data[j][0]
    if j == k:
        return data[k][1]
    else:
        return (calc_f(j+1, k)-calc_f(j, k-1))/d


def calc_x(n):

    r = [-data[0][0], 1]

    for x in range(1, n+1):
        a = [-data[x][0], 1]
        l = x+2
        tmp = [0 for _ in range(l)]
        for i in range(len(r)):
            for j in range(2):
                tmp[i + j] += r[i] * a[j]
        r = tmp
    return r


def calc_newton(n):
    c = [0 for _ in range(len(data))]

    fc = calc_f(0, 0)
    c[0] += fc

    for i in range(1, len(data)):

        fc = calc_f(0, i)
        xc = calc_x(i-1)
        print("fc:", fc, "xc", xc)
        for j in range(len(xc)):
            c[j] += xc[j]*fc
    return c


def f(x, nums):
    res = 0
    for i in range(len(nums)):
        res += nums[i]*math.pow(x, i)
    return res


def draw_graph(nums, size=100, dots=False, style="solid"):
    xs = [x / size for x in range(-size*10, size*10)]
    ys = [f(x, nums) for x in xs]

    plt.plot(xs, ys, linestyle=style)

    if dots:
        for i in range(len(data)):
            plt.scatter(data[i][0], data[i][1], color="black")


r = calc_newton(len(data))
print(f(1.02, r))

draw_graph(r, 100, True)
plt.grid()
plt.show()
