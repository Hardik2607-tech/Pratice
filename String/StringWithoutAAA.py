def strWithout3a3b(a: int, b: int) -> str:
    res = []
    while a > 0 or b > 0:
        if len(res) >= 2 and res[-1] == res[-2]:
            # If the last two are the same, we must add the opposite character
            if res[-1] == 'a':
                res.append('b')
                b -= 1
            else:
                res.append('a')
                a -= 1
        else:
            # Otherwise, add the character with more remaining count
            if a >= b:
                res.append('a')
                a -= 1
            else:
                res.append('b')
                b -= 1
    return ''.join(res)


# 🧾 Example test cases
print(strWithout3a3b(1, 2))  # Output: "abb", "bab", or "bba"
print(strWithout3a3b(4, 1))  # Output: "aabaa"
print(strWithout3a3b(3, 3))  # Output: "ababab" or "aabbab"
