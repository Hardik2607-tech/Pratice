
s = input()

n = len(s)
st = []

pairs = {
  ')': '(',
  ']': '[',
  '}': '{'
}

for ch in s:

  if ch in "[{(":
    st.append(ch)

  else:
    if not st or st[-1] != pairs[ch]:
      print(False)
      break
    st.pop()
    
else:
   print(len(st) == 0)