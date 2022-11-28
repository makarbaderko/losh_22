def lcs(x, y):
    print("working...")
    if len(x) == 0 or len(y) == 0:
        return []
    if x[-1] == y[-1]:
        return lcs(x[:-1], y[:-1]) + [x[-1]]
    else:
        left = lcs(x[:-1], y)
        right = lcs(x, y[:-1])
        return left if len(left) > len(right) else right
n = int(input())
print(lcs(input(), input()))
