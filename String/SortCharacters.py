from collections import Counter

def frequencySort(s: str) -> str:
    # Count frequency of each character
    freq = Counter(s)
    
    # Sort characters by frequency in descending order
    sorted_chars = sorted(freq.keys(), key=lambda x: freq[x], reverse=True)
    
    # Build and return the result string
    return ''.join([char * freq[char] for char in sorted_chars])


# Example usage
print(frequencySort("tree"))    # Output: "eetr" or "eert"
print(frequencySort("cccaaa"))  # Output: "cccaaa" or "aaaccc"
print(frequencySort("Aabb"))    # Output: "bbAa" or "bbaA"
