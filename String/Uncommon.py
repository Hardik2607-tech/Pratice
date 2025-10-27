from typing import List

def is_subsequence(a: str, b: str) -> bool:
    """Return True if string a is a subsequence of string b."""
    i = 0
    for c in b:
        if i < len(a) and a[i] == c:
            i += 1
    return i == len(a)

def findLUSlength(strs: List[str]) -> int:
    """Return the length of the longest uncommon subsequence."""
    # Sort by length (descending) so longer strings are checked first
    strs.sort(key=len, reverse=True)

    for i, s in enumerate(strs):
        # Check if s is NOT a subsequence of any other string
        if all(not is_subsequence(s, t) for j, t in enumerate(strs) if i != j):
            return len(s)
    return -1

# Example usage:
print(findLUSlength(["aba", "cdc", "eae"]))  # Output: 3
print(findLUSlength(["aaa", "aaa", "aa"]))   # Output: -1
