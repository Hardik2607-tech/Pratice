s = input("Enter string: ")
output = ''
for ch in s:
    if ch.isalpha():
        x=ch
    else:
        d= int(ch)
        output= output + x * d
print(output)
