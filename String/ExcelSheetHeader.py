def convertToTitle(columnNumber: int) -> str:
    result = []
    while columnNumber > 0:
        columnNumber -= 1  # adjust for 1-based indexing
        result.append(chr(columnNumber % 26 + ord('A')))
        columnNumber //= 26
    return ''.join(reversed(result))


# 🧪 Testcases
print(convertToTitle(1))    # Output: "A"
print(convertToTitle(28))   # Output: "AB"
print(convertToTitle(701))  # Output: "ZY"
print(convertToTitle(52))   # Output: "AZ"
print(convertToTitle(703))  # Output: "AAA"
