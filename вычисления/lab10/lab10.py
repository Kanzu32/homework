import math
import matplotlib.pyplot as plt


def f(x, y):
    return 0.5*(x-1)*math.exp(x)*y*y-x*y


def rk(a, b, x0, y0, f, eps=0.05):
    xs = [x0]
    ys = [y0]
    h = (b-a)/2

    y1 = float("inf")
    y2 = -float("inf")
    h2 = h
    while abs(y1-y2) > eps:
        h = h2
        k1 = f(x0, y0)
        k2 = f(x0 + h / 2, y0 + h * k1 / 2)
        k3 = f(x0 + h / 2, y0 + h * k2 / 2)
        k4 = f(x0 + h, y0 + h * k3)
        y1 = y0 + (h/6)*(k1+2*k2+2*k3+k4)

        h2 = h/2
        k1 = f(x0, y0)
        k2 = f(x0 + h2 / 2, y0 + h2 * k1 / 2)
        k3 = f(x0 + h2 / 2, y0 + h2 * k2 / 2)
        k4 = f(x0 + h2, y0 + h2 * k3)
        y2 = y0 + (h2/6)*(k1+2*k2+2*k3+k4)

    print("h rk:", h)
    y = y0
    x = x0+h
    k1 = f(x0, y0)
    k2 = f(x0 + h/2, y0 + h*k1/2)
    k3 = f(x0 + h/2, y0 + h*k2/2)
    k4 = f(x0 + h, y0 + h*k3)
    while b >= x >= a:
        y = y + (h/6)*(k1+2*k2+2*k3+k4)
        xs.append(x)
        ys.append(y)
        k1 = f(x, y)
        k2 = f(x + h / 2, y + h * k1 / 2)
        k3 = f(x + h / 2, y + h * k2 / 2)
        k4 = f(x + h, y + h * k3)
        x += h

    return xs, ys

def euler(a, b, x0, y0, f, eps=0.05):
    xs = [x0]
    ys = [y0]
    h = (b-a)/2

    y1 = float("inf")
    y2 = -float("inf")
    h2 = h
    while abs(y1-y2) > eps:
        h = h2
        y1 = y0 + h*f(x0, y0)

        h2 = h/2
        y2 = y0 + h2*f(x0, y0)

    print("h euler:", h)
    y = y0
    x = x0+h
    while b >= x >= a:
        y = y + h*f(x, y)
        xs.append(x)
        ys.append(y)
        x += h

    return xs, ys

xs, ys = rk(0, 2, 0, 2, f, 0.05)
plt.plot(xs, ys)

xs, ys = euler(0, 2, 0, 2, f, 0.05)
plt.plot(xs, ys)
plt.grid()
plt.show()
