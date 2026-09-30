

a = input("Первый список ")
b = input("Второй список ")
c = input("Третьий список ")


d = dict([(1, a), (2, b), (3, c)])

x = int(input("Какой список открыть? "))

if x == 1:
    print(d[1])
elif x == 2:
    print(d[2])
elif x == 3:
    print(d[3])

print(d)