def Area(points):
    n = len(points)
    area = 0
    for i in range(n):
        j = (i + 1) % n
        area += points[i][0] * points[j][1]
        area -= points[j][0] * points[i][1]
    area = abs(area) / 2.0
    return area
n = int(input())
points = []
for i in range(n):
    points.append(list(map(int, input().split())))
print(Area(points))
