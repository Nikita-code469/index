


n = int(input("Введите n: "))



for i in range(1, n + 1):
    spaces = " " * (n - i)

    s = ""
    for j in range(1, i + 1):
        s += str(j)
    for j in range(i - 1, 0, -1):
         s += str(j)
    print(spaces + s)
