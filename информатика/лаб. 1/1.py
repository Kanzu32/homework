from math import log
in_file = open("in.txt", "r")
text = in_file.read().lower()
allowed = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя "
M = 0
graph = {}

for i in range(len(text)):
    if text[i] in allowed:
        item = text[i]
        if (item == "ё"):
            item = "е"
        if (item == "й"):
            item = "и"
        if (item == "ъ"):
            item = "ь"
            
        M += 1
        
        if graph.get(item):
            graph[item] += 1
        else:
            graph[item] = 1

print(M)
print(graph)
            
        
