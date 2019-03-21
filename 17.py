cond1 = False
cond2 = False
cond3 = False
cond4 = False
cond5 = False
cond6 = False
for i in range(int(input())):
    kek = int(input())
    if kek == 1021: 
        cond1 = True
    if kek == 1031: 
        cond2 = True
    if kek == 1033: 
        cond3 = True
    if kek == 1065023: 
        cond4 = True
    if kek == 1054693: 
        cond5 = True
    if kek == 1052651: 
        cond6 = True
    if kek == 1087388483:
        cond1 = True
        cond2 = True
        cond3 = True

if (cond1 and cond4) or (cond2 and cond5) or (cond3 and cond6) or (cond1 and cond2 and cond3): print("YES")
else: print("NO")

# 3
#1065023
#1054693
# 1052651