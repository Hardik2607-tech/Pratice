def reverseWords(s: str) -> str:
    # Step 1: Split the string by whitespace (handles multiple spaces)
    words = s.split()
    
    # Step 2: Reverse the list of words
    words.reverse()
    
    # Step 3: Join the words back into a single string with one space
    return " ".join(words)


# ---- Example Tests ----
print(reverseWords("the sky is blue"))       # Output: "blue is sky the"
print(reverseWords("  hello world  "))       # Output: "world hello"
print(reverseWords("a good   example"))      # Output: "example good a"
print(reverseWords("  Bob    Loves  Alice "))# Output: "Alice Loves Bob"
print(reverseWords("Alice does not even like bob"))  # Output: "bob like even not does Alice"
