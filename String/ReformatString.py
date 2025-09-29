def reformat(s: str) -> str:
    letters = [c for c in s if c.isalpha()]
    digits = [c for c in s if c.isdigit()]
    
    # If impossible
    if abs(len(letters) - len(digits)) > 1:
        return ""
    
    # Decide who starts (longer list first)
    if len(letters) > len(digits):
        first, second = letters, digits
    else:
        first, second = digits, letters
    
    result = []
    for i in range(len(s)):
        if i % 2 == 0:
            result.append(first.pop())
        else:
            result.append(second.pop())
    
    return "".join(result)


# ---- Example usage ----
print(reformat("a0b1c2"))     # "0a1b2c" (or any valid alternation)
print(reformat("leetcode"))   # "" (impossible)
print(reformat("1229857369")) # "" (impossible)
