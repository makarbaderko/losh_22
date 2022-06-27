def product(A0, A1, A2):
    X1 = (A1[0] - A0[0])
    Y1 = (A1[1] - A0[1])
    X2 = (A2[0] - A0[0])
    Y2 = (A2[1] - A0[1])
    return (X1 * Y2 - Y1 * X2)

def vipukl(points):
    n = len(points)
    pr = 0
    cur = 0
    for i in range(n):
        cur = product(points[i], points[(i + 1) % n], points[(i + 2) % n])
        if (cur != 0):
            if (cur * pr < 0):
                return False
            else:
                pr = cur

    return True

n = int(input())
points = []
for i in range(n):
    points.append(list(map(int, input().split())))
if vipukl(points):
    print("YES")
else:
    print("NO")
