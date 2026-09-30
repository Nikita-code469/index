s = []

a = int(input("Введите количество элементов "))

for i in range(a):
    x = int(input("Введите число "))
    s.append(x)

res = s[::2]
print(res)
