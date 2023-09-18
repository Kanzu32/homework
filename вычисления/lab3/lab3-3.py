import math
import matplotlib.pyplot as plt


def f(x):
    return math.acos(x*x)-x
    # return x*x #-5 5
    # return 2 - x - math.log(x)  # 1.5 1.6


def diff(x):
    return (f(x+0.00001) - f(x-0.00001))/0.00002


def diff2(x):
    return (diff(x+0.00001) - diff(x-0.00001))/0.00002


xs = [x / 100 for x in range(-100, 101)]
ys = [f(x) for x in xs]

plt.grid()


a, b = -1, 1
plt.scatter(a, f(a), color="black")
plt.scatter(b, f(b), color="black")
eps = 0.0001

a = a + eps  # если не определено
b = b - eps
count = 0

if diff(b)*diff2(b) > 0:   # недостаток избыток
    while abs(a - b) > eps:
        a = a - ((b - a) * f(a)) / (f(b) - f(a))
        b = b - f(b) / diff(b)
        plt.scatter(a, f(a), color="red")
        plt.scatter(b, f(b), color="green")
        count += 1

else:                           # избыток недостаток
    while abs(a - b) > eps:
        b = b - ((b - a) * f(b)) / (f(b) - f(a))
        a = a - f(a) / diff(a)
        plt.scatter(a, f(a), color="green")
        plt.scatter(b, f(b), color="red")
        count += 1

print(count)

plt.plot(xs, ys)
plt.show()