in_file = open("in.txt", "r")
a = int(in_file.readline())
code = {}
p = {}

for i in range(a):
    symb, num = in_file.readline().split()
    num = float(num)
    p[symb] = num
    code[symb] = ""

while (len(p.items()) >= 2):
    arr = list(p.items())
    arr.sort(key = lambda item: -item[1])
    
    for i in arr[-1][0].split():
        code[i] += "1"

    for i in arr[-2][0].split():
        code[i] += "0"

    nextVal = arr[-1][1] + arr[-2][1]
    nextKey = arr[-1][0] + " " + arr[-2][0]
    p.pop(arr[-1][0])
    p.pop(arr[-2][0])
    p[nextKey] = nextVal

print("общая частота:", list(p.values())[0], "\n")

for i in code.items():
    print(i[0], "\t", i[1], "\t", len(i[1]))

in_file.close()
