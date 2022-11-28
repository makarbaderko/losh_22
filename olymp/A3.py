s = input() 
j = 1
n = 0
for i in range(len(s)-1):
  if s[i+1] == s[i]:
    j += 1
  elif s[i+1] != s[i]:
    j = 1
  if j > n:
    n = j

print(n)
