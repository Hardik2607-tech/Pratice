def findLongestWord(s: str, dictionary: list[str]) -> str:
    def is_subsequence(x):
        i = j = 0
        while i < len(s) and j < len(x):
            if s[i] == x[j]:
                j += 1
            i += 1
        return j == len(x)
    
    best = ""
    for word in dictionary:
        if is_subsequence(word):
            if len(word) > len(best) or (len(word) == len(best) and word < best):
                best = word
    return best


# ----------------------------
# Test Cases
# ----------------------------
s = "abpcplea"
dictionary = ["ale","apple","monkey","plea"]
print(findLongestWord(s, dictionary))  # Expected: "apple"

s = "abpcplea"
dictionary = ["a","b","c"]
print(findLongestWord(s, dictionary))  # Expected: "a"

s = "bab"
dictionary = ["ba","ab","a","b"]
print(findLongestWord(s, dictionary))  # Expected: "ab"

s = "abce"
dictionary = ["abe","abc"]
print(findLongestWord(s, dictionary))  # Expected: "abc"

s = "abc"
dictionary = ["def", "ghi"]
print(findLongestWord(s, dictionary))  # Expected: ""
