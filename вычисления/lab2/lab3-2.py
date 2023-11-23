import math
import matplotlib.pyplot as plt


def f(x):
    return math.acos(x*x)-x
    # return (x+3)*(x+3) #-5 5
    # return 2 - x - math.log(x)  # 1.5 1.6


def diff(x):
    return (f(x+0.00001) - f(x-0.00001))/0.00002


xs = [x / 100 for x in range(-100, 101)]
ys = [f(x) for x in xs]


plt.grid()


a, b = -1, 1
plt.scatter(a, f(a), color="black")
plt.scatter(b, f(b), color="black")
eps = 0.0001
prev = 0

a = a + eps  # если не определено
b = b - eps

left = a
right = b

new = b - f(b)/diff(b)
plt.scatter(new, f(new))
plt.axline((b, f(b)), (new, 0), color="red")

count = 1

while abs(f(new)) > eps:
    prev = new
    new = prev - f(prev)/diff(prev)
    plt.scatter(new, f(new))
    plt.axline((prev, f(prev)), (new, 0), color="red")
    count += 1

print(count)

plt.plot(xs, ys)
plt.show()

