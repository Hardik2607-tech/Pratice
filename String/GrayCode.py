def grayCode(n):
    return [i ^ (i >> 1) for i in range(1 << n)]

# Change n here if you want a different Gray code
n = 2

result = grayCode(n)
print(result)
