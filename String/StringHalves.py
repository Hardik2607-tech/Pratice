def halvesAreAlike(s: str) -> bool:
    vowels = set("aeiouAEIOU")
    n = len(s)
    half = n // 2
    
    a, b = s[:half], s[half:]
    
    count_a = sum(ch in vowels for ch in a)
    count_b = sum(ch in vowels for ch in b)
    
    return count_a == count_b


# Test cases
print(halvesAreAlike("book"))      # True
print(halvesAreAlike("textbook"))  # False
print(halvesAreAlike("MANGO"))     # False
print(halvesAreAlike("AbCdEfGh"))  # True
