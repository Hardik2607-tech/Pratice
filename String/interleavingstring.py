def isInterleave(s1: str, s2: str, s3: str) -> bool:
    if len(s1) + len(s2) != len(s3):
        return False

    dp = [[False] * (len(s2) + 1) for _ in range(len(s1) + 1)]
    dp[0][0] = True

    # Initialize first row
    for j in range(1, len(s2) + 1):
        dp[0][j] = dp[0][j - 1] and s2[j - 1] == s3[j - 1]

    # Initialize first column
    for i in range(1, len(s1) + 1):
        dp[i][0] = dp[i - 1][0] and s1[i - 1] == s3[i - 1]

    # Fill DP table
    for i in range(1, len(s1) + 1):
        for j in range(1, len(s2) + 1):
            dp[i][j] = (dp[i - 1][j] and s1[i - 1] == s3[i + j - 1]) or \
                       (dp[i][j - 1] and s2[j - 1] == s3[i + j - 1])

    return dp[len(s1)][len(s2)]


# ---------------------------
# ✅ Test Cases
# ---------------------------

print(isInterleave("aabcc", "dbbca", "aadbbcbcac"))  # True
print(isInterleave("aabcc", "dbbca", "aadbbbaccc"))  # False
print(isInterleave("", "", ""))                      # True
print(isInterleave("abc", "def", "adbcef"))          # True
print(isInterleave("abc", "def", "abdecf"))          # True
print(isInterleave("abc", "def", "abcdefg"))         # False
