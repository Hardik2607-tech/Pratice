a = int(input("Enter A: "))
b = int(input("Enter B: "))
c = int(input("Enter C: "))

if(a<b and a<c):
    print(f"A = {a} is smallest.")
elif(b<a and b<c):
    print(f"B = {b} is smallest.")
elif(c<a and c<b):
    print(f"C = {c} is smallest.")