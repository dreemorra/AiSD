length = int(input())
kek = [int(i) for i in input().split()]
kek.sort()

if kek[0]*kek[1] > kek[length-1]*kek[length-2]:
    print(kek[0]*kek[1])
else:
    print(kek[length-1]*kek[length-2])