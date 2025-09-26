def lengthOfLongestSubstring(s: str) -> int:
    char_set = set()
    left = 0
    max_len = 0

    for right in range(len(s)):
        while s[right] in char_set:
            char_set.remove(s[left])
            left += 1
        char_set.add(s[right])
        max_len = max(max_len, right - left + 1)
    
    return max_len


# --- Example test cases ---
if __name__ == "__main__":
    print(lengthOfLongestSubstring("abcabcbb"))  # Output: 3 ("abc")
    print(lengthOfLongestSubstring("bbbbb"))    # Output: 1 ("b")
    print(lengthOfLongestSubstring("pwwkew"))   # Output: 3 ("wke")
    print(lengthOfLongestSubstring(""))         # Output: 0 (empty string)
    print(lengthOfLongestSubstring("au"))       # Output: 2 ("au")
