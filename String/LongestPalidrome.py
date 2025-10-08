def longestPalindrome(s: str) -> str:
    def expandAroundCenter(left: int, right: int) -> int:
        # Expand while the characters on both sides match
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        # Return the length of the palindrome found
        return right - left - 1

    start = 0
    end = 0
    for i in range(len(s)):
        len1 = expandAroundCenter(i, i)      # Odd-length palindrome
        len2 = expandAroundCenter(i, i + 1)  # Even-length palindrome
        max_len = max(len1, len2)
        if max_len > end - start:
            start = i - (max_len - 1) // 2
            end = i + max_len // 2

    return s[start:end + 1]


# 🔹 Example usage
print(longestPalindrome("babad"))  # Output: "bab" or "aba"
print(longestPalindrome("cbbd"))   # Output: "bb"
print(longestPalindrome("a"))      # Output: "a"
print(longestPalindrome("ac"))
