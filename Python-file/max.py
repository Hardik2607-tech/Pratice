a = int(input("Enter A: "))
b = int(input("Enter B: "))
c = int(input("Enter C: "))

if(a>b and a>c):
    print(f"A = {a} is Greater.")
elif(b>a and b>c):
    print(f"B = {b} is Greater.")
elif(c>a and c>b):
    print(f"C = {c} is Greater.")