
s = input()

n = len(s)
st = []

for i in range(n):
  st.append(s[i])

while  st:
  print(st.pop(),end="")
