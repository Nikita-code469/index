a = int(input("Введите первое число "))
b = int(input("Введите второе число "))
c = int(input("Введите третье число "))

if a == b and a == c:
    print("3 совпадения")
elif (a < b or a > b and a == c) or (a < c or a > c and a == b) or (b < a or b > a and b == c)or (b < c or b > c and b == a)or (c < a or c > a and c == a)or (c < b or c > b and c == b):
    print("2 совпадения")
else:
    print("Совпадений нет")