import math

# x_array = [60.1, 59.2, 58.6, 55.4, 53.1, 52, 49.9]
# y_array = [49, 52.1, 53.2, 56.6, 59.5, 66.6, 67.8]

x_array = [1, 2, 3, 4, 5, 6]
y_array = [1.0, 1.5, 3.0, 4.5, 7.0, 8.5]
a = float("inf")
b = float("inf")
n = len(x_array)

xs = []
ys = []

mode = 0  # 0 - линейная, 1 - степенная, 2 - показательная
x_to_solve = 2  # число для вычисления

def sum_x():
    res = 0
    for x in xs:
        res += x
    return res


def sum_y():
    res = 0
    for y in ys:
        res += y
    return res


def sum_xy():
    res = 0
    for i in range(n):
        res += xs[i] * ys[i]
    return res


def sum_x_square():
    res = 0
    for x in xs:
        res += x*x
    return res


def calc():
    res_a = (n * sum_xy() - sum_x() * sum_y()) / (n * sum_x_square() - sum_x()*sum_x())
    res_b = (1/n) * sum_y() - res_a * (1/n) * sum_x()
    return [res_a, res_b]

if mode == 0:
    xs = [*x_array]
    ys = [*y_array]
    r = calc()
    print("Линейная функция, a:", r[0], "b:", r[1])
    if x_to_solve < float("inf"):
        print("x:", x_to_solve, "y:", r[0]*x_to_solve+r[1])
elif mode == 1:
    for i in range(n):
        xs.append(math.log(x_array[i]))
        ys.append(math.log(y_array[i]))
    r = calc()
    print("Cтепенная функция, a:", r[0], "b:", math.exp(r[1]))
    if x_to_solve < float("inf"):
        print("x:", x_to_solve, "y:", r[1]*math.pow(x_to_solve, r[0]))
elif mode == 2:
    xs = [*x_array]
    for i in range(n):
        ys.append(math.log(y_array[i]))
    r = calc()
    print("Показательная функция, a:", r[0], "b:", math.exp(r[1]))
    if x_to_solve < float("inf"):
        print("x:", x_to_solve, "y:", r[1]*math.exp(r[0]*x_to_solve))
