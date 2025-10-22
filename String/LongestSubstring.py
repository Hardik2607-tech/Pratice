def longestSubstring(s: str, k: int) -> int:
    # Base case: if string is shorter than k, no valid substring possible
    if len(s) < k:
        return 0

    # Count frequency of each character
    freq = {}
    for ch in s:
        freq[ch] = freq.get(ch, 0) + 1

    # Split around characters that occur less than k times
    for ch in freq:
        if freq[ch] < k:
            # Recurse on each part after splitting
            return max(longestSubstring(sub, k) for sub in s.split(ch))
    
    # If all characters occur at least k times, entire string is valid
    return len(s)


# ---- Example Tests ----
print(longestSubstring("aaabb", 3))    # Output: 3
print(longestSubstring("ababbc", 2))   # Output: 5
