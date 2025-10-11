def myAtoi(s: str) -> int:
    INT_MAX = 2**31 - 1
    INT_MIN = -2**31

    i, n = 0, len(s)
    sign, result = 1, 0

    # 1. Skip leading spaces
    while i < n and s[i] == ' ':
        i += 1

    # 2. Check sign
    if i < n and s[i] in '+-':
        sign = -1 if s[i] == '-' else 1
        i += 1

    # 3. Read digits
    while i < n and s[i].isdigit():
        digit = ord(s[i]) - ord('0')

        # 4. Check overflow
        if result > (2**31 - 1 - digit) // 10:
            return INT_MAX if sign == 1 else INT_MIN

        result = result * 10 + digit
        i += 1

    return sign * result


# -----------------
# Test Cases
# -----------------
test_cases = [
    "42",            # → 42
    "   -042",       # → -42
    "1337c0d3",      # → 1337
    "0-1",           # → 0
    "words and 987", # → 0
    "-91283472332",  # → -2147483648 (INT_MIN)
    "91283472332",   # → 2147483647 (INT_MAX)
    "+1",            # → 1
    "",              # → 0
]

for t in test_cases:
    print(f"{t!r} -> {myAtoi(t)}")
