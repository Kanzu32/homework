import math
import matplotlib.pyplot as plt


def f(x):
    return 2 - x - math.log(x)


def f_sign(x):
    res = f(x)
    if res > 0:
        return True
    return False


left, right = 1.5, 1.6

xs = [x / 100 for x in range(int(left*100-5), int(right*100+5))]
ys = [f(x) for x in xs]
plt.plot(xs, ys)
plt.grid()
plt.scatter(left, f(left), color="black")
plt.scatter(right, f(right), color="black")

mid_val = -1
mid = 0
eps = 0.0001
count = 0

while abs(mid_val) >= eps:
    count += 1
    left_sign = f_sign(left)
    right_sign = f_sign(right)
    mid = (left + right) / 2
    mid_sign = f_sign(mid)
    mid_val = f(mid)
    if left_sign != mid_sign:
        right = mid
    else:
        left = mid
    plt.scatter(mid, mid_val)

print("x: ", mid, ", y: ", f(mid))
print("count: ", count)
plt.show()
