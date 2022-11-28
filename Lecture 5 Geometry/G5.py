ax, ay, bx, by = map(int, input().split())
cx, cy, dx, dy = map(int, input().split())

def area(ax, ay, bx, by, cx, cy):
    return (bx - ax) * (cy - ay) - (by - ay) * (cx - ax)


def left(a, b, c, d):
    if a > b:
        b, a = a, b
    if c > d:
        d, c = c, d
    return (max(a, c) <= min(b, d))


def right(ax, ay, bx, by, cx, cy, dx, dy):
    f1 = left(ax, bx, cx, dx)
    f2 = left(ay, by, cy, dy)
    f3 = area(ax, ay, bx, by, cx, cy) * area(ax, ay, bx, by, dx, dy) <= 0
    f4 = area(cx, cy, dx, dy, ax, ay) * area(cx, cy, dx, dy, bx, by) <= 0
    if (f1 and f2 and f3 and f4):
        return True
    return False


ans = right(ax, ay, bx, by, cx, cy, dx, dy)
if (ans == True):
    print("YES")
else:
    print("NO")
