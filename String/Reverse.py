def reverse(x: int) -> int:
    sign = -1 if x < 0 else 1
    x = abs(x)
    rev = int(str(x)[::-1])

    # 32-bit signed integer range check
    if rev > 2**31 - 1:
        return 0
    return sign * rev


# Example tests
print(reverse(120))       # 21
print(reverse(-123))      # -321
print(reverse(1534236469))# 0 (overflow)
print(reverse(450))       # 54

