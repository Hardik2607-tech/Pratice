def countBinarySubstrings(s: str) -> int:
    prev, curr = 0, 1  # prev group length, current group length
    ans = 0
    
    for i in range(1, len(s)):
        if s[i] == s[i - 1]:
            curr += 1
        else:
            ans += min(prev, curr)
            prev, curr = curr, 1
    
    ans += min(prev, curr)
    return ans


# Example usage:
print(countBinarySubstrings("00110011"))  # Output: 6
print(countBinarySubstrings("10101"))     # Output: 4
