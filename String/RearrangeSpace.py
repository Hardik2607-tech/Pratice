def reorderSpaces(text: str) -> str:
    # Count spaces
    total_spaces = text.count(" ")
    
    # Split words
    words = text.split()
    n = len(words)
    
    # Case: only one word
    if n == 1:
        return words[0] + " " * total_spaces
    
    # Distribute spaces
    spaces_between = total_spaces // (n - 1)
    extra_spaces = total_spaces % (n - 1)
    
    # Build result
    return (" " * spaces_between).join(words) + " " * extra_spaces


# ---- Testcases ----
print(reorderSpaces("  this   is  a sentence "))   # "this   is   a   sentence"
print(reorderSpaces(" practice   makes   perfect")) # "practice   makes   perfect "
print(reorderSpaces("hello"))                       # "hello"
