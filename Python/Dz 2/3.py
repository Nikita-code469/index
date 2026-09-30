s = []

a = int(input("Введите количество элементов "))

for i in range(a):
    x = int(input("Введите число "))
    s.append(x)

res = [s[i] 

for i in range(len(s))
    if s[i] > s[i - 1]
]
print(res)
