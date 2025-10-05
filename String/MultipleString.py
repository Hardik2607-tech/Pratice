def multiply(num1: str, num2: str) -> str:
    if num1 == "0" or num2 == "0":
        return "0"

    n, m = len(num1), len(num2)
    res = [0] * (n + m)

    # Multiply digits from right to left
    for i in range(n - 1, -1, -1):
        for j in range(m - 1, -1, -1):
            mul = (ord(num1[i]) - ord('0')) * (ord(num2[j]) - ord('0'))
            p1, p2 = i + j, i + j + 1
            sum_ = mul + res[p2]

            res[p2] = sum_ % 10
            res[p1] += sum_ // 10

    # Convert to string (skip leading zeros)
    result = []
    for num in res:
        if not result and num == 0:
            continue
        result.append(str(num))

    return ''.join(result) if result else "0"


# Example usage
print(multiply("2", "3"))       # Output: "6"
print(multiply("123", "456"))   # Output: "56088"
print(multiply("999", "999"))   # Output: "998001"
