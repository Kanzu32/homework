from itertools import combinations
arr = [ [1, 0, 0, 0, 0, 0, 1, 0, 1],
        [0, 1, 0, 0, 0, 1, 0, 1, 1],
        [0, 0, 1, 0, 0, 1, 1, 0, 0],
        [0, 0, 0, 1, 0, 0, 1, 1, 0],
        [0, 0, 0, 0, 1, 0, 0, 1, 1] ]
count = 0

def calc(arr):
    res = []
    arr = list(arr)
    a = arr[0]
    b = arr[1]
    for i in range(len(a)):
        if (a[i] != b[i]): res.append(1)
        else: res.append(0)
    arr = arr[2:]
    arr.append(res)
    if (len(arr) == 1): return res
    else: return calc(arr)


for x in range(2, 6):
     cmb = combinations(arr, x)
     for c in cmb:
        count += 1;
        print("\t".join(map(str , calc(c))))
