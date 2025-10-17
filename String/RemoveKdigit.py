def removeKdigits(num: str, k: int) -> str:
    stack = []
    
    for digit in num:
        # Remove larger digits from the stack if possible
        while k > 0 and stack and stack[-1] > digit:
            stack.pop()
            k -= 1
        stack.append(digit)
    
    # If there are still digits left to remove, remove from the end
    while k > 0:
        stack.pop()
        k -= 1
    
    # Build the final number and remove leading zeros
    result = ''.join(stack).lstrip('0')
    
    # Return "0" if result is empty
    return result if result else "0"


# ---- Example Test Cases ----
print(removeKdigits("1432219", 3))  # Output: "1219"
print(removeKdigits("10200", 1))    # Output: "200"
print(removeKdigits("10", 2))       # Output: "0"
