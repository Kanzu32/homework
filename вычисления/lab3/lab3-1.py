import math
import matplotlib.pyplot as plt


def f(x):
    return math.acos(x*x)-x


xs = [x / 100 for x in range(-100, 101)]
ys = [f(x) for x in xs]

plt.plot(xs, ys)
plt.grid()


a, b = -1, 1
plt.scatter(a, f(a), color="black")
plt.scatter(b, f(b), color="black")
eps = 0.0001
new = a - ((b - a)*f(a))/(f(b)-f(a))

count = 0

while abs(f(new)) > eps:
    if f(a) * f(new) < 0:
        b = new
        plt.scatter(b, f(b))
    else:
        a = new
        plt.scatter(a, f(a))
    new = a - ((b - a)*f(a))/(f(b)-f(a))
    count += 1

print(count)

plt.show()
