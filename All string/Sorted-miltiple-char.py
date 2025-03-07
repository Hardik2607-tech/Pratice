s = input("Enter String: ")
target = ''
for ch in s:
    if ch.isalpha():
        x= ch
    else:
        d=int(ch)
        target = target + x*d
output = ''.join(sorted(target))
print(output)