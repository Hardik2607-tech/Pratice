def mergeAlternately(word1: str, word2: str) -> str:
    res = []
    i, j = 0, 0
    while i < len(word1) and j < len(word2):
        res.append(word1[i])
        res.append(word2[j])
        i += 1
        j += 1
    
    # Append leftovers
    if i < len(word1):
        res.append(word1[i:])
    if j < len(word2):
        res.append(word2[j:])
    
    return "".join(res)


# Example runs
print(mergeAlternately("abc", "pqr"))   # "apbqcr"
print(mergeAlternately("ab", "pqrs"))   # "apbqrs"
print(mergeAlternately("abcd", "pq"))   # "apbqcd"
