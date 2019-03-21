kek = int(input())

if (kek % 4 == 0 and kek % 100 != 0) or (kek % 400 == 0):
    print("YES")
else:
    print("NO")