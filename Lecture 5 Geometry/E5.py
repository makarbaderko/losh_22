def linesIntersection(a1, b1, c1, A2, B2, c2):
    delta = a1 * B2 - b1 * A2
    delta_x = -c1 * B2 - b1 * (-c2)
    delta_y = a1 * (-c2) - (-c1) * A2
    x = delta_x / delta
    y = delta_y / delta
    return x, y
a1, a2, b1, b2, c1, c2 = map(int, input().split())
x, y = linesIntersection(a1, a2, b1, b2, c1, c2)
print(x, y)
