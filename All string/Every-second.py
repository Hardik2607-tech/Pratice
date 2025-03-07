s = input("Enter String: ")
I = s.split()
I1 = []
# print([I1])
i = 0
while i<len(I):
    if i%2 ==0:
     I1.append(I[i])
    else:
     I1.append(I[i][::-1])
i+=1
output=''.join(I1)
print(output)