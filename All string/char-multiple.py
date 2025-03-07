s = input("Enter String: ")
output = ''
count  =1
for i in range(1, len(s)):
    if s[i] == s[i-1]:
        count  += 1
    else:
        output = output + str(count) + s[i-1]
        count = 1

output =  str(count) + output + s[-1]

print(f"Input: {s}")
print(f"Output: {output}")

