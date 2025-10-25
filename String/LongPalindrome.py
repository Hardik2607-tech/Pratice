def longestPalindromeSubseq(s):
    n = len(s)
    dp = [[0] * n for _ in range(n)]

    # Base case: single letters are palindromes of length 1
    for i in range(n):
        dp[i][i] = 1

    # Build up from shorter substrings to longer ones
    for length in range(2, n + 1):  # substring lengths
        for i in range(n - length + 1):
            j = i + length - 1
            if s[i] == s[j]:
                dp[i][j] = dp[i + 1][j - 1] + 2
            else:
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])

    return dp[0][n - 1]


# ----------------------------
# 🧪 Test Cases
# ----------------------------
if __name__ == "__main__":
    s1 = "bbbab"
    s2 = "cbbd"
    s3 = "agbdba"
    s4 = "aaaa"
    s5 = "abcde"

    print("Example 1:", longestPalindromeSubseq(s1))  # 4 ("bbbb")
    print("Example 2:", longestPalindromeSubseq(s2))  # 2 ("bb")
    print("Example 3:", longestPalindromeSubseq(s3))  # 5 ("abdba")
    print("Example 4:", longestPalindromeSubseq(s4))  # 4 ("aaaa")
    print("Example 5:", longestPalindromeSubseq(s5))  # 1 ("a","b","c","d","e")
