start = 1
end = 10

print("Prime numbers between", start, "and", end, "are:")

for num in range(start, end + 1):
    # Check if the number is greater than 1
    if num > 1:
        for i in range(2, int(num ** 0.5) + 1):
            if num % i == 0:
                break
        else:
            print(num)
