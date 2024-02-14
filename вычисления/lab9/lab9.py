import math


def f1(x):
    return math.sqrt(math.exp(x)+1)


def f2(x):
    return 1/(math.exp(x)+1)


def f3(x):
    return math.exp(math.cos(x))*math.sin(x)


def rect(a, b, n, f):
    x = 0
    s = 0
    for i in range(n):
        s += f(x)
        x += (b-a)/n
    return (b-a)*s/n


def trap(a, b, n, f):
    x = 0
    s = 0
    for i in range(n-1):
        s += f(x)
        x += (b - a) / n
    return ((b - a) / n) * ((f(a)+f(b))/2 + s)


def simpson(a, b, n, f):
    s = 0
    for i in range(n*2+1):
        if i == n*2 or i == 0:
            s += f(a + ((b-a)*i)/(2*n))
        elif i % 2 == 0:
            s += 2*f(a + ((b-a)*i)/(2*n))
        else:
            s += 4*f(a + ((b-a)*i)/(2*n))

    return ((b - a) / (6*n)) * s


print(rect(0, 1, 1000, f1))
print(trap(0, 1, 1000, f2))
print(simpson(0, math.pi/2, 1000, f3))
