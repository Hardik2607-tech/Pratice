def partition(s: str):
    res = []
    path = []

    def is_palindrome(sub: str) -> bool:
        return sub == sub[::-1]

    def backtrack(start: int):
        if start == len(s):
            res.append(path[:])  # Add a copy of the current partition
            return
        for end in range(start + 1, len(s) + 1):
            substr = s[start:end]
            if is_palindrome(substr):
                path.append(substr)
                backtrack(end)
                path.pop()

    backtrack(0)
    return res


# ---- Example Tests ----
print(partition("aab"))   # Output: [["a","a","b"],["aa","b"]]
print(partition("a"))     # Output: [["a"]]
print(partition("abba"))  # Output: [["a","b","b","a"],["a","bb","a"],["abba"]]
