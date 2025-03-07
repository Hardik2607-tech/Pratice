s = input("Enter String: ")
I = s.split()
I1 = []
for word in I:
    I1.append(word[::-1])
output = ' '.join(I1)
print(output)
print(I1)