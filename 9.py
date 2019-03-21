#this solution will get TL on Python

def inverted(c):
    return (c.upper() if c.islower() else c.lower())


def input_requests(scopes):
    requests = int(input())
    for i in range(requests):
        edges = [int(x) for x in str(input()).split()]
        if edges[1] < edges[0]: edges[1], edges[0] = edges[0], edges[1]
        scopes[edges[0]-1] += 1
        scopes[edges[1]] += 1


def solution(strin, scopes):
    length = len(strin)
    invert = False
    for i in range(length):
        if scopes[i] % 2 == 1:
            invert = not invert
        print(inverted(strin[i]) if invert else strin[i], end="")
    

kek = str(input())
length = len(kek)
scopes = [0 for i in range(length)]

input_requests(scopes)
solution(kek, scopes)
