def wordPattern(pattern: str, s: str) -> bool:
    words = s.split()
    if len(words) != len(pattern):
        return False
    
    char_to_word = {}
    word_to_char = {}
    
    for ch, word in zip(pattern, words):
        if ch in char_to_word:
            if char_to_word[ch] != word:
                return False
        else:
            char_to_word[ch] = word
        
        if word in word_to_char:
            if word_to_char[word] != ch:
                return False
        else:
            word_to_char[word] = ch
    
    return True


# ✅ Example Tests
print(wordPattern("abba", "dog cat cat dog"))  # True
print(wordPattern("abba", "dog cat cat fish")) # False
print(wordPattern("aaaa", "dog cat cat dog"))  # False
print(wordPattern("abc", "one two one"))       # False
print(wordPattern("abc", "one two three"))     # True
