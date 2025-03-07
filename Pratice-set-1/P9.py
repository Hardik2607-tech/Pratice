# Input values
x = int(input("Enter value for x: "))
y = int(input("Enter value for y: "))

print(f"Before swapping: x = {x}, y = {y}")
x, y = y, x

print(f"After swapping: x = {x}, y = {y}")