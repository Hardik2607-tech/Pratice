s1= input("Enter String: ")
s2= input("Enter String: ")
output= ''
i,j=0,0
while i<len(s1) or j<len(s2):
    output= output+s1[i]+s2[j]
    i+=1
    j+=1
print(output)