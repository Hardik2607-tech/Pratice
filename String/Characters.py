from collections import Counter

def countCharacters(words, chars):
    chars_count = Counter(chars)
    total_length = 0

    for word in words:
        word_count = Counter(word)
        if all(word_count[ch] <= chars_count[ch] for ch in word_count):
            total_length += len(word)

    return total_length


# Example 1
print(countCharacters(["cat","bt","hat","tree"], "atach"))  # Output: 6

# Example 2
print(countCharacters(["hello","world","leetcode"], "welldonehoneyr"))  # Output: 10
