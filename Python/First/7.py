l = []

zero = 0

n = int(input("Введите n: "))

for i in range(n):
    x = int(input("Введите число ")) 
    l.append(x)
    if x == 0:
        zero += 1

print(zero)
