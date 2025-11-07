def maxProduct(words):
    n = len(words)
    masks = [0] * n
    lengths = [0] * n

    # Step 1: Create bitmask for each word
    for i, word in enumerate(words):
        mask = 0
        for ch in word:
            mask |= 1 << (ord(ch) - ord('a'))
        masks[i] = mask
        lengths[i] = len(word)

    # Step 2: Compare every pair
    max_product = 0
    for i in range(n):
        for j in range(i + 1, n):
            if masks[i] & masks[j] == 0:  # no common letters
                max_product = max(max_product, lengths[i] * lengths[j])

    return max_product


# Example usage:
words1 = ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
print(maxProduct(words1))  # Output: 16

words2 = ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
print(maxProduct(words2))  # Output: 4

words3 = ["a", "aa", "aaa", "aaaa"]
print(maxProduct(words3))  # Output: 0
