def countSegments(s: str) -> int:
    count, n = 0, len(s)
    for i in range(n):
        if s[i] != " " and (i == 0 or s[i - 1] == " "):
            count += 1
    return count


# Example usage
print(countSegments("Hello, my name is John"))  # Output: 5
print(countSegments("Hello"))                   # Output: 1
print(countSegments("   "))                     # Output: 0
