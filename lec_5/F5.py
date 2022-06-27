import math
ax, ay, bx, by = map(int, input().split())
c = (ax*bx + ay*by)/(((ax**2 + ay**2)**0.5) * ((bx**2 + by**2)**0.5))
print(math.acos(c))
