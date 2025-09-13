def maxPower(s: str) -> int:
    max_len = 1
    curr_len = 1

    for i in range(1, len(s)):
        if s[i] == s[i - 1]:
            curr_len += 1
            max_len = max(max_len, curr_len)
        else:
            curr_len = 1

    return max_len


# Example usage
print(maxPower("leetcode"))            # Output: 2
print(maxPower("abbcccddddeeeeedcba")) # Output: 5
