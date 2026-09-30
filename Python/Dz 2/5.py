
a = set()
b = set()



m_len = int(input("Число элементов в первом множестве "))
for i in range(m_len):
    m = int(input("Первое множество "))
    a.add(m)

n_len = int(input("Число элементов в втором множестве "))
for i in range(n_len):
    n = int(input("Второе множество "))
    b.add(n)


if a.issubset(b) == True:
    print("A подмножество B")
elif b.issubset(a) == True:
    print("B подмножество A")
else:
    print("Подмножеств нет")


print(a, b)
