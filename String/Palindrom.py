def isPalindrome(x: int) -> bool:
    # Negative numbers or numbers ending in 0 (except 0 itself) cannot be palindromes
    if x < 0 or (x % 10 == 0 and x != 0):
        return False

    reversed_half = 0

    # Reverse only half of the number
    while x > reversed_half:
        reversed_half = reversed_half * 10 + x % 10
        x //= 10

    # Check for palindrome (even length OR odd length)
    return x == reversed_half or x == reversed_half // 10


# --------------------------
# Example Testcases
# --------------------------
print(isPalindrome(121))   # True
print(isPalindrome(-121))  # False
print(isPalindrome(10))    # False
print(isPalindrome(0))     # True
