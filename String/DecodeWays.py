# Decode Ways - Dynamic Programming Solution

def numDecodings(s: str) -> int:
    # If the string is empty or starts with '0', it’s invalid
    if not s or s[0] == '0':
        return 0

    n = len(s)
    dp = [0] * (n + 1)

    # Base cases:
    dp[0] = 1  # empty string
    dp[1] = 1  # first char (valid because s[0] != '0')

    # Fill the dp array
    for i in range(2, n + 1):
        one_digit = int(s[i-1:i])      # last one digit
        two_digits = int(s[i-2:i])     # last two digits

        # If the last single digit is valid (1-9)
        if one_digit != 0:
            dp[i] += dp[i-1]

        # If the last two digits are valid (10-26)
        if 10 <= two_digits <= 26:
            dp[i] += dp[i-2]

    # The result is the total number of decodings for the full string
    return dp[n]


# ------------------------------
# Test Cases
# ------------------------------
if __name__ == "__main__":
    tests = [
        ("12", 2),     # "AB", "L"
        ("226", 3),    # "BZ", "VF", "BBF"
        ("06", 0),     # Invalid
        ("11106", 2),  # "AAJF", "KJF"
        ("10", 1),     # "J"
        ("27", 1),     # "BG" only
        ("100", 0),    # No valid decoding
    ]

    for s, expected in tests:
        result = numDecodings(s)
        print(f"Input: {s} → Output: {result} (Expected: {expected})")
