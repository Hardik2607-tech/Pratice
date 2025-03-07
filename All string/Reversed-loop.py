s = input("Enter String: ")
output = ''
i = len(s) -1
while i>=0:
    output += s[i]
    print(s[i])
    i-=1
print(output)