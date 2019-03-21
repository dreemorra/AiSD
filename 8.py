kek = input().rstrip()
length = len(kek)

is_iden = True
for i in range(1, length):
    if kek[0] != kek[i]:
        is_iden = False
if is_iden:
    print("-1")
else:
    is_pal = True
    for i in range(length // 2 + 1):
        if kek[i] != kek[length-1-i]:
            is_pal = False
    if is_pal:
        print(length-1)
    else: print(length)